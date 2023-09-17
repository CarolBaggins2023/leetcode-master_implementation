#include <vector>

const int INF = 0x3f3f3f3f;

class Graph {
public:
    Graph(int _num_vertexes, int _num_arcs) : num_vertexes(_num_vertexes), num_arcs(_num_arcs), arcs(std::vector<std::vector<int>>(_num_vertexes, std::vector<int>(_num_vertexes, INF))) {}
    
    int num_vertexes;
    int num_arcs;
    std::vector<std::vector<int>> arcs;
};

class Solution {
public:
    int CalDis(std::vector<int> a, std::vector<int> b) {
        return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
    }
    
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        Graph *G = new Graph(points.size(), points.size() / 2 * (points.size() - 1));
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i; j < points.size(); ++j) {
                if (i == j) {
                    G->arcs[i][j] = 0;
                    continue;
                }
                G->arcs[i][j] = G->arcs[j][i] = CalDis(points[i], points[j]);
            }
        }

        std::vector<int> lowcost(G->arcs[0]);
        // std::vector<int> adjvex(G->num_vertexes, 0);
        int sum_cost = 0;
        
        for (int i = 1; i < G->num_vertexes; ++i) {
            int min_cost = INF, min_cost_idx = -1;
            for (int j = 1; j < G->num_vertexes; ++j) {
                if (lowcost[j] != 0 && lowcost[j] < min_cost) {
                    min_cost = lowcost[j];
                    min_cost_idx = j;
                }
            }
            sum_cost += lowcost[min_cost_idx];
            lowcost[min_cost_idx] = 0;
            for (int j = 1; j < G->num_vertexes; ++j) {
                if (lowcost[j] != 0 && lowcost[j] > G->arcs[min_cost_idx][j]) {
                    lowcost[j] = G->arcs[min_cost_idx][j];
                    // adjvex[j] = min_cost_idx;
                }
            }
        }

        return sum_cost;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> points;
    points.emplace_back(std::vector<int>{0, 0});
    points.emplace_back(std::vector<int>{1, 1});
    Solution solution;
    int sum_cost = solution.minCostConnectPoints(points);
    std::printf("%d", sum_cost);
    
    return 0;
}
