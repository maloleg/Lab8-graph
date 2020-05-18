//#include <iostream>
#include "graph.hpp"


int main() {
    Graph<double> graph;
    uint_fast64_t n, m, in, out;
    uint_fast64_t a, b;
    double w;
    std::ifstream file;

    file.open("input.txt");

    if (file.is_open()) {

        file >> n >> m >> in >> out;

        for (uint_fast64_t i = 0; i < m; i++) {
            file >> a >> b >> w;
            graph.SetEdges(a, b, w, 1);
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

    if (graph.Is_connected(in, out)) graph.Dijkstra_Shortest_path(in, out, "output.txt", 1, n, 4);
    else{
        std::ofstream file;
        file.open("output.txt");
        file << -1;
        file.close();
    }
//Прямо скажем, костыль тот ещё. Почему-то, если вызывать Is_connected в методе класса - он работает неправильно:(
    return 0;
}
//
// Created by oleg on 10.05.2020.
//

