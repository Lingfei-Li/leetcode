// 48.53% fastest
// BST
// DFS

#include"mytest.h"

bool dfs(TreeNode* u, int& k) {
    if(!u) return false;
    if(u->left) {
        if(dfs(u->left, k)) return true;
    }
    if((--k)==0) {
        k = u->val;
        return true;
    }
    if(u->right) {
        if(dfs(u->right, k)) return true;
    }
    return false;
}

int kthSmallest(TreeNode* root, int k) {
    dfs(root, k);
    return k;
}



int main() {
	srand(time(NULL));




    return 0;
}
