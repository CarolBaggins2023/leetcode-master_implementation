#include <iostream>
#include <vector>

class Solution {
public:
    class Graph {
    public:
        Graph(int _num_vertex, int _num_arc) : num_vertex(_num_vertex), num_arc(_num_arc), arcs(std::vector<std::vector<int>>(_num_vertex, std::vector<int>(_num_vertex, INF))) {}
        
        int num_vertex;
        int num_arc;
        std::vector<std::vector<int>> arcs;
    };
    
    int CalMinTime(int N, int M, const std::vector<std::vector<int>> &arcs) {
        auto *G = new Graph(N, M);
        for (const std::vector<int> &arc : arcs) {
            G->arcs[arc[0] - 1][arc[1] - 1] = G->arcs[arc[1] - 1][arc[0] - 1] = arc[2];
        }
        for (int i = 0; i < G->num_vertex; ++i) {
            G->arcs[i][i] = 0;
        }

        std::vector<bool> used(N, false);
        std::vector<int> dis(N, INF);
        dis[0] = 0;
        for (int _ = 0; _ < N; ++_) {
            int min_dis = INF, min_dis_idx = -1;
            for (int i = 0; i < G->num_vertex; ++i) {
                if (!used[i] && dis[i] < min_dis) {
                    min_dis = dis[i];
                    min_dis_idx = i;
                }
            }

            used[min_dis_idx] = true;
            for (int i = 0; i < G->num_vertex; ++i) {
                dis[i] = std::min(dis[i], min_dis + G->arcs[i][min_dis_idx]);
            }
        }

        return dis[N - 1];
    }

    static const int INF = 0x3f3f3f3f;
};

int main(int argc, char* argv[])
{
    int N = 0, M = 0;
    while (scanf_s("%d %d", &N, &M) != EOF) {
        if (N == 0 && M == 0) {
            break;
        }
        std::vector<std::vector<int>> edges;
        for (int _ = 0; _ < M; ++_) {
            int begin = 0, end = 0, w = 0;
            scanf_s("%d %d %d", &begin, &end, &w);
            edges.emplace_back(std::vector<int>{begin, end, w});
        }

        Solution solution;
        printf("%d\n", solution.CalMinTime(N, M, edges));
    }
    
    return 0;
}
