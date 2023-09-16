#include <queue>
#include <unordered_map>
#include <vector>

class Node {
public:
    Node() : val(0), neighbors(std::vector<Node*>()) {}
    Node(int val) : val(val), neighbors(std::vector<Node*>()) {}
    Node(int val, std::vector<Node*> neighbors) : val(val), neighbors(neighbors) {}
    
    int val;
    std::vector<Node*> neighbors;
};

class SolutionDFS {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // for deep copy, we cannot copy its neighbors
        Node *clone_node = new Node(node->val);
        // avoid endless loop
        visited[node] = clone_node;
        
        for (Node *neighbor : node->neighbors) {
            clone_node->neighbors.emplace_back(cloneGraph(neighbor));
        }

        return clone_node;
    }

    std::unordered_map<Node*, Node*> visited;
};

class SolutionBFS {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        
        std::queue<Node*> que;
        que.emplace(node);
        
        visited[node] = new Node(node->val);

        while (!que.empty()) {
            Node *n = que.front();
            que.pop();

            for (Node *neighbor : n->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    que.push(neighbor);
                }
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }

        return visited[node];
    }

    std::unordered_map<Node*, Node*> visited;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
