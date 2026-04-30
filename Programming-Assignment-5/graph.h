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

	// Set functions
	void setEdge(int i, int j, int weight); // Sets weight of the edge

	// Get functions
	int getVertexCount() const; // Number of vertices
	int getEdge(int i, int j) const; // Weight of the edge
	const std::vector<std::vector<int>>& getMatrix() const; // Matrix

private:
	int n; // Number of vertices
	std::vector<std::vector<int>> mat; // Matrix
};