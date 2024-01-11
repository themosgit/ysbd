#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bf.h"
#include "hp_file.h"
#include "record.h"
#include "sort.h"
#include "merge.h"
#include "chunk.h"

bool shouldSwap(Record *rec1, Record *rec2) {
    int nameComparison = strcmp(rec1->name, rec2->name);

    if (nameComparison > 0) {
        // rec1's name comes before rec2's name
        return true;
    } else if (nameComparison == 0) {
        // Names are equal, compare surnames
        int surnameComparison = strcmp(rec1->surname, rec2->surname);

        if (surnameComparison > 0) {
            // rec1's surname comes before rec2's surname
            return true;
        }
    }

    // No need to swap
    return false;
}

void sort_FileInChunks(int file_desc, int numBlocksInChunk) {
    CHUNK_Iterator chit = CHUNK_CreateIterator(file_desc, numBlocksInChunk);
    CHUNK *chunk = malloc(sizeof(CHUNK));

    while (CHUNK_GetNext(&chit, chunk)) {
        sort_Chunk(chunk);
        for(int i=chunk->from_BlockId;i<=chunk->to_BlockId;i++){
            HP_Unpin(file_desc,i);
        }
    }
    free(chunk);
}


void sort_Chunk(CHUNK *chunk) {
    Record *Record1,*Record2;
    Record1=malloc(sizeof(Record));
    Record2=malloc(sizeof(Record));
    for (int i = 1; i <= chunk->recordsInChunk ; i++) {
        for (int j = 1; j < chunk->recordsInChunk  - i+1; j++) {
            CHUNK_GetIthRecordInChunk(chunk, j, Record1);
            CHUNK_GetIthRecordInChunk(chunk,j+1, Record2);
            if(shouldSwap(Record1, Record2)){
                CHUNK_UpdateIthRecord(chunk,j,*Record2);
                CHUNK_UpdateIthRecord(chunk,j+1,*Record1);
            }
        }
    }
    free(Record1);
    free(Record2);
}


