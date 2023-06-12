#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Node* create_node(int v){
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

Graph* create_graph(int n_vertices){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = n_vertices;
    graph->adj_lists = (Node**)malloc(n_vertices * sizeof(Node*));
    graph->visited = (int*)malloc(n_vertices * sizeof(int));
    
    for (int i = 0; i < n_vertices; i++) {
        graph->adj_lists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void add_edge(Graph* graph, int src, int dest){
    Node* node = create_node(dest);
    node->next = graph->adj_lists[src];
    graph->adj_lists[src] = node;

    node = create_node(src);
    node->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = node;
}

void display_graph(Graph* graph){
    for (int v = 0; v < graph->num_vertices; v++) {
        Node* tmp = graph->adj_lists[v];
        printf("Adjacency list of vertex %d:\n", v);
        while (tmp) {
            printf("%d ->", tmp->vertex);
            tmp = tmp->next;
        }
        printf("NULL\n");
    }
}