#include <iostream>
#include <stack>
#include <vector>

class ArcNode {
public:
    ArcNode(int _adjvex, int _weight, ArcNode *_next) : adjvex(_adjvex), weight(_weight), next(_next) {}
    
    int adjvex;
    int weight;
    ArcNode *next;
};

class VertexNode {
public:
    VertexNode() : idx(-1), cnt_in(0), first_arc(nullptr) {}
    VertexNode(int _idx) : idx(_idx), cnt_in(0), first_arc(nullptr) {}
    
    int idx;
    int cnt_in;
    ArcNode *first_arc;
};

class Graph {
public:
    Graph(int _num_vertex) : num_vertex(_num_vertex), vertex(std::vector<VertexNode>(_num_vertex)) {
        for (int i = 0; i < _num_vertex; ++i) {
            vertex[i].idx = i;
        }
    }
    
    void BuildGraph(std::vector<std::vector<int>> arcs) {
        for (std::vector<int> arc : arcs) {
            ArcNode *temp = vertex[arc[0]].first_arc;
            vertex[arc[0]].first_arc = new ArcNode(arc[1], arc[2], temp);
            ++vertex[arc[1]].cnt_in;
        }
    }
    
    int num_vertex;
    std::vector<VertexNode> vertex;
};

void TopologicalSort(Graph G, std::vector<int> &earliest_begin_time, std::stack<int> &inverse_stk) {
    std::stack<int> stk;
    for (int i = 0; i < G.num_vertex; ++i) {
        if (G.vertex[i].cnt_in == 0) {
            stk.emplace(i);
        }
    }

    while (!stk.empty()) {
        int idx = stk.top();
        stk.pop();
        inverse_stk.emplace(idx);

        for (ArcNode *arc = G.vertex[idx].first_arc; arc != nullptr; arc = arc->next) {
            int k = arc->adjvex;
            --G.vertex[k].cnt_in;
            if (G.vertex[k].cnt_in == 0) {
                stk.emplace(k);
            }

            earliest_begin_time[k] = std::max(earliest_begin_time[k], earliest_begin_time[idx] + arc->weight);
        }
    }
}

int FindCriticalPath(const Graph *G) {
    std::vector<int> earliest_begin_time(G->num_vertex, 0);
    std::stack<int> inverse_stk;
    TopologicalSort(*G, earliest_begin_time, inverse_stk);

    
    std::vector<int> latest_begin_time(G->num_vertex, earliest_begin_time[G->num_vertex - 1]);
    while (!inverse_stk.empty()) {
        int idx = inverse_stk.top();
        inverse_stk.pop();

        for (ArcNode *arc = G->vertex[idx].first_arc; arc != nullptr; arc = arc->next) {
            latest_begin_time[idx] = std::min(latest_begin_time[idx], latest_begin_time[arc->adjvex] - arc->weight);
        }
    }

    int ret = 0;
    for (int i = 0; i < G->num_vertex; ++i) {
        for (const ArcNode *arc = G->vertex[i].first_arc; arc != nullptr; arc = arc->next) {
            int j = arc->adjvex;
            // the event should be later than the begin_vertex, but must be earlier than the end_event 
            int event_earliest_begin_time = earliest_begin_time[i];
            int event_latest_begin_time = latest_begin_time[j] - arc->weight;

            if (event_earliest_begin_time == event_latest_begin_time) {
                ret += arc->weight;
            }
        }
    }
    return ret;
}

int main(int argc, char* argv[])
{
    int N = -1, M = -1;
    scanf_s("%d %d", &N, &M);
    std::vector<std::vector<int>> arcs;
    for (int _ = 0; _ < M; ++_) {
        int X = -1, Y = -1, Z = -1;
        scanf_s("%d %d %d", &X, &Y, &Z);
        arcs.emplace_back(std::vector<int>{X, Y, Z});
    }

    Graph *G = new Graph(N);
    G->BuildGraph(arcs);
    
    printf("%d", FindCriticalPath(G));
    
    return 0;
}
