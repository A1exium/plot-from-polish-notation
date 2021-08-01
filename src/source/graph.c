#include "../include/graph.h"
#include <stdio.h>
#include <stdlib.h>

void PrintGraph(char** matrix, int max_rows, int max_columns);
char** InitGraph(int max_rows, int max_columns);  //  fill with points
void AddToGraph(char** matrix, long long value, int measurement_number);

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
                                                            
