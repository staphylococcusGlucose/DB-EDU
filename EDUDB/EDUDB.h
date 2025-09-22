#pragma once
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    COL_TYPE_TEXT,
    COL_TYPE_FLOAT
} COL_TYPE;

typedef struct {
    COL_TYPE TYPE;
    const char *COLUMN_NAME;
    bool KEY;     
    bool NOTNULL;
} COLUMN;

typedef struct {
    const char *TABLE_NAME;
    size_t COLUMNS_SIZE;
    COLUMN *COLUMNS;
} TABLE;

typedef struct {
    COL_TYPE MEMORY_TYPE;
    union {
        char *TEXT;
        float FLOAT_VALUE;
    } VALUE;
} DATA;

int init_memory(DATA ***memorys, size_t column_size, size_t row_size);
int define_column(COLUMN **column, const char *column_name, COL_TYPE column_type, bool key, bool not_null);
int create_table(TABLE **table, const char *table_name, COLUMN *columns, size_t columns_size);

int add_data(TABLE *table, DATA *datas);
int get_data(TABLE *table, DATA *key, DATA **dest);
