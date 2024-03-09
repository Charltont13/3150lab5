#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

using Matrix = std::vector<std::vector<int>>;

class Graph {
private:
    int n; 
    Matrix D1, D0, Dm1;

public:
    explicit Graph(int size); 
    void readMatrixFromFile(const std::string& filename, int matrixType);
    void expensiveDigraphExactPaths();
    void initAdjacencyMatrices();
    const Matrix& getD1() const { return D1; }
    const Matrix& getD0() const { return D0; } // Ensure this getter is defined
    const Matrix& getDm1() const { return Dm1; }
};

#endif // MATRIX_H
