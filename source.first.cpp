#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

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
	std::vector<bool> used_nodes (n, false); // Init for O(n)
	std::vector<std::pair <int, int> > answer;

	for (auto edge : edges) {
		bool check_start = !used[edge.first];
		bool check_end = !used[edge.second];
		
		if (check_end && check_start) {
			answer.push_back(edge);
			used_nodes[edge.first] = True;
			used_nodes[edge.second] = True;
		}
	}

	// PRINT ANSWER
	for (auto edge : answer) {
		std::cout << "(" << edge.first << " " << edge.second << ")" << std::endl;
	}
}
