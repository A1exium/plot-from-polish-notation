#ifndef SRC_INCLUDE_GRAPH_H_
#define SRC_INCLUDE_GRAPH_H_
void PrintGraph(char** matrix, int max_rows, int max_columns);
char** InitGraph(int max_rows, int max_columns);  //  fill with points
void AddToGraph(char** matrix, int max_rows, int max_columns, int x, double y);

#endif  // SRC_INCLUDE_GRAPH_H_
