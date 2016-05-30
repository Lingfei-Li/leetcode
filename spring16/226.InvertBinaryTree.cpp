#include"mytest.h"

TreeNode* invertTree(TreeNode* root) {
    if(!root) return 0;
    
    TreeNode* tmp = 0;
    tmp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = tmp;
            
    return root;
}


int main() {
	srand(time(NULL));




    return 0;
}
