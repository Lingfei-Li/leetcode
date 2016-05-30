// Feature:
// Iterative in-order tree traversal.

#include"mytest.h"


using namespace std;


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == 0) return ans;
    int clean = 0, dirty = 1;

    //pair: node, state
    stack<pair<TreeNode* ,int> > stk;

    stk.push(pair<TreeNode*,int>(root, clean));

    while(!stk.empty()){
        pair<TreeNode*, int> u = stk.top(); stk.pop();
        if(u.second == clean && u.first->left != NULL) {
            stk.push(pair<TreeNode*, int>(u.first, dirty));
            stk.push(pair<TreeNode*, int>(u.first->left, clean));
        }
        else {
            ans.push_back(u.first->val);  
            if(u.first->right != NULL) {
                stk.push(pair<TreeNode*, int>(u.first->right, clean));
            }
        } 
    }


    return ans;           
}


int main() {
	srand(time(NULL));




    return 0;
}

/*
//Trivial solution
void solve(vector<int>& ans, TreeNode* u) {
    if(u->left != NULL)
        solve(ans, u->left);
    ans.push_back(u->val);

    if(u->right != NULL)
        solve(ans, u->right);
}



vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;

    if(root != NULL) solve(ans, root);



    return ans;           
}

*/
