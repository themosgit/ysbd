#include <merge.h>
#include <stdio.h>
#include <string.h>
#include "chunk.h"
#include "bf.h"
#include "hp_file.h"
#include "record.h"

CHUNK_Iterator CHUNK_CreateIterator(int fileDesc, int blocksInChunk) {
    CHUNK_Iterator info;
    info.file_desc = fileDesc;
    info.current = 1;
    info.blocksInChunk = blocksInChunk;
    info.lastBlocksID = HP_GetIdOfLastBlock(fileDesc);
    return info;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CHUNK_GetNext(CHUNK_Iterator *iterator, CHUNK *chunk) {        //προετοιμαζουμε για να παρουμε το επομενο chunk
    int lastblockid = HP_GetIdOfLastBlock(iterator->file_desc);
    int maxrecordsinblock = HP_GetMaxRecordsInBlock(iterator->file_desc);
    if (iterator->current > lastblockid) {
        return 0;
    }
    chunk->file_desc = iterator->file_desc;
    chunk->from_BlockId = iterator->current;
    if (iterator->current + iterator->blocksInChunk - 1 > lastblockid) {
        chunk->to_BlockId = lastblockid;
        chunk->blocksInChunk = lastblockid - iterator->current + 1;
        chunk->recordsInChunk = maxrecordsinblock * (lastblockid - iterator->current) +
                                HP_GetRecordCounter(iterator->file_desc, lastblockid);
        iterator->current = lastblockid + 1;
    } else {
        chunk->to_BlockId = iterator->current + iterator->blocksInChunk - 1;
        chunk->blocksInChunk = iterator->blocksInChunk;
        chunk->recordsInChunk = maxrecordsinblock * iterator->blocksInChunk;
        iterator->current += iterator->blocksInChunk;
    }
    return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CHUNK_RecordIterator CHUNK_CreateRecordIterator(CHUNK *chunk) {
    CHUNK_RecordIterator rec;
    rec.chunk = *chunk;
    rec.currentBlockId = chunk->from_BlockId;
    rec.cursor = 0;
    return rec;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CHUNK_GetIthRecordInChunk(CHUNK *chunk, int i, Record *record) {
    if (!i) return 0;
    int bloc, reco;
    bloc = (i - 1) / HP_GetMaxRecordsInBlock(chunk->file_desc) + chunk->from_BlockId;
    reco = (i - 1) % HP_GetMaxRecordsInBlock(chunk->file_desc);
    HP_GetRecord(chunk->file_desc, bloc, reco, record);
    return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CHUNK_UpdateIthRecord(CHUNK *chunk, int i, Record record) {
    if (!i) return 0;
    int bloc, reco;
    bloc = (i - 1) / HP_GetMaxRecordsInBlock(chunk->file_desc) + chunk->from_BlockId;
    reco = (i - 1) % HP_GetMaxRecordsInBlock(chunk->file_desc);
    HP_UpdateRecord(chunk->file_desc, bloc, reco, record);
    HP_Unpin(chunk->file_desc, bloc);
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CHUNK_Print(CHUNK chunk) {
    CHUNK_RecordIterator iterator = CHUNK_CreateRecordIterator(&chunk);
    Record rec;
    int check = CHUNK_GetNextRecord(&iterator, &rec);
    while (check == 1) {
        if (strcmp(rec.name, "") != 0) {
            printRecord(rec);
        } else {
            printf("-------------------\n");
        }
        check = CHUNK_GetNextRecord(&iterator, &rec);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CHUNK_GetNextRecord(CHUNK_RecordIterator *iterator, Record *record) {
    int rec = iterator->cursor;
    int bloc = iterator->currentBlockId;
    if (iterator->chunk.to_BlockId < iterator->currentBlockId) {
        return 0;
    }
    if (iterator->cursor == HP_GetRecordCounter(iterator->chunk.file_desc, iterator->currentBlockId)) {
        return 0;
    }
    HP_GetRecord(iterator->chunk.file_desc, bloc, rec, record);
    iterator->cursor++;
    if (iterator->cursor == HP_GetMaxRecordsInBlock(iterator->chunk.file_desc)) {
        iterator->cursor = 0;
        iterator->currentBlockId++;
    }
    return 1;
}