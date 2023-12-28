#include <merge.h>
#include <stdio.h>
#include "chunk.h"


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
        return 0;
    }

    chunk->file_desc = iterator->file_desc;
    chunk->from_BlockId = iterator->current;                    //ξεκιναμε απο το τρεχον μπλοκ, δεν θα πρεπε να παρει το lastblockid ωστε να ξεκινησει απο το επομενο???
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
    
    return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CHUNK_GetIthRecordInChunk(CHUNK* chunk,  int i, Record* record){

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CHUNK_UpdateIthRecord(CHUNK* chunk,  int i, Record record){

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CHUNK_Print(CHUNK chunk){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CHUNK_RecordIterator CHUNK_CreateRecordIterator(CHUNK *chunk){

    CHUNK_RecordIterator rec;

    rec.chunk = *chunk;
    rec.currentBlockId = chunk->from_BlockId;
    rec.cursor = 0;

    return rec;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CHUNK_GetNextRecord(CHUNK_RecordIterator *iterator,Record* record){
    BF_Block *block;

    BF_GetBlock(iterator->chunk.file_desc,iterator->currentBlockId,block); //δεν θα επρεπε να παιρνει blocksinchunk??
    
    Record *rec;

    rec=BF_Block_GetData(block);
    record=&rec[iterator->cursor];

    if(iterator->chunk.blocksInChunk < iterator->currentBlockId){
        return 0;
    }

    if(iterator->cursor >= iterator->chunk.recordsInChunk){
        iterator->cursor=0;
        iterator->currentBlockId++;
    }else{
        iterator->cursor++;
    }

    return 1;
}
