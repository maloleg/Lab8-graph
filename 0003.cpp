#include <iostream>
#include "graph.hpp"

int main() {
    Graph<double> graph;
    uint_fast64_t n, m, in, out;
    uint_fast64_t a, b;
    std::ifstream file;

    file.open("input3.txt");

    if (file.is_open()) {

        file >> n >> m >> in >> out;

        for (int i = 0; i < m; i++) {
            file >> a >> b;
            graph.SetEdges(a, b, 1);
        }
    }
    else std::cout << "input file is not open";

    file.close();

    graph.Adjacency_matrix_print("output.txt", n);

    return 0;
}
