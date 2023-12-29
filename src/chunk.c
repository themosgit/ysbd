#include <merge.h>
#include <stdio.h>
#include "chunk.h"
#include "bf.h"
#include "hp_file.h"
#include "record.h"

CHUNK_Iterator CHUNK_CreateIterator(int fileDesc, int blocksInChunk){

    HP_info *blinfo;
    CHUNK_Iterator info;
    BF_Block *block;

    info.file_desc = fileDesc;
    info.current = 1;
    info.blocksInChunk = blocksInChunk;
    
    BF_Block_Init(&block);
    BF_GetBlock(fileDesc,0,block);
    blinfo = BF_Block_GetData(block);

    info.lastBlocksID = blinfo->lastBlockId;
    BF_UnpinBlock(block);

    return info;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CHUNK_GetNext(CHUNK_Iterator *iterator,CHUNK* chunk){        //προετοιμαζουμε για να παρουμε το επομενο chunk

    HP_info *blinfo;
    BF_Block *block;
    BF_Block_Init(&block);
    BF_GetBlock(chunk->file_desc,0,block);
    blinfo = BF_Block_GetData(block);

    
    if (iterator->current==blinfo->lastBlockId){
         BF_UnpinBlock(block);
        return 0;
    }

    chunk->file_desc = iterator->file_desc;
    chunk->from_BlockId = iterator->current;                    
    if (iterator->current + iterator->blocksInChunk - 1 > blinfo->lastBlockId ) {
        chunk->to_BlockId = blinfo->lastBlockId;
        chunk->blocksInChunk = blinfo->lastBlockId - chunk->from_BlockId + 1;
        chunk->recordsInChunk = blinfo->totalRecords - (iterator->current - 1) * blinfo->blockCapacity;
        iterator->current = blinfo->lastBlockId;
    }
    else {
        chunk->to_BlockId = iterator->current + iterator->blocksInChunk - 1;
        chunk->blocksInChunk = iterator->blocksInChunk;
        chunk->recordsInChunk = blinfo->blockCapacity * chunk->blocksInChunk;
        iterator->current += iterator->blocksInChunk;
    }
     BF_UnpinBlock(block);
    
    return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CHUNK_RecordIterator CHUNK_CreateRecordIterator(CHUNK *chunk){

    CHUNK_RecordIterator rec;

    rec.chunk = *chunk;
    rec.currentBlockId = chunk->from_BlockId;
    rec.cursor = 0;

    return rec;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CHUNK_GetIthRecordInChunk(CHUNK* chunk,  int i, Record* record){

    CHUNK_RecordIterator iterator = CHUNK_CreateRecordIterator(chunk);
    
    record->id=-1;
    
    for(int j = 0; j < i - 1; j++){
        CHUNK_GetNextRecord(&iterator, record);
    }

    record->id=0;

    if (CHUNK_GetNextRecord(&iterator, record) == 1) return 0;
    else return -1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CHUNK_UpdateIthRecord(CHUNK* chunk,  int i, Record record){
    CHUNK_RecordIterator iterator = CHUNK_CreateRecordIterator(chunk);
    int check;

    record.id=-1;

    for(int j = 0; j < i; j++){
       if (j==i-1) record.id=0;
       check = CHUNK_GetNextRecord(&iterator, NULL);
       if (check != 1) return -1;
    }

    BF_Block *block;
    Record *rec;
    BF_Block_Init(&block);

    BF_GetBlock(chunk->file_desc, iterator.currentBlockId, block);

    rec = BF_Block_GetData(block);
    memcpy(&rec[iterator.cursor], &record, sizeof(Record));
    BF_SetDirty(block);
    BF_UnpinBlock(block);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CHUNK_Print(CHUNK chunk){
    CHUNK_RecordIterator iterator = CHUNK_CreateRecordIterator(&chunk);
    Record rec;
    int check = CHUNK_GetNextRecord(&iterator, &rec);
    while(check == 1){
        printRecord(rec);
        check = CHUNK_GetNextRecord(&iterator, &rec);
    }
    return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int CHUNK_GetNextRecord(CHUNK_RecordIterator *iterator,Record* record){

    if(iterator->chunk.to_BlockId < iterator->currentBlockId){
        return 0;
    }

    BF_Block *block;
    HP_info *info;
    BF_Block_Init(&block); 

    if (record->id != -1) {
        BF_GetBlock(iterator->chunk.file_desc, iterator->currentBlockId, block); 
    
        Record *rec;
        rec = BF_Block_GetData(block);
        record = &rec[iterator->cursor];
        BF_UnpinBlock(block);
    }
    BF_GetBlock(iterator->chunk.file_desc, 0, block);
    info = BF_Block_GetData(block);

    if(iterator->currentBlockId == info->lastBlockId && 
        iterator->cursor >= info->totalRecords - (iterator->currentBlockId - 1) * info->blockCapacity) {
        iterator->currentBlockId++;//
        BF_UnpinBlock(block);
        return 1;
    }


    if(iterator->cursor >= info->blockCapacity){
        iterator->cursor = 0;
        iterator->currentBlockId++;
    }else{
        iterator->cursor++;
    }
    BF_UnpinBlock(block);

    return 1;
}
