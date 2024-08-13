#include <limits.h>
#include <algorithm>

class TreeNode {
  public:
  int val;

  TreeNode(int val) : val{val} {}
  
  TreeNode* prev;
  TreeNode* left;
  TreeNode* sec;
  TreeNode* right;
};


class Solution {
public:
    TreeNode* prev{nullptr};
    TreeNode* first{nullptr};
    TreeNode* sec{nullptr};

    void recurse(TreeNode* cur) {
        if(!cur) { return; }

        recurse(cur->left);

        if(!first && cur->val < prev->val) {
            first = prev;
        }
        if(first && cur->val < prev->val) {
            sec = cur;
        }

        prev = cur;

        recurse(cur->right);
    }

    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        recurse(root);
        std::swap(first->val, sec->val);
    }
};
