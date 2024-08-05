//
// Created by Jiang Yinzuo on 2021/3/16.
//
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<int>> graph(wordList.size() + 3, vector<int>());
		bool flag = false;

		for (int i = 0; i < wordList.size(); ++i) {
			if (wordList[i] == beginWord) {
				continue;
			}
			if (wordList[i] == endWord)  {
				flag = true;
				continue;
			}
			if (is_neighbor(wordList[i], beginWord)) {
				graph[i+1].push_back(0);
				graph[0].push_back(i+1);
			}
			if (is_neighbor(wordList[i], endWord)) {
				graph[i+1].push_back(wordList.size() + 1);
				graph[wordList.size() + 1].push_back(i+1);
			}
			for (int  j = 0; j < wordList.size(); ++j) {
				if (is_neighbor(wordList[i], wordList[j])) {
					graph[i+1].push_back(j+1);
				}
			}
		}
		if (!flag) return 0;
		if (is_neighbor(beginWord, endWord)) {
			return 2;
		}
		return bfs(graph, wordList.size() + 1);
	}

	struct Vertex {
		int len;
		int v_id;
	};
	int bfs(vector<vector<int>> &graph, int end_vid) {
		std::queue<Vertex> q;
		q.push(Vertex {1, 0});
		std::vector<bool> visited(graph.size(), false);

		while (!q.empty()) {
			auto v = q.front();
			q.pop();
			visited[v.v_id]= true;
			if (v.v_id == end_vid) {
				return v.len;
			}
			for(auto u : graph[v.v_id]) {
				if (!visited[u]){
					if (u == end_vid) return v.len + 1;
					q.push(Vertex{v.len+1,u});
				}
			}
		}
		return 0;
	}

	bool is_neighbor(string &a, string &b) {
		int diff = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) ++diff;
		}
		return diff == 1;
	}
};