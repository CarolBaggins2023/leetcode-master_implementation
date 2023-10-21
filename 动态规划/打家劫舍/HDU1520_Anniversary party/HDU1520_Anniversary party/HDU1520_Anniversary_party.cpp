#include <unordered_set>
#include <vector>
#include <cstdio>

class Node {
public:
    Node(int _val, int _idx) : val(_val), idx(_idx), first_child(nullptr), next_sibling(nullptr) {}
    
    int val;
    int idx;
    Node *first_child;
    Node *next_sibling;
};

class Solution {
public:
    std::vector<int> MaxSumIter(Node *root) {
        // pick: /sum{MaxSumIter(children)[0]} + root->val
        // not pick: /sum{/max{MaxSumIter(children)[0], [1]}}
        if (root == nullptr) {
            return std::vector<int>{0, 0};
        }

        std::vector<std::vector<int>> child_sum;
        Node *child = root->first_child;
        while (child) {
            child_sum.emplace_back(MaxSumIter(child));
            child = child->next_sibling;
        }

        int with_root = root->val;
        for (std::vector<int> sum : child_sum) {
            with_root += sum[0];
        }

        int without_root = 0;
        for (std::vector<int> sum : child_sum) {
            without_root += std::max(sum[0], sum[1]);
        }

        return std::vector<int>{without_root, with_root};
    }
    
    int MaxSum(Node *root) {
        std::vector<int> res = MaxSumIter(root);
        return std::max(res[0], res[1]);
    }
};

int main(int argc, char *argv[]) {
    int N = 0;
    std::vector<int> nums;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int n = 0;
        scanf("%d", &n);
        nums.emplace_back(n);
    }

    std::unordered_set<int> idxs;
    for (int i = 0; i < N; ++i) {
        idxs.insert(i);
    }
    std::vector<Node*> nodes(N, nullptr);
    int L = 0, K = 0;
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d %d", &L, &K);
    
        --L;
        --K;
        idxs.erase(L);

        if (nodes[L] == nullptr) {
            nodes[L] = new Node(nums[L], L + 1);
        }
        if (nodes[K] == nullptr) {
            nodes[K] =  new Node(nums[K], K + 1);
        }
        nodes[L]->next_sibling = nodes[K]->first_child;
        nodes[K]->first_child = nodes[L];
    }
    
    int root_idx = *idxs.begin();
    Solution solution;
    if (N > 1) {
        printf("%d", solution.MaxSum(nodes[root_idx]));
    } else {
        printf("%d", nums[0]);
    }
    
    
    return 0;
}