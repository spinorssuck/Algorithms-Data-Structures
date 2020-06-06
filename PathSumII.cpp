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
class Solution {
public:
    //Move the recursion to a helper function
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> PathList;
        vector<int> path;
        pathTraversal(root,sum,path,PathList);
        return PathList;
    }
    
    void pathTraversal(TreeNode* root, int sum,vector<int> path, vector<vector<int>> &PathList){

        //Base case
        if(root==NULL)
            return;
        int check=root->val;
        path.push_back(root-> val);
        if(root-> left ==NULL && root -> right == NULL && check==sum){
            PathList.push_back(path);
        }
        
        //Recursive step
        pathTraversal(root->left,sum-check,path,PathList);
        pathTraversal(root->right,sum-check,path,PathList);
        path.pop_back();
    }
};