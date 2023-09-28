#include <stack>
#include <vector>

class Solution {
public:
    class ArcNode {
    public:
        ArcNode(int _adj_idx, ArcNode *_next) : adj_idx(_adj_idx), next(_next) {}
        
        int adj_idx;
        ArcNode *next;
    };
    
    class VertexNode {
    public:
        VertexNode(int _idx, int _quiet) : idx(_idx), quiet(_quiet), cnt_in(0), first_arc(nullptr) {}
        
        int idx;
        int quiet;
        int cnt_in;
        ArcNode *first_arc;
    };
    
    class Graph {
    public:
        Graph(int _num_vertex) : num_vertex(_num_vertex), vertex(std::vector<VertexNode>()) {}
        
        void BuildGraph(const std::vector<std::vector<int>>& richer, const std::vector<int>& quiet) {
            for (int i = 0; i < num_vertex; ++i) {
                vertex.emplace_back(i, quiet[i]);
            }
            
            for (const std::vector<int> &arc : richer) {
                ArcNode *temp = vertex[arc[0]].first_arc;
                vertex[arc[0]].first_arc = new ArcNode(arc[1], temp);
                ++vertex[arc[1]].cnt_in;
            }
        }
        
        int num_vertex;
        std::vector<VertexNode> vertex;
    };
    
    std::vector<int> loudAndRich(std::vector<std::vector<int>>& richer, std::vector<int>& quiet) {
        Graph *G = new Graph(quiet.size());
        G->BuildGraph(richer, quiet);

        std::vector<int> min_quiet(G->num_vertex);
        for (int i = 0; i < min_quiet.size(); ++i) {
            min_quiet[i] = i;
        }
        std::stack<int> stk;
        for (int i = 0; i < G->num_vertex; ++i) {
            if (G->vertex[i].cnt_in == 0) {
                stk.emplace(i);
            }
        }

        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            
            ArcNode *arc = G->vertex[idx].first_arc;
            while (arc) {
                if (G->vertex[min_quiet[idx]].quiet < G->vertex[arc->adj_idx].quiet) {
                    min_quiet[arc->adj_idx] = min_quiet[idx];
                }
                
                --G->vertex[arc->adj_idx].cnt_in;
                if (G->vertex[arc->adj_idx].cnt_in == 0) {
                    stk.emplace(arc->adj_idx);
                }
                arc = arc->next;
            }
        }

        return min_quiet;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> richer;
    richer.emplace_back(std::vector<int>{1, 0});
    richer.emplace_back(std::vector<int>{2, 1});
    richer.emplace_back(std::vector<int>{3, 1});
    richer.emplace_back(std::vector<int>{3, 7});
    richer.emplace_back(std::vector<int>{4, 3});
    richer.emplace_back(std::vector<int>{5, 3});
    richer.emplace_back(std::vector<int>{6, 3});
    std::vector<int> quiet{3, 2, 5, 4, 6, 1, 7, 0};
    Solution solution;
    std::vector<int> res = solution.loudAndRich(richer, quiet);
    for (int i : res) {
        printf("%d ", i);
    }
    
    return 0;
}
