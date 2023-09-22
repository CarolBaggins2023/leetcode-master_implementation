#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    class Graph {
    public:
        Graph(int _num_vex) : num_vex(_num_vex), arcs(std::vector<std::vector<int>>(_num_vex, std::vector<int>(_num_vex, INF))) {}
        
        int num_vex;
        std::vector<std::vector<int>> arcs;
    };
    
    int MinLenPrim(int N, const std::vector<std::vector<int>> &arcs) {
        auto *G = new Graph(N);
        for (std::vector<int> arc : arcs) {
            G->arcs[arc[0] - 1][arc[1] - 1] = G->arcs[arc[1] - 1][arc[0] - 1] = arc[2];
        }

        int ret = 0;
        std::vector<int> lowcost(G->arcs[0]);
        for (int i = 0; i < G->num_vex - 1; ++i) {
            int min_cost = INF, min_cost_idx = -1;
            for (int j = 1; j < G->num_vex; ++j) {
                if (lowcost[j] != 0 && lowcost[j] < min_cost) {
                    min_cost = lowcost[j];
                    min_cost_idx = j;
                }
            }

            ret += min_cost;
            lowcost[min_cost_idx] = 0;
            for (int j = 1; j < G->num_vex; ++j) {
                if (lowcost[j] != 0 && lowcost[j] > G->arcs[j][min_cost_idx]) {
                    lowcost[j] = G->arcs[j][min_cost_idx];
                }
            }
        }

        return ret;
    }

    class DisjointSetUnion {
    public:
        DisjointSetUnion(int _num) : num(_num), parent(std::vector<int>(_num)), rank(std::vector<int>(_num, 0)) {
            for (int i = 0; i < _num; ++i) {
                parent[i] = i;
            }
        }

        int Find(int x) {
            if (parent[x] == x) {
                return parent[x];
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
            } else if (rank[par_x] > rank[par_y]) {
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
        
        int begin;
        int end;
        int weight;
    };

    int MinLenKruskal(int N, const std::vector<std::vector<int>> &arcs) {
        std::vector<Edge> edges;
        for (std::vector<int> arc : arcs) {
            edges.emplace_back(arc[0] - 1, arc[1] - 1, arc[2]);
        }
        std::sort(edges.begin(), edges.end(), [](Edge x, Edge y) -> bool { return x.weight < y.weight; });

        int num_edge = 0;
        int ret = 0;
        DisjointSetUnion dsu(N);
        for (const Edge &edge : edges) {
            if (dsu.Union(edge.begin, edge.end)) {
                ret += edge.weight;
                ++num_edge;
            }

            if (num_edge == N - 1) {
                break;
            }
        }
        return ret;
    }

    static const int INF = 0x3f3f3f3f;
};

int main(int argc, char* argv[])
{
    int N = 0;
    while (scanf_s("%d", &N) != EOF) {
        if (N == 0) {
            break;
        }

        int begin = -1, end = -1, weight = -1;
        std::vector<std::vector<int>> arcs;
        for (int i = 0; i < N * (N - 1) / 2; ++i) {
            scanf_s("%d %d %d", &begin, &end, &weight);
            arcs.emplace_back(std::vector<int>{begin, end, weight});
        }

        // Solution solution_prim;
        // printf("%d\n", solution_prim.MinLenPrim(N, arcs));
        Solution solution_kruskal;
        printf("%d\n", solution_kruskal.MinLenKruskal(N, arcs));
    }
    return 0;
}
