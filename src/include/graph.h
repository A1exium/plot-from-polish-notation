#ifndef SRC_INCLUDE_GRAPH_H_
#define SRC_INCLUDE_GRAPH_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "parse.h"
void PrintGraph(char** matrix, int max_rows, int max_columns);
char** InitGraph(int max_rows, int max_columns);  //  fill with points
void AddToGraph(char** matrix, int max_rows, int max_columns, int x, double y);
void MakeGraph(char* str, int max_rows, int max_columns);
void FreeMatrix(char** matrix, int max_rows);
#endif  // SRC_INCLUDE_GRAPH_H_
