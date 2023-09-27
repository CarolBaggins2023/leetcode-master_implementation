#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    class ArcNode {
    public:
        ArcNode(int _adjvex) : adjvex(_adjvex), next(nullptr) {}
        ArcNode(int _adjvex, ArcNode *_next) : adjvex(_adjvex), next(_next) {}
        
        int adjvex;
        ArcNode *next;
    };
    
    class VertexNode {
    public:
        VertexNode() : cnt_in(0), data(0), first_arc(nullptr) {}
        
        int cnt_in;
        int data;
        ArcNode *first_arc;
    };

    class Graph {
    public:
        Graph(int _num_vertex) : num_vertex(_num_vertex), vertex(std::vector<VertexNode>(_num_vertex)) {
            for (int i = 0; i < vertex.size(); ++i) {
                vertex[i].data = i;
            }
        }

        void BuildGraph(const std::vector<std::vector<int>>& prerequisites) {
            for (const std::vector<int> &arc : prerequisites) {
                ArcNode *temp = vertex[arc[1]].first_arc;
                vertex[arc[1]].first_arc = new ArcNode(arc[0], temp);
                ++vertex[arc[0]].cnt_in;
            }
        }
        
        int num_vertex;
        std::vector<VertexNode> vertex;
    };
    
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        Graph *G = new Graph(numCourses);
        G->BuildGraph(prerequisites);

        int cnt = 0;
        std::stack<VertexNode> stk;
        std::vector<int> order;
        for (const VertexNode &vertex_node : G->vertex) {
            if (vertex_node.cnt_in == 0) {
                stk.emplace(vertex_node);
            }
        }
        while (!stk.empty()) {
            const VertexNode &vertex_node = stk.top();
            stk.pop();
            order.emplace_back(vertex_node.data);

            ArcNode *arc = vertex_node.first_arc;
            while (arc) {
                --G->vertex[arc->adjvex].cnt_in;
                if (G->vertex[arc->adjvex].cnt_in == 0) {
                    stk.emplace(G->vertex[arc->adjvex]);
                }
                arc = arc->next;
            }
        }

        if (order.size() < numCourses) {
            return std::vector<int>{};
        }
        
        return order;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites;
    prerequisites.emplace_back(std::vector<int>{0, 1});
    // prerequisites.emplace_back(std::vector<int>{1, 0});
    for (int i : solution.findOrder(numCourses, prerequisites)) {
        std::cout << i << " ";
    }
    
    return 0;
}
