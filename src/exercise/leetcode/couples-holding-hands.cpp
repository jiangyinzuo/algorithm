//
// Created by Jiang Yinzuo on 2021/3/15.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <unordered_set>

using namespace std;

class Solution {
public:
	std::unordered_map<int, int> index;
	vector<bool> visited;

	int minSwapsCouples(vector<int> &row) {
		visited.resize(row.size() / 2, false);
		for (int i = 0; i < row.size(); i += 2) {
			if (row[i] + 1 == row[i + 1] && row[i] % 2 == 0 || row[i] == row[i + 1] + 1 && row[i + 1] % 2 == 0) {
				visited[i / 2] = true;
				continue;
			}
			index[row[i]] = i / 2;
			index[row[i + 1]] = i / 2;
		}
		for (int i = 0; i < visited.size(); ++i) {
			if (!visited[i]) {
				remain.clear();
				dfs(i, row);
				--ans;
			}
		}
		return ans;
	}

	std::unordered_set<int> remain;
	int ans = 0;

	void dfs(int cur_idx, vector<int> &row) {
		int elems[2] = {row[cur_idx * 2], row[cur_idx * 2 + 1]};
		for (int e : elems) {
			if (e % 2 == 0 && remain.find(e + 1) != remain.end()) {
				remain.erase(e + 1);
			} else if (e % 2 == 1 && remain.find(e - 1) != remain.end()) {
				remain.erase(e - 1);
			} else {
				remain.insert(e);
			}
		}
		++ans;
		visited[cur_idx] = true;
		if (remain.empty()) {
			return;
		} else {
			for (int e : elems) {
				if (remain.find(e) != remain.end()) {
					if (e % 2 == 0) {
						dfs(index[e + 1], row);
					} else {
						dfs(index[e - 1], row);
					}
				}

				if (remain.empty()) {
					return;
				}
			}
		}
	}
};

int main() {
	Solution s;
	vector<int> row = {5, 4, 2, 6, 3, 1, 0, 7};
	std::cout << s.minSwapsCouples(row);
	return 0;
}