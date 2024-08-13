#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool balanced = true;

    int recurse(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int left_height = recurse(root->left) + 1;
        int right_height = recurse(root->right) + 1;

        if(std::abs(left_height - right_height) > 1) {
            balanced = false;
        }

        return std::max(left_height, right_height);
    }

    bool isBalanced(TreeNode* root) {
        recurse(root);
        return balanced;
    }
};
