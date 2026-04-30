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

	int startVertices[] = { 3, 7, 9 };
	for (int i = 0; i < 3; i++) {
		int start = startVertices[i];
		cout << endl;
		cout << "Begin MST" << i + 1 << "at starting Vertex" << start << endl;

		Graph mst = graph->primMst(start); // need to implement
		mst.printToConsole();

		string filename = "mst" << to_string(i + 1) + ".txt";
		if (!mst.writeToFile(filename)) {
			cout << "Error: could not write to " << filename << endl; // check if write failed
		}
		else {
			cout << "End of MST " << (i + 1) << endl;
		}
	}

	
	return 0;
}