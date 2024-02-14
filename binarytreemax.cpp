#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
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
    int maxPathSol(TreeNode* root, int &maxx) {
        if (root == nullptr) {
            return 0;
        }
        int lh = max(0, maxPathSol(root->left, maxx));  
        int rh = max(0, maxPathSol(root->right, maxx)); 
        maxx = max(maxx, lh + rh + root->val);
        return root->val + max(lh, rh); 
    }
    
    int maxPathSum(TreeNode* root) {
        int maxx = INT_MIN;
        maxPathSol(root, maxx);
        return maxx;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int result = sol.maxPathSum(root);
    cout << "Maximum path sum: " << result << endl;
    return 0;
}
