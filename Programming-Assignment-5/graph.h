#pragma once
#include <vector>
#include <string>

class Graph {
public:
	// Constructors and destructors
	Graph();
	explicit Graph(int vertices);

	// Member functions
	bool readFromFile(const std::string& filename);
	bool writeToFile(const std::string& filename) const;
	int edgeCount() const; // Number of edges
	void printToConsole() const;

private:
	// Variables
	int n; // Number of vertices
	std::vector<std::vector<int>> mat; // Adjacency matrix
};