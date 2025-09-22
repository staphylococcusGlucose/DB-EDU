#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "table.h"   // 방금 만든 헤더 (typedef, 함수 선언 들어있는 파일)


// 메모리 초기화
int init_memory(DATA ***memorys, size_t column_size, size_t row_size) {
    *memorys = (DATA**)malloc(sizeof(DATA*) * row_size);
    if (!*memorys) return -1;

    for (size_t i = 0; i < row_size; i++) {
        (*memorys)[i] = (DATA*)malloc(sizeof(DATA) * column_size);
        if (!(*memorys)[i]) return -1;
    }
    return 0;
}

// 컬럼 정의
int define_column(COLUMN **column, const char *column_name, COL_TYPE column_type, bool key, bool not_null) {
    *column = (COLUMN*)malloc(sizeof(COLUMN));
    if (!*column) return -1;

    (*column)->COLUMN_NAME = strdup(column_name);
    (*column)->TYPE = column_type;
    (*column)->KEY = key;
    (*column)->NOTNULL = not_null;

    return 0;
}

// 테이블 생성
int create_table(TABLE **table, const char *table_name, COLUMN *columns, size_t columns_size) {
    *table = (TABLE*)malloc(sizeof(TABLE));
    if (!*table) return -1;

    (*table)->TABLE_NAME = strdup(table_name);
    (*table)->COLUMNS = columns;
    (*table)->COLUMNS_SIZE = columns_size;

    return 0;
}

// 데이터 추가 (아주 단순 버전: 첫 번째 row에만 넣는다)
int add_data(TABLE *table, DATA *datas) {
    printf("Insert into table: %s\n", table->TABLE_NAME);
    for (size_t i = 0; i < table->COLUMNS_SIZE; i++) {
        if (datas[i].MEMORY_TYPE == COL_TYPE_TEXT) {
            printf("  %s = %s\n", table->COLUMNS[i].COLUMN_NAME, datas[i].VALUE.TEXT);
        } else if (datas[i].MEMORY_TYPE == COL_TYPE_FLOAT) {
            printf("  %s = %f\n", table->COLUMNS[i].COLUMN_NAME, datas[i].VALUE.FLOAT_VALUE);
        }
    }
    return 0;
}

// 샘플 실행
int main() {
    // 1. 컬럼 정의
    COLUMN *columns = (COLUMN*)malloc(sizeof(COLUMN) * 2);

    define_column(&columns[0], "id", COL_TYPE_FLOAT, true, true);
    define_column(&columns[1], "name", COL_TYPE_TEXT, false, true);

    // 2. 테이블 생성
    TABLE *table = NULL;
    create_table(&table, "users", columns, 2);

    // 3. 데이터 준비
    DATA row[2];
    row[0].MEMORY_TYPE = COL_TYPE_FLOAT;
    row[0].VALUE.FLOAT_VALUE = 1.0f;

    row[1].MEMORY_TYPE = COL_TYPE_TEXT;
    row[1].VALUE.TEXT = strdup("Alice");

    // 4. 데이터 추가
    add_data(table, row);

    // 5. 다른 데이터도 추가 가능
    row[0].VALUE.FLOAT_VALUE = 2.0f;
    row[1].VALUE.TEXT = strdup("Bob");
    add_data(table, row);

    return 0;
}
