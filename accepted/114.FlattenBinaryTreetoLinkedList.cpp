// Feature:
// Recursion / Divide and conquer

#include"mytest.h"


using namespace std;

TreeNode* last(TreeNode* u) {
    while(u->right) u = u->right;
    return u;
}

void flatten(TreeNode* u) {

    if(!u) return;
    if(u->right) flatten(u->right);
    if(u->left) {
        flatten(u->left);
        TreeNode* left_last = last(u->left);
        left_last->right = u->right;
        u->right = u->left;
        u->left = 0;
    }
}


int main() {
	srand(time(NULL));



    return 0;
}
