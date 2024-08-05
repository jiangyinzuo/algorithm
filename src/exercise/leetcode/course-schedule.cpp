//
// Created by Jiang Yinzuo on 2021/3/18.
//

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> pres(numCourses, vector<int>()), succs(numCourses, vector<int>());
		vector<int> in_deg(numCourses, 0);
		for (auto &p : prerequisites) {
			pres[p[0]].push_back(p[1]);
			succs[p[1]].push_back(p[0]);
			++in_deg[p[0]];
		}

		queue<int> heads;
		for (int i = 0; i < numCourses; ++i) {
			if (pres[i].empty()) {
				heads.push(i);
			}
		}

		int count = 0;
		while (!heads.empty()) {
			int u = heads.front();
			heads.pop();
			for (int v : succs[u]) {
				if (--in_deg[v] == 0 ) {
					heads.push(v);
				}
			}
			++count;
		}
		return count == numCourses;
	}
};