#include "graph.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructors and destructors
Graph::Graph() : n(0) {

}
Graph::Graph(int vertices) : n(vertices), mat(vertices, std::vector<int>(vertices, 0)) { // Initialize with zeros

} 

// Member functions
bool Graph::readFromFile(const std::string& filename) { // Reads graph from a file
    std::ifstream in(filename); // Open file for reading

    if (!in) { // If file did not open
        return false;
    }
    if (!(in >> n)) { // If reading n failed
        return false;
    }

    mat.assign(n, std::vector<int>(n, 0)); // Resize matrix to n x n and initialize with zeros

    for (int i = 0; i < n; ++i) { // For each row
        for (int j = 0; j < n; ++j) { // For each column
            if (!(in >> mat[i][j])) { // If reading matrix element failed
                return false;
            }
        }
    }
    return true;
}
void Graph::printToConsole() const { // Prints graph to console
    std::cout << "Number of vertices is " << n << std::endl;
    std::cout << "Number of edges is " << edgeCount() << std::endl;
    std::cout << "Matrix is:" << std::endl;
    for (int i = 0; i < n; ++i) { // For each row
        for (int j = 0; j < n; ++j) { // For each column
            std::cout << mat[i][j] << (j + 1 == n ? "" : " "); // Print the element
        }
        std::cout << std::endl;
    }
}