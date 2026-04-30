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
    std::ifstream in(filename);

    if (!in) { // If file did not open
        return false;
    }
    if (!(in >> n)) { // If reading n failed
        return false;
    }

    mat.assign(n, std::vector<int>(n, 0)); // Resize and initialize with zeros

    for (int i = 0; i < n; ++i) { // For each row
        for (int j = 0; j < n; ++j) { // For each column
            if (!(in >> mat[i][j])) { // If reading fails
                return false;
            }
        }
    }
    return true;
}
bool Graph::writeToFile(const std::string& filename) const { // Writes graph to file
    std::ofstream out(filename); // Open file

    if (!out) { // If file did not open
        return false;
    }

    out << n << std::endl; // Write number of vertices

    for (int i = 0; i < n; ++i) { // For each row
        for (int j = 0; j < n; ++j) { // For each column
            out << mat[i][j] << (j + 1 == n ? "" : " "); // Write element with space except for last
        }
        out << std::endl;
    }
    return true;
}
int Graph::edgeCount() const { // Number of edges in the graph
    int count = 0;
    for (int i = 0; i < n; ++i) { // For each row
        for (int j = i + 1; j < n; ++j) { // For each column after the diagonal
            if (mat[i][j] != 0) { // If there is an edge
                ++count;
            }
        }
    }

    return count;
}
void Graph::printToConsole() const { // Print to console
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

// Set functions
void Graph::setEdge(int i, int j, int weight) { // Sets weight of the edge
    if (i >= 0 && i < n && j >= 0 && j < n) { // If indices are valid
        mat[i][j] = weight;
    }
}

// Get functions
int Graph::getVertexCount() const { // Number of vertices
    return n;
}
int Graph::getEdge(int i, int j) const { // Weight of the edge
    if (i >= 0 && i < n && j >= 0 && j < n) { // If indices are valid
        return mat[i][j];
    }
    return false; // Invalid indices
}
const std::vector<std::vector<int>>& Graph::getMatrix() const { // Matrix
    return mat;
}
