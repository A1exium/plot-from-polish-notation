#include "../include/graph.h"

char** InitGraph(int max_rows, int max_columns) {
  char** gr = (char**)calloc(max_rows, sizeof(int*));
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
    int rws = round((1 - y) / step);
    for (int i = 0; i < max_rows; i++) {
      for (int j = 0; j < max_columns; j++) {
        if (rws == i && x == j) {
          matrix[i][j] = '*';
        }
      }
    }
  }
}
void MakeGraph(char* str, int max_rows, int max_columns) {
  char** graph = InitGraph(max_rows, max_columns);
  double step = M_PI * 4 / 79;
  double y = 0;
  for (int i = 0; i < max_columns; i++) {
    printf("%lf\n", y);
    AddToGraph(graph, max_rows, max_columns, i, Eval(str, y));
    y += step;
  }
  PrintGraph(graph, max_rows, max_columns);
  FreeMatrix(graph, max_rows);
}

void FreeMatrix(char** matrix, int max_rows) {
  for (int y = 0; y < max_rows; y++) {
    free(matrix[y]);
  }
  free(matrix);
}