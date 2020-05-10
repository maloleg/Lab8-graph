#include <iostream>
#include "graph.hpp"

int main() {
    Graph<double> graph;
    uint_fast64_t n, m, in, out;
    uint_fast64_t a, b;
    double w;
    std::ifstream file;

    file.open("input4-1.txt");

    if (file.is_open()) {

        file >> n >> m >> in >> out;

        for (int i = 0; i < m; i++) {
            file >> a >> b >> w;
            graph.SetEdges(a, b, w, 0);
        }
    }
    else std::cout << "input file is not open";


    file.close();

    //graph.Adjacency_matrix_print("Directed.txt", n);

    //graph.Double_directions();

    //graph.Adjacency_matrix_print("UnDirected.txt", n);

    graph.Dijkstra_Shortest_path(in, out, "output4-1.txt");

    return 0;
}
//
// Created by oleg on 10.05.2020.
//

