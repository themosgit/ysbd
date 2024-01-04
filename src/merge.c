#include <merge.h>
#include <stdio.h>
#include <stdbool.h>

void merge(int input_FileDesc, int chunkSize, int bWay, int output_FileDesc ){
    int pointertominrec;
    bool yparxounRecs;
    CHUNK ** chunks=malloc(sizeof(CHUNK*)*bWay);
    CHUNK_RecordIterator *rec_it=malloc(sizeof(CHUNK_RecordIterator) * bWay);
    CHUNK_Iterator chunk_it=CHUNK_CreateIterator(input_FileDesc, chunkSize);
    Record **next_recs=malloc(sizeof(Record*) * bWay);
    for(int i=0;i<bWay;i++){
        chunks[i]=malloc(sizeof(CHUNK));
        next_recs[i]=malloc(sizeof(Record));
        if(!CHUNK_GetNext(&chunk_it, chunks[i])) {
            next_recs[i]=NULL;
            continue;
        }
        rec_it[i]=CHUNK_CreateRecordIterator(chunks[i]);
        CHUNK_GetNextRecord(&rec_it[i], next_recs[i]);
    }
    while(true){
        while(true){
            yparxounRecs=false;
            for(int i=0;i<bWay;i++){
                yparxounRecs= yparxounRecs || next_recs[i] != NULL;
            }
            if(!yparxounRecs) break;
            pointertominrec=-1;
            for(int i=0;i<bWay;i++){
                if(next_recs[i] != NULL){
                    if(pointertominrec==-1 || shouldSwap(next_recs[pointertominrec], next_recs[i])){
                        pointertominrec=i;
                    }
                }
            }
            HP_InsertEntry(output_FileDesc,*next_recs[pointertominrec]);
            HP_Unpin(output_FileDesc,HP_GetIdOfLastBlock(output_FileDesc));
            int a=rec_it[pointertominrec].currentBlockId;
            if(!CHUNK_GetNextRecord(&rec_it[pointertominrec], next_recs[pointertominrec])){
                next_recs[pointertominrec]=NULL;
            }
            int b=rec_it[pointertominrec].currentBlockId;
            if(b!=a){
                HP_Unpin(input_FileDesc,a);
            }
        }
        yparxounRecs=false;
        for(int i=0;i<bWay;i++){
            for(int j=chunks[i]->from_BlockId;j<=chunks[i]->to_BlockId;j++){
                HP_Unpin(input_FileDesc,j);
            }
            if(!CHUNK_GetNext(&chunk_it, chunks[i])) {
                next_recs[i]=NULL;
                continue;
            }
            rec_it[i]=CHUNK_CreateRecordIterator(chunks[i]);
            next_recs[i]=malloc(sizeof(Record));
            if(CHUNK_GetNextRecord(&rec_it[i], next_recs[i])){
                yparxounRecs=true;
            }
        }
        if(!yparxounRecs) break;
    }
}
