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

	cout << "Initial Graph" << endl;
	graph->printToConsole();
	cout << "End of initial graph" << endl;
	cout << endl;

	vector<int> starts = { 3, 7, 9 };
	for (size_t i = 0; i < starts.size(); ++i) { // For each starting vertex
		int start = starts[i];

		if (start < 0 || start >= graph->getVertexCount()) { // If invalid vertex
			cerr << "Invalid start vertex: " << start << endl;
			continue;
		}

		string outname = "mst_" + to_string(i + 1) + ".txt"; // Output file name

		cout << "Begin MST " << (i + 1) << " starting at Vertex " << start << endl;

		auto mst = primMST(*graph, start, outname); // Compute MST and write to file

		cout << "Wrote MST to " << outname << endl;
		cout << endl;
	}

	
	return 0;
}