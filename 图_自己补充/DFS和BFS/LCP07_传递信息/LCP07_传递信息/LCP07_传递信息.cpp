#include <iostream>
#include <queue>
#include <vector>

class Graph {
public:
    Graph(int num_vertexes, int num_edges) : num_vertexes(num_vertexes), num_edges(num_edges), arcs(std::vector<std::vector<int>> (num_vertexes, std::vector<int> ())) {}
    
    std::vector<std::vector<int>> arcs;
    int num_vertexes;
    int num_edges;
};

class Round {
public:
    Round(int vertex, int cnt, std::vector<int> route) : vertex(vertex), cnt(cnt), route(route) {}
    
    int vertex;
    int cnt;
    std::vector<int> route;
};

class Solution {
public:
    int numWays(int n, std::vector<std::vector<int>>& relation, int k) {
        Graph G(n, relation.size());
        for (std::vector<int> edge : relation) {
            G.arcs[edge[0]].emplace_back(edge[1]);
        }

        int res = 0;
        std::queue<Round> vertexs;
        vertexs.emplace(0, 0, std::vector<int> {0});
        while (!vertexs.empty()) {
            Round cur_round = vertexs.front();
            int cur_vertex = cur_round.vertex;
            int cur_cnt = cur_round.cnt;
            std::vector<int> cur_route = cur_round.route;
            vertexs.pop();
            if (cur_cnt == k) {
                if (cur_vertex == n - 1) {
                    ++res;

                    // for (int i : cur_route) {
                    //     std::cout << i << " ";
                    // }
                    // std::cout << std::endl;
                }
                continue;
            }

            for (int next_vertex : G.arcs[cur_vertex]) {
                std::vector<int> next_route = cur_route;
                next_route.emplace_back(next_vertex);
                vertexs.emplace(next_vertex, cur_cnt + 1, next_route);
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> relation;
    relation.push_back(std::vector<int> {0, 2});
    relation.push_back(std::vector<int> {2, 1});
    relation.push_back(std::vector<int> {3, 4});
    relation.push_back(std::vector<int> {2, 3});
    relation.push_back(std::vector<int> {1, 4});
    relation.push_back(std::vector<int> {2, 0});
    relation.push_back(std::vector<int> {0, 4});
    int n = 5;
    int k = 3;
    Solution solution;
    std::cout << solution.numWays(n, relation, k);
    return 0;
}
