#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define MAX_TERMS 20

typedef struct {
    int row;
    int col;
    int value;
} Term;

Term sparse[MAX_TERMS];
Term transposed[MAX_TERMS];

int matrix[ROWS][COLS];

int move_count = 0;

void init_sparse() {
    int i, j;

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            matrix[i][j] = 0;

    int data[MAX_TERMS][3] = {
        {0,1,1},{0,5,2},{1,2,3},{1,7,4},{2,0,5},
        {2,4,6},{3,3,7},{3,8,8},{4,1,9},{4,6,10},
        {5,2,11},{5,9,12},{6,0,13},{6,5,14},{7,3,15},
        {7,7,16},{8,1,17},{8,8,18},{9,4,19},{9,9,20}
    };

    for (i = 0; i < MAX_TERMS; i++) {
        sparse[i].row   = data[i][0];
        sparse[i].col   = data[i][1];
        sparse[i].value = data[i][2];
        matrix[data[i][0]][data[i][1]] = data[i][2];
    }
}

void print_matrix() {
    int i, j;
    printf("\n===== 원본 10x10 행렬 =====\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf("%3d", matrix[i][j]);
        printf("\n");
    }
}

void print_sparse(Term *list, int size, char *title) {
    int i;
    printf("\n===== %s 희소행렬 순차리스트 =====\n", title);
    printf("index\t행\t열\t값\n");
    printf("--------------------------------\n");
    for (i = 0; i < size; i++)
        printf("[%2d]\t%d\t%d\t%d\n", i, list[i].row, list[i].col, list[i].value);
}

void transpose() {
    int i, j, k;
    k = 0;
    move_count = 0;

    for (i = 0; i < COLS; i++) {
        for (j = 0; j < MAX_TERMS; j++) {
            if (sparse[j].col == i) {
                transposed[k].row   = sparse[j].col;   
                transposed[k].col   = sparse[j].row;
                transposed[k].value = sparse[j].value;
                k++;
                move_count++;  
            }
        }
    }
}

void print_transposed_matrix() {
    int i, j;
    int trans_matrix[ROWS][COLS];

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            trans_matrix[i][j] = 0;

    for (i = 0; i < MAX_TERMS; i++)
        trans_matrix[transposed[i].row][transposed[i].col] = transposed[i].value;

    printf("\n===== 전치 10x10 행렬 =====\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf("%3d", trans_matrix[i][j]);
        printf("\n");
    }
}

int main() {

    init_sparse();

    print_matrix();
    print_sparse(sparse, MAX_TERMS, "원본");

    transpose();

    print_transposed_matrix();
    print_sparse(transposed, MAX_TERMS, "전치");

    printf("\n데이터 이동 횟수: %d회\n", move_count);

    return 0;
}