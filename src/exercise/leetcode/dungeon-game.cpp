#include <vector>
#include <queue>
using namespace std;

struct Point {
    int max_cost;
    int cur_cost;
    int x, y;
    bool operator<(const Point &p1) const{
        return this->max_cost < p1.max_cost;
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        std::priority_queue<Point> queue;
        Point start{dungeon[0][0], dungeon[0][0], 0, 0};
        queue.push(start);
        while (!queue.empty()) {
            auto p = queue.top();
            auto p2 = p;
            queue.pop();
            if (p.x == dungeon.size() - 1 && p.y == dungeon[0].size() - 1) {
                return p.max_cost < 0 ? 1 - p.max_cost : 1;
            }
            if (p.x < dungeon.size() - 1) {
                int delta = dungeon[++p.x][p.y];
                p. cur_cost +=delta;
                if (p.max_cost > p.cur_cost) {
                    p.max_cost = p.cur_cost;
                }
                queue.push(p);
            }
            if (p2.y < dungeon[0].size() - 1) {
                int delta = dungeon[p2.x][++p2.y];
                p2. cur_cost +=delta;
                if (p2.max_cost > p2. cur_cost) {
                    p2.max_cost = p2. cur_cost;
                }
                queue.push(p2);
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    s.calculateMinimumHP(v);
}