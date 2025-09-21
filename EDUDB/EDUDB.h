#pragma once


typedef enum _COL_TYPE_ {
    TEXT,
    FLOAT
}COL_TYPE;

typedef struct  {
    COL_TYPE TYPE;
    char *COLUMN_NAME;
    int KEY;   //key : 1, not key : 0
    int NOTNULL; //allow null : 0, not allow null : 1
}COLUMN;

typedef struct  {
    char *TABLE_NAME;
    unsigned int COLUMNS_SIZE;
    COLUMN *COLUMNS;
}TABLE;

typedef struct  {
    COL_TYPE MEMORY_TYPE;
    void *DATA;
}MEMORY;

int init_memory();
int create_table();

int add_daa();
int get_data();