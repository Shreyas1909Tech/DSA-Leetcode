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
    vector<int> largestValues(TreeNode* root) {
    vector<int>result;
    if(!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
     int levelSize=q.size();
     int maxval=INT_MIN;

     for(int i=0;i<levelSize;++i)
     {
        TreeNode* curr=q.front();
        q.pop();
        
        maxval=max(maxval,curr->val);

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
     }  
     result.push_back(maxval); 
    } 
    return result;
    }
};