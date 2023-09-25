#include <vector>

class Solution {
public:
    class Graph {
    public:
        Graph(int _num_vertex) : num_vertex(_num_vertex), arcs(std::vector<std::vector<int>>(_num_vertex, std::vector<int>(_num_vertex, INF))) {}
        
        int num_vertex;
        std::vector<std::vector<int>> arcs;
    };
    
    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        Graph *G = new Graph(n);
        for (std::vector<int> edge : edges) {
            G->arcs[edge[0]][edge[1]] = G->arcs[edge[1]][edge[0]] = edge[2];
        }
        for (int i = 0; i < G->num_vertex; ++i) {
            G->arcs[i][i] = 0;
        }

        for (int k = 0; k < G->num_vertex; ++k) {
            for (int i = 0; i < G->num_vertex; ++i) {
                for (int j = 0; j < G->num_vertex; ++j) {
                    G->arcs[i][j] = G->arcs[j][i] = std::min(G->arcs[i][j], G->arcs[i][k] + G->arcs[k][j]);
                }
            }
        }

        std::vector<std::vector<int>> neighbor(G->num_vertex, std::vector<int>());
        for (int i = 0; i < G->num_vertex; ++i) {
            for (int j = 0; j < G->num_vertex; ++j) {
                if (j != i && G->arcs[i][j] <= distanceThreshold) {
                    neighbor[i].emplace_back(j);
                }
            }
        }

        int min_neighbor_idx = -1;
        for (int i = 0; i < neighbor.size(); ++i) {
            if (min_neighbor_idx == -1 || neighbor[i].size() <= neighbor[min_neighbor_idx].size()) {
                min_neighbor_idx = i;
            }
        }
        return min_neighbor_idx;
    }

    static const int INF = 0x3f3f3f3f;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
