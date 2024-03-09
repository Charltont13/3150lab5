#include "Matrix.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <stdexcept>

void testMatrixReadAndOperations() {
    // Initialize the Graph with 2 vertices for a simple test
    Graph g(2);
    g.initAdjacencyMatrices();

    // Read matrices from test files
    // (Make sure to have testD1.txt, testD0.txt, testDm1.txt files with proper test matrices)
    g.readMatrixFromFile("testD1.txt", 1);
    g.readMatrixFromFile("testD0.txt", 0);
    g.readMatrixFromFile("testDm1.txt", -1);

    
    g.expensiveDigraphExactPaths();

    // Perform tests on the result
    const Matrix& D0_result = g.getD0();
    assert(D0_result[0][0] == 0);
    assert(D0_result[0][1] == 0); 
    assert(D0_result[1][0] == 0); 
    assert(D0_result[1][1] == 0);

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    try {
        testMatrixReadAndOperations();
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
