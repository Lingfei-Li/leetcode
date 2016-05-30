// Feature:
// level order traversal (and reversed order in some levels)

#include"mytest.h"


using namespace std;




void solve(vector<vector<int> >& ans, TreeNode* u, int d) {
    if(!u) return;
    if(ans.size() < d+1) ans.resize(d+1);
    ans[d].push_back(u->val);
    solve(ans, u->left, d+1);
    solve(ans, u->right, d+1);
}


vector<vector<int> > zigzagLevelOrder(TreeNode* root) {

    vector<vector<int> > ans;
    solve(ans, root, 0);

    for(int i = 1; i < ans.size(); i +=2) {
        for(int j = 0; j < ans[i].size()/2; j ++) {
            swap(ans[i][j], ans[i][ans[i].size()-1-j]);
        }
    }

    return ans;

} 


int main() {
	srand(time(NULL));




    return 0;
}
