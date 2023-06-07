#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct{
    int* visited;
    int num_vertices;
    Node** adj_lists;
} Graph;

Node* create_node(int v);
Graph* create_graph(int n_vertices);
void add_edge(Graph* graph, int src, int dest);
void display_graph(Graph* graph);

static inline void dfs(Graph* graph, int source) {
    Node* adj = graph->adj_lists[source];
    Node* tmp = adj;

    graph->visited[source] = 1;
    printf("Visited vertex: %d\n", source);

    while (tmp != NULL) {
        int connected_vertex = tmp->vertex;
        if (graph->visited[connected_vertex] == 0) {
            dfs(graph, connected_vertex);
        }
        tmp = tmp->next;
    }
}

static inline void bfs(Graph* graph, int source) {
    struct Node* q[graph->num_vertices];
    int front = 0;
    int rear = 0;

    graph->visited[source] = 1;
    printf("Visited vertex: %d\n", source);
    q[rear++] = graph->adj_lists[source];

    while (front < rear) {
        Node* adj = q[front++];
        Node* tmp = adj;

        while (tmp != NULL) {
            int connected_vertex = tmp->vertex;
            if(graph->visited[connected_vertex] == 0) {
                printf("Visited vertex: %d\n", connected_vertex);
                q[rear++] = graph->adj_lists[connected_vertex];
                graph->visited[connected_vertex] = 1;
            }
            tmp = tmp->next;
        }
    }
}

#endif