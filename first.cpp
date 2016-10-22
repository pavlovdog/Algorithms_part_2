#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
	// INIT
	std::vector<std::pair <int, int>> edges;
	int nodes_number, edges_number;
	std::cin >> nodes_number >> edges_number;

	for (size_t i = 0; i != edges_number; ++i) {
		std::pair <int, int> tmpEdge;
		std::cin >> tmpEdge.first >> tmpEdge.second;
		edges.push_back(tmpEdge);
	}

	// SOLUTION
	std::vector<int> used_nodes;
	std::vector<std::pair <int, int> > answer;

	for (auto edge : edges) {
		bool check_start = std::find(used_nodes.begin(), used_nodes.end(), edge.first) == used_nodes.end();
		bool check_end = std::find(used_nodes.begin(), used_nodes.end(), edge.second) == used_nodes.end();
		
		if (check_end && check_start) {
			answer.push_back(edge);
			used_nodes.push_back(edge.first);
			used_nodes.push_back(edge.second);
		}
	}

	// PRINT ANSWER
	for (auto edge : answer) {
		std::cout << "(" << edge.first << " " << edge.second << ")" << std::endl;
	}
}