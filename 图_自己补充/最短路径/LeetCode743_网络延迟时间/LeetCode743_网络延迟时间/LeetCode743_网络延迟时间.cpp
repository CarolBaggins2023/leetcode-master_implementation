#include<vector>

class Solution {
public:
    class Graph {
    public:
        Graph(int _num_vertex) : num_vertex(_num_vertex), arcs(std::vector<std::vector<int>>(_num_vertex, std::vector<int>(_num_vertex, INF))) {}
        
        int num_vertex;
        std::vector<std::vector<int>> arcs;
    };

    Graph* BuildGraph(std::vector<std::vector<int>>& times, int n) {
        Graph *G = new Graph(n);
        for (int i = 0; i < G->num_vertex; ++i) {
            G->arcs[i][i] = 0;
        }
        for (const std::vector<int> &arc : times) {
            G->arcs[arc[0] - 1][arc[1] - 1] = arc[2];
        }
        return G;
    }
    
    int networkDelayTime_Floyd(std::vector<std::vector<int>>& times, int n, int k) {
        Graph *G = BuildGraph(times, n);
        
        for (int z = 0; z < n; ++z) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    G->arcs[i][j] = std::min(G->arcs[i][j], G->arcs[i][z] + G->arcs[z][j]);
                }
            }
        }
        
        int ret = 0;
        for (int time : G->arcs[k - 1]) {
            if (time == INF) {
                return -1;
            }
            ret = std::max(ret, time);
        }
        return ret;
    }

    int networkDelayTime_Dijkstra(std::vector<std::vector<int>>& times, int n, int k) {
        Graph *G = BuildGraph(times, n);

        std::vector<bool> used(n, false);
        std::vector<int> dist(n, INF);
        dist[k - 1] = 0;
        for (int i = 0; i < n; ++i) {
            int min_dist_idx = -1;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && (min_dist_idx == -1 || dist[j] < dist[min_dist_idx])) {
                    min_dist_idx = j;
                }
            }

            used[min_dist_idx] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = std::min(dist[j], dist[min_dist_idx] + G->arcs[min_dist_idx][j]);
            }
        }

        int ret = 0;
        for (int i : dist) {
            if (i == INF) {
                return -1;
            }
            ret = std::max(ret, i);
        }
        return ret;
    }

    static const int INF = 0x3f3f3f3f;
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> times;
    times.emplace_back(std::vector<int>{1, 2, 1});
    // times.emplace_back(std::vector<int>{2, 3, 1});
    // times.emplace_back(std::vector<int>{3, 4, 1});
    int n = 2, k = 2;
    Solution solution;
    std::printf("%d", solution.networkDelayTime_Dijkstra(times, n, k));
    
    return 0;
}
