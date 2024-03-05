#include "Matrix.h"
#include <iostream>

int main() {
    Graph g(4);
    
    try {
        g.initAdjacencyMatrices(); // Initialize the graph with predefined values or a file

        // Read matrices from files
        g.readMatrixFromFile("D1.txt", 1);
        g.readMatrixFromFile("D0.txt", 0);
        g.readMatrixFromFile("Dm1.txt", -1);

        // Run the algorithm
        g.expensiveDigraphExactPaths();


    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
