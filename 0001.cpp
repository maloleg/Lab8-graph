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

        for (uint_fast64_t i = 0; i < m; i++) {
            file >> a >> b;
            graph.SetEdges(a, b, 0);
        }
        file.close();
    }
    else std::cout << "input file is not open";



    graph.Adjacency_matrix_print("output.txt", n, 0);

    return 0;
}
