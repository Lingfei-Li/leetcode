// Feature:
// Definition of "height balanced tree"
// DFS

#include"mytest.h"


using namespace std;


int solve(TreeNode* u, int d) {
    if(!u) return d;
    int d1 = solve(u->left, d+1);
    int d2 = solve(u->right, d+1);
    if(d1-d2 > 1 || d2-d1 > 1) return 1<<31;
    return max(d1,d2);
}


bool isBalanced(TreeNode* root) {
    int d = solve(root, 0);
    if(d >= 0) return true;
    return false;
}


int main() {
	srand(time(NULL));




    return 0;
}
