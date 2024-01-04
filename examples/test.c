#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge.h"
#include "chunk.h"

#define RECORDS_NUM 91// you can change it if you want
#define FILE_NAME "test.db"
#define OUT_NAME "out"

void printChunkIterator(CHUNK_Iterator *chunkIterator);
int createAndPopulateHeapFile(char* filename);
void findblockandrecord(int);

void printRecordIterator(CHUNK_RecordIterator *pIterator);

int main(){

    BF_Init(LRU);

    remove(FILE_NAME);
    remove("test2.db");
    int filedesc = createAndPopulateHeapFile(FILE_NAME);
    CHUNK *chunk = malloc(sizeof(CHUNK));
    CHUNK_Iterator iterator=CHUNK_CreateIterator(filedesc,5);


    printChunkIterator(&iterator);
    printf("recsInBlocks:%d\n================\n",HP_GetMaxRecordsInBlock(filedesc));


    while(CHUNK_GetNext(&iterator,chunk)){
        CHUNK_Print(*chunk);
        for(int i=chunk->from_BlockId;i<chunk->to_BlockId+1;i++){
            HP_Unpin(filedesc,i);
        }
        //prepei na kanoume unpin kai se alla shmeia
    }
    printf("------before last chunk Record Iterator ---------\n");
    CHUNK_RecordIterator rit=CHUNK_CreateRecordIterator(chunk);
    printRecordIterator(&rit);
    Record *rec=malloc(sizeof(Record));
    while(CHUNK_GetNextRecord(&rit,rec) && strcmp(rec->surname,"")!=0){
        printRecord(*rec);
    }
    printf("------after last chunk Record Iterator ---------\n");
    printf("------before ithRecordInChunk---------\n");
    if(CHUNK_GetIthRecordInChunk(chunk,RECORDS_NUM%(HP_GetMaxRecordsInBlock(filedesc)*5),rec))
    printRecord(*rec);
    printf("------after ithRecordInChunk ---------\n");
    printf("------before sort---------\n");


    iterator=CHUNK_CreateIterator(filedesc,5);
    while(CHUNK_GetNext(&iterator,chunk)){
        sort_Chunk(chunk);
        for(int i=chunk->from_BlockId;i<chunk->to_BlockId+1;i++){
            HP_Unpin(filedesc,i);
        }
    }

    printf("------after sort---------\n");
    iterator=CHUNK_CreateIterator(filedesc,5);
    while(CHUNK_GetNext(&iterator,chunk)){
        CHUNK_Print(*chunk);
        for(int j=chunk->from_BlockId;j<=chunk->to_BlockId;j++){
            HP_Unpin(filedesc,j);
        }
    }
    printf("------before merge---------\n");

    int filed;
    HP_CreateFile("test2.db");
    HP_OpenFile("test2.db", &filed);
    merge(filedesc,5,2,filed);
    printf("------after merge---------\n");




    free(rec);

    HP_CloseFile(filedesc);
    HP_CloseFile(filed);
    free(chunk);

    return 0;
}

void printRecordIterator(CHUNK_RecordIterator *pIterator) {
    printf("currentBlock:%d\ncursor:%d\n================\n",pIterator->currentBlockId,pIterator->cursor);

}

void printChunkIterator(CHUNK_Iterator *chunkIterator){
    printf("blocksInChunk:%d\nlastBlockId:%d\nfileDesc:%d\ncurrent:%d\n================\n",chunkIterator->blocksInChunk,chunkIterator->lastBlocksID,chunkIterator->file_desc,chunkIterator->current);

}

int createAndPopulateHeapFile(char* filename){
    HP_CreateFile(filename);

    int file_desc;
    HP_OpenFile(filename, &file_desc);

    Record record;
    srand(12569874);
    for (int id = 0; id < RECORDS_NUM; ++id)
    {
        record = randomRecord();
        HP_InsertEntry(file_desc, record);
        HP_CloseFile(file_desc);
        HP_OpenFile(filename, &file_desc);

    }


    return file_desc;
}
void findblockandrecord(int i){

}