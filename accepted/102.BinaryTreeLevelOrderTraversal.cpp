// Feature:
// level-order traverse of a tree...

#include"mytest.h"


using namespace std;



void solve(vector<vector<int> >& ans, TreeNode* u, int d) {
    if(!u) return;
    if(ans.size() < d+1) ans.resize(d+1);
    ans[d].push_back(u->val);
    solve(ans, u->left, d+1);
    solve(ans, u->right, d+1);
}

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > ans;
    solve(ans, root, 0);
    return ans;
}


int main() {
	srand(time(NULL));




    return 0;
}
