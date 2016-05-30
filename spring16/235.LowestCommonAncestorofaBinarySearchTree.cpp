// 98.73% fastest
// BST

#include"mytest.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                
    while(1) {
        if(!root || !p || !q) return 0;
        int a = p->val, c = q->val, b = root->val;
        if((a <= b && b <= c)|| (a >= b && b >= c))
            return root;

        if(a > b && c > b) 
            root = root->right;
        else
            root = root->left;
    }
    return 0;
}



int main() {
	srand(time(NULL));



    TreeNode* u = readTree();
    printTree(u);
    TreeNode* p = u->right->left, *q = u->right->right;
    cout<<p->val<<" "<<q->val<<endl;
    TreeNode* v = lowestCommonAncestor(u, p, q);
    cout<<v->val<<endl;



    return 0;
}
