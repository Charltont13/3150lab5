#include "Matrix.h"
#include <fstream>
#include <stdexcept>
#include <limits>



Graph::Graph(int size) : n(size), D1(size, std::vector<int>(size, std::numeric_limits<int>::max())),
                         D0(size, std::vector<int>(size, 0)), Dm1(size, std::vector<int>(size, std::numeric_limits<int>::max())) {

}
void Graph::readMatrixFromFile(const std::string& filename, int matrixType) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    
    Matrix* matrixPtr;
    switch (matrixType) {
        case 1: matrixPtr = &D1; break;
        case 0: matrixPtr = &D0; break;
        case -1: matrixPtr = &Dm1; break;
        default: throw std::invalid_argument("Invalid matrix type");
    }

    Matrix& matrix = *matrixPtr;
    for (auto& row : matrix) {
        for (int& val : row) {
            file >> val;
        }
    }

    file.close();
}

void Graph::expensiveDigraphExactPaths() {
    int n = D0.size();
    for (int ell = 2; ell <= 3 * n * n + 1; ++ell) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (Dm1[i][k] + D1[k][j] == 0 || D1[i][k] + Dm1[k][j] == 0) D0[i][j] = 0;
                    if (D1[i][k] + D0[k][j] == 1 || D0[i][k] + D1[k][j] == 1) D1[i][j] = 1;
                    if (Dm1[i][k] + D0[k][j] == -1 || D0[i][k] + Dm1[k][j] == -1) Dm1[i][j] = -1;
                }
            }
        }
    }
}

void Graph::initAdjacencyMatrices() {
    int n = 4; // Example size
    D1 = Matrix(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    D0 = Matrix(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    Dm1 = Matrix(n, std::vector<int>(n, std::numeric_limits<int>::max()));

    // Example initialization
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                D0[i][j] = 0;
            } else if ((i + 1) % n == j) {
                D1[i][j] = 1;
            } else if ((j + 1) % n == i) {
                Dm1[i][j] = -1;
            }
        }
    }
}
