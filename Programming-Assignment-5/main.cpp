#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <fstream>
#include "graph.h"
using namespace std;

int main() {
	// Variables
	auto graph = make_unique<Graph>(); // Make graph with unique pointer
	const string inputFile = "graph_input.txt";

	if (!graph->readFromFile(inputFile)) { // If failed to read graph
		cerr << "Failed to open file " << inputFile << endl;
		return 1;
	}

	
	return 0;
}