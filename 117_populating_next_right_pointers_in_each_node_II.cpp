#include <queue>
#include <stddef.h>
#include <vector>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return root;
        }

        std::queue<Node*> q;
        std::vector<Node*> v;
        q.push(root);

        while(!q.empty()) {
            Node* prev = nullptr;
            while(q.size() > 0) {
                Node* cur = q.front();
                v.push_back(cur);

                if(prev) {
                    prev->next = cur;
                }

                prev = cur;
                q.pop();
            }

            for(auto n: v) {
                if(n->left) {
                    q.push(n->left);
                }
                if(n->right) {
                    q.push(n->right);
                }
            }

            v.clear();
        }

        return root;
    }
};
