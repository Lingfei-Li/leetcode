// Feature:
// Symmetric tree
// Iterative version: the use of stack

#include"mytest.h"


using namespace std;



bool isSame(TreeNode* u, TreeNode* v) {
    if(u == 0 && v == 0) return true;
    if((!u && v)||(u && !v)) return false;

    if(u->val != v->val)return false;

    return isSame(u->left, v->right)&&isSame(u->right, v->left);

}




bool isSymmetric(TreeNode* root) {

    if(!root) return true;

    stack<TreeNode*> stk;
    stk.push(root->left);
    stk.push(root->right);

    while(!stk.empty()) {

        TreeNode*u = stk.top();
        stk.pop();
        TreeNode*v = stk.top();
        stk.pop();

        if(u == 0 && v == 0) continue;
        if((!u && v)||(u && !v)) return false;
        if(u->val != v->val)return false;
        stk.push(v->right);
        stk.push(u->left);
        stk.push(v->left);
        stk.push(u->right);
    }

    return true;
}


int main() {
	srand(time(NULL));




    return 0;
}
