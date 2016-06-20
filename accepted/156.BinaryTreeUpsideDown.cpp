#include"mytest.h"
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


    TreeNode* upsideDownBinaryTree(TreeNode* root) {

        TreeNode* newRoot, *v, *u = root;

        stack<TreeNode*> stk;
        while(u){
            stk.push(u);
            u = u->left;
        }
        v = newRoot = stk.top();
        stk.pop();

        while(!stk.empty()){
            u = stk.top();
            stk.pop();
            if(u->right != NULL){
                v->left = u->right;
            }
            else {
                v->left = NULL;
            }
            v->right = u;
            v = u;
        }
        v->left = v->right = 0;
        return newRoot;
    }
};




int main() {
	srand(time(NULL));

    Solution sol;



    return 0;
}
