#include <iostream>
#include "graph.hpp"

int main() {
    Graph<double> graph;
    uint_fast64_t n, m, in, out;
    uint_fast64_t a, b;
    std::ifstream file;

    file.open("input3-1.txt");

    if (file.is_open()) {

        file >> n >> m >> in >> out;

        for (int i = 0; i < m; i++) {
            file >> a >> b;
            graph.SetEdges(a, b, 0);
        }
    }
    else std::cout << "input file is not open";

    file.close();

    graph.Shortest_path(in, out, "output3-1.txt");

    return 0;
}
