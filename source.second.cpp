// Run this app at *nix using 'cat data_2.txt | ./x.second'
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <string>

// GLOBAL VARS
int raw_number, raw_size;
std::set<std::string> raws;
std::map<std::string, bool> used_raws;

// DECORATORS
void BFS(std::string raw);
std::string generate_raw(
	std::string raw, 
	int pos1, 
	int pos2, 
	bool two
);

int main() {
	// INIT
	std::cin >> raw_number >> raw_size;

	// INPUT
	for (size_t i = 0; i != raw_number; ++i) {
		std::string raw;
		std::cin >> raw;

		raws.insert(raw);
		used_raws[raw] = false;
	}

	// SOLUTION
	int clasters = 0;
	for (auto raw : raws) {
		if (!used_raws[raw]) {
			BFS(raw);
			clasters++;
		}
	}

	// PRINT ANSWER
	std::cout << clasters << std::endl;
}

void BFS(std::string raw) {
	used_raws[raw] = true;

	// Check list of raws for a line
	// Which differs from 'raw' for 1 symbol
	for (int position = 0; position != raw_size; ++position) {

		auto new_raw = generate_raw(raw, position, 1, false);
		if (raws.find(new_raw) != raws.end()) { // 'new_raw' exists
			if (!used_raws[new_raw]) { // 'new_raw' didn't checked
				BFS(new_raw);
			}
		}

		// Check list of raws for a line
		// Which differs from 'raw' for 2 symbols
		for (int sec_position = 0; sec_position != raw_size; ++sec_position) {

			auto new_raw = generate_raw(raw, position, sec_position, true);
			if (raws.find(new_raw) != raws.end()) {
				if (!used_raws[new_raw]) {
					BFS(new_raw);
				}
			}
		
		}
	}
}

std::string generate_raw(std::string old_raw, int pos1, int pos2, bool two) {
	auto new_raw = old_raw;

	if (!two) { // Change one symbol
		if (old_raw[pos1] == '0') {
			new_raw[pos1] = '1';
		} else {
			new_raw[pos1] = '0';
		}
	} else { // Change two symbols
		if (old_raw[pos1] == '0') {
			new_raw[pos1] = '1';
		} else {
			new_raw[pos1] = '0';
		}

		if (old_raw[pos2] == '0') {
			new_raw[pos2] = '1';
		} else {
			new_raw[pos2] = '0';
		}		
	}

	return new_raw;
}