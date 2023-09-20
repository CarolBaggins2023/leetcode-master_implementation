#include <algorithm>
#include <vector>

class Solution {
public:
    class Graph {
    public:
        Graph(int n, int m) : vertex_num(n), arc_num(m), arcs(std::vector<std::vector<int>>(n, std::vector<int>(n, INF))) {}
        
        int vertex_num;
        int arc_num;
        std::vector<std::vector<int>> arcs;
    };
    
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最小的花费代价使得这n户人家连接起来
     * @param n int整型 n户人家的村庄
     * @param m int整型 m条路
     * @param cost int整型vector<vector<>> 一维3个参数，表示连接1个村庄到另外1个村庄的花费的代价
     * @return int整型
     */
    int miniSpanningTree(int n, int m, std::vector<std::vector<int> >& cost) {
        // write code here
        Graph *G = new Graph(n, m);
        for (int i = 0; i < G->vertex_num; ++i) {
            G->arcs[i][i] = 0;
        }
        for (const std::vector<int> &arc : cost) {
            if (arc[2] < G->arcs[arc[0] - 1][arc[1] - 1]) {
                G->arcs[arc[0] - 1][arc[1] - 1] = G->arcs[arc[1] - 1][arc[0] - 1] = arc[2];
            }
        }

        std::vector<int> lowcost(G->arcs[0]);
        std::vector<int> adjvex(n, 0);
        int ret = 0;
        for (int i = 1; i < G->vertex_num; ++i) {
            int min_cost = INF, min_cost_idx = -1;
            for (int j = 0; j < G->vertex_num; ++j) {
                if (lowcost[j] != 0 && lowcost[j] < min_cost) {
                    min_cost_idx = j;
                    min_cost = lowcost[j];
                }
            }

            lowcost[min_cost_idx] = 0;
            ret += min_cost;
            for (int j = 0; j < G->vertex_num; ++j) {
                if (lowcost[j] != 0 && lowcost[j] > G->arcs[j][min_cost_idx]) {
                    lowcost[j] = G->arcs[j][min_cost_idx];
                    adjvex[j] = min_cost_idx;
                }
            }
        }

        return ret;
    }

    static const int INF = 0x3f3f3f3f;
};

class SolutionKruskal {
public:
    class DisjointSetUnion {
    public:
        DisjointSetUnion(int _num) : num(_num), parent(std::vector<int>(_num)), rank(std::vector<int>(_num, 0)) {
            for (int i = 0; i < num; ++i) {
                parent[i] = i;
            }
        }

        int Find(int x) {
            if (parent[x] == x) {
                return x;
            }
        
            parent[x] = Find(parent[x]);
            return parent[x];
        }

        bool Union(int x, int y) {
            int par_x = Find(x), par_y = Find(y);
            if (par_x == par_y) {
                return false;
            }

            if (rank[par_x] < rank[par_y]) {
                parent[par_x] = par_y;
            } else if (rank[par_y] < rank[par_x]) {
                parent[par_y] = par_x;
            } else {
                parent[par_y] = par_x;
                ++rank[par_x];
            }
            return true;
        }

        int num;
        std::vector<int> parent;
        std::vector<int> rank;
    };

    class Edge {
    public:
        Edge(int _begin, int _end, int _weight) : begin(_begin), end(_end), weight(_weight) {}

        bool operator < (const Edge &rhs) const {
            return weight < rhs.weight;
        }
        
        int begin;
        int end;
        int weight;
    };
    
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最小的花费代价使得这n户人家连接起来
     * @param n int整型 n户人家的村庄
     * @param m int整型 m条路
     * @param cost int整型vector<vector<>> 一维3个参数，表示连接1个村庄到另外1个村庄的花费的代价
     * @return int整型
     */
    int miniSpanningTree(int n, int m, std::vector<std::vector<int> >& cost) {
        // write code here
        std::vector<Edge> edges;
        for (const std::vector<int> &edge : cost) {
            edges.emplace_back(edge[0], edge[1], edge[2]);
        }
        std::sort(edges.begin(), edges.end());

        DisjointSetUnion dsu(n);
        int edge_cnt = 0, ret = 0;
        for (const Edge &edge : edges) {
            if (dsu.Union(edge.begin - 1, edge.end - 1)) {
                ++edge_cnt;
                ret += edge.weight;
            }
            if (edge_cnt == n - 1) {
                break;
            }
        }
        
        return ret;
    }
};





int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> points;
    points.emplace_back(std::vector<int>{1, 3, 3});
    points.emplace_back(std::vector<int>{1, 2, 1});
    SolutionKruskal solution;
    int sum_cost = solution.miniSpanningTree(3, 2, points);
    std::printf("%d", sum_cost);
    return 0;
}
