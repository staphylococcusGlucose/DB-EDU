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
}DATA;

int init_memory(DATA ***memorys, unsigned int column_size, unsigned int row_size);
int define_column(COLUMN **column, char *column_name, COL_TYPE column_type, int key, int not_null);
int create_table(TABLE **table, char *table_name, COLUMN*columns, unsigned int columns_size);

int add_daa(TABLE *table, COLUMN *datas);
int get_data(TABLE *table, DATA *key, DATA **dest);