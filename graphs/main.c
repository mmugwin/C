#include <stdio.h>
#include "graph.h"

int main() {
    int n_vertices = 5;
    Graph* graph = create_graph(n_vertices);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    display_graph(graph);

    return 0;
}