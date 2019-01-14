/*
872. Leaf-Similar Trees   beat 95.00%
Consider all the leaves of a binary tree.  From left to right order, 
the values of those leaves form a leaf value sequence.
         3
        / \
       5   1
      / \  / \
     6   2 9  8
        / \
       7   4

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vals1,vals2;
        dfs(root1, vals1);
        dfs(root2, vals2);
        for(int i=0; i<vals1.size(); i++){
            if(vals1[i]!=vals2[i])
                return false;
        }
        return true;
    }
    void dfs(TreeNode *root, vector<int>& vals){
        if(root->left==NULL&&root->right==NULL){
            vals.push_back(root->val);
        }
        if(root->left!=NULL){
            dfs(root->left, vals);
        }
        if(root->right!=NULL){
            dfs(root->right, vals);
        }
    }
};
