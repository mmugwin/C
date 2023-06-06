#ifndef GRAPH_H
#define GRAPH_H

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct{
    int num_vertices;
    Node** adj_lists;
} Graph;

Node* create_node(int v);
Graph* create_graph(int n_vertices);
void add_edge(Graph* graph, int src, int dest);
void display_graph(Graph* graph);

#endif