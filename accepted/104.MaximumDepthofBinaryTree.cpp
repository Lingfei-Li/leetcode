// Feature:
// depth of a tree

#include"mytest.h"


using namespace std;

void solve(TreeNode* u, int d, int& ans) {

    if(!u) {
        ans = max(ans, d);
        return;
    }
    solve(u->left, d+1, ans);
    solve(u->right, d+1, ans);
}


int maxDepth(TreeNode* root) {
    
    int ans = 0;
    solve(root, 0, ans);
    return ans;
            

}

int main() {
	srand(time(NULL));




    return 0;
}
