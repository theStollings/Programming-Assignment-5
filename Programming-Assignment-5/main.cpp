#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <fstream>
#include "graph.h"
using namespace std;

unique_ptr<Graph> primMST(const Graph& g, int startVertex, const string& outFilename) { // Prim's algorithm for MST
	// Variables
	int n = g.getVertexCount(); // Number of vertices
	const int INF = numeric_limits<int>::max(); // Infinity value
	vector<int> key(n, INF); // Key values
	vector<int> parent(n, -1); // Parent array
	vector<bool> inMST(n, false); // In MST set
	key[startVertex] = 0; // Start vertex key value is 0
	auto mst = make_unique<Graph>(n); // MST graph

	// Open output file for writing edge additions
	ofstream outFile(outFilename);

	for (int count = 0; count < n; ++count) { // For each vertex
		int u = -1;
		int minKey = INF;
		for (int v = 0; v < n; ++v) { // For each vertex
			if (!inMST[v] && key[v] < minKey) { // If vertex not in MST and key is smaller
				minKey = key[v]; // Update min key
				u = v;
			}
		}
		if (u == -1) { // If no vertex found
			break; // Break for loop
		}

		inMST[u] = true; // Add vertex to MST

		if (parent[u] != -1) { // If not the start vertex
			int p = parent[u]; // Parent vertex
			int w = g.getEdge(p, u); // Edge weight
			mst->setEdge(p, u, w); // Add edge to MST
			mst->setEdge(u, p, w); // Undirected graph
			cout << "Add edge " << p << " to " << u << " Weight: " << w << endl;
			if (outFile) {
				outFile << "Add edge " << p << " to " << u << " Weight: " << w << endl;
			}
		}

		for (int v = 0; v < n; ++v) { // For each vertex
			int w = g.getEdge(u, v); // Edge weight
			if (w != 0 && !inMST[v] && w < key[v]) { // If edge exists, vertex not in MST, and weight is smaller
				key[v] = w; // Update key
				parent[v] = u; // Update parent
			}
		}
	}

	// Print MST matrix to console and file
	mst->printToConsole();
	if (outFile) {
		outFile << "Number of vertices is " << mst->getVertexCount() << endl;
		outFile << "Number of edges is " << mst->edgeCount() << endl;
		outFile << "Matrix is:" << endl;
		const auto& mat = mst->getMatrix();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				outFile << mat[i][j] << (j + 1 == n ? "" : " ");
			}
			outFile << endl;
		}
	}

	cout << "End of MST" << endl << endl;

	return mst;
}

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

	system("pause");
	
	return 0;
}