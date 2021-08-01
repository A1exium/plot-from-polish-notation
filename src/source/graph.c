#include "../include/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char** InitGraph(int max_rows, int max_columns) {
    char ** gr = (char**)calloc(max_rows, sizeof(int*));
    for (int i = 0; i < max_rows; i++) {
        gr[i] = (char*)calloc(max_columns, sizeof(int));
    }
    for (int i = 0; i < max_rows; i++) {
            for (int j = 0; j < max_columns; j++) {
                gr[i][j] = '.';
            }
    }
    return gr;
}

void PrintGraph(char** matrix, int max_rows, int max_columns) {
        printf("\033[2J\033[1;1H");
        for (int i = 0; i < max_rows; i++) {
            for (int j = 0; j < max_columns; j++) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    for (int i = 0; i < max_rows; i++) {
        free(matrix[i]);
    }
     free(matrix);
}
void AddToGraph(char** matrix, int max_rows, int max_columns, int x, double y) {
    double step = 0.0833;
    if (y <= 1 && y >= -1) {
    int rws = round((1-y)/step);
    for (int i = 0; i < max_rows; i++) {
            for (int j = 0; j < max_columns; j++) {
                if (rws == i && x == j) {
                    matrix[i][j] = '*';
                }
            }
        }
    }
}
