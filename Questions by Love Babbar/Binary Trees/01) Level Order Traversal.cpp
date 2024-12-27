// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// soln asks for a level by level trasveral soln in vector<vector<int>>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == NULL) return {};
        vector<vector<int>> ans;
        vector<TreeNode*> lvl({root});
        while(!lvl.empty()) {
            vector<TreeNode*> next_lvl;
            ans.push_back(vector<int> ());

            for (auto& it : lvl) {
                ans.back().push_back(it->val);
                if (it->left != NULL) next_lvl.push_back(it->left);
                if (it->right != NULL) next_lvl.push_back(it->right);
            }

            swap(lvl, next_lvl);
        }
        return ans;
    }
};
//swap operator is a constant time operation for standard containers (like vectors) in such a way that only a few pointers are changed.



// classical way of writing the code... using [queue_length]
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == NULL) return {};
        vector<vector<int>> ans;

        queue<TreeNode*> q ({root});

        while(!q.empty()) {
            int sz = q.size();
            ans.push_back(vector<int> ());

            for (int i=0; i<sz; i++) {
                TreeNode* nd = q.front();
                q.pop();

                ans.back().push_back(nd->val);
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
        }
        return ans;
    }
};
