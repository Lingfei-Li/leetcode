// Feature:
// Extra caref for corner cases (integer overflow)
// Maximum value of type "int": (1<<31) <-> (1<<31)-1

#include"mytest.h"


using namespace std;


bool solve(TreeNode* root, int l, int r) {
    if(root == NULL) return true;

    if(root->val < l || root->val > r) {
        return false;
    }
    else if(root->val == (1<<31)-1) {
        return root->right == NULL && solve(root->left, l, root->val-1);    
    }
    else if(root->val == (1<<31)) {
        return root->left == NULL &&  solve(root->right, root->val+1, r);
    }
    else {
        return solve(root->left, l, root->val-1) && solve(root->right, root->val+1, r);
    
    }
    return false;
}


bool isValidBST(TreeNode* root) {
//    printf("%d\n -2147483648\n", (1<<31));
//[-2147483648,-2147483648]
    return solve(root, (1<<31), (1<<31)-1);
}



int main() {
	srand(time(NULL));

    isValidBST(NULL);


    return 0;
}
