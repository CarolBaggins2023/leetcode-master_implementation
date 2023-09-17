#include <queue>
#include <vector>

class Graph {
public:
    Graph(int num_vertexes, int num_edges) : num_vertexes(num_vertexes), num_edges(num_edges), arcs(std::vector<std::vector<int>>(num_vertexes, std::vector<int>())) {}

    int num_vertexes;
    int num_edges;
    std::vector<std::vector<int>> arcs;
};

class SolutionDFS {
public:
    bool DFS(Graph &G, std::vector<bool> &visited, int vertex, int destination) {
        if (vertex == destination) {
            return true;
        }

        visited[vertex] = true;
        for (int next_vertex : G.arcs[vertex]) {
            if (!visited[next_vertex] && DFS(G, visited, next_vertex, destination)) {
                return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        Graph G = Graph(n, edges.size());
        for (std::vector<int> edge : edges) {
            G.arcs[edge[0]].emplace_back(edge[1]);
            G.arcs[edge[1]].emplace_back(edge[0]);
        }
        std::vector<bool> visited(n, false);
        return DFS(G, visited, source, destination);
    }
};

class SolutionBFS {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        Graph G = Graph(n, edges.size());
        for (std::vector<int> edge : edges) {
            G.arcs[edge[0]].emplace_back(edge[1]);
            G.arcs[edge[1]].emplace_back(edge[0]);
        }
        std::vector<bool> visited(n, false);
        std::queue<int> vertexes;
        vertexes.emplace(source);
        visited[source] = true;
        while (!vertexes.empty()) {
            int cur_vertex = vertexes.front();
            vertexes.pop();
            if (cur_vertex == destination) {
                return true;
            }

            for (int next_vertex : G.arcs[cur_vertex]) {
                if (!visited[next_vertex]) {
                    vertexes.emplace(next_vertex);
                    visited[next_vertex] = true;
                }
            }
        }

        return false;
    }
};


int main(int argc, char* argv[])
{
    
    return 0;
}
