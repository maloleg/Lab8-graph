#include <iostream>
#include "graph.hpp"

int main() {
    Graph<double> graph;
    uint_fast64_t n, m = 0;
    uint_fast64_t a, b = 0;
    std::ifstream file;

    file.open("input.txt");

    if (file.is_open()) {

        file >> n >> m;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 2; j++) {
                file >> a >> b;
                graph.SetEdges(a, b, 0);
            }
        }
    }
    else std::cout << "input file is not open";

    file.close();

    graph.Adjacency_matrix_print("output.txt");



    return 0;
}
