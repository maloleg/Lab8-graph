//#include <iostream>
#include "graph.hpp"


int main() {
    Graph<double> graph;
    uint_fast64_t n, m;
    uint_fast64_t a, b;
    double w;
    std::ifstream file;

    file.open("input.txt");

    if (file.is_open()) {

        file >> n >> m;

        for (uint_fast64_t i = 0; i < m; i++) {
            file >> a >> b >> w;
            graph.SetEdges(a, b, w, 0);
        }
    }
    else std::cout << "input file is not open";

    //file >> in >> out;


    file.close();

    //graph.Adjacency_matrix_print("Directed.txt", n);

    //graph.Double_directions();

    //graph.Adjacency_matrix_print("UnDirected.txt", n);

    //graph.Dijkstra_Shortest_path(in, out, "output4-2.txt", 1, n, 4);
    //std::cout << graph.Is_connected(in, out);

    if (graph.Is_connected(-1) == n){
        graph.Prims_Algorithm("output.txt");
    }
    else{
        std::ofstream file;
        file.open("output.txt");
        file << 0;
        file.close();
    }
    return 0;
}
//
// Created by oleg on 10.05.2020.
//

