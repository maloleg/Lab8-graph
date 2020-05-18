#include <iostream>
#include "graph.hpp"

int main() {
    Graph<double> graph;
    uint_fast64_t n = 0;
    uint_fast64_t a, b = 0;
    std::ifstream file;

    file.open("input.txt");

    if (file.is_open()) {

        file >> n;

        for (uint_fast64_t i = 0; i < n; i++) {
            file >> a >> b;
            graph.SetEdges(a, b, 0);
        }
    }
    else std::cout << "input file is not open";

    file.close();

    graph.Vertexes_degree("output.txt");

    return 0;
}
