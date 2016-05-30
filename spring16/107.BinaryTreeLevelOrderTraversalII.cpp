// Feature:
// level-order traversal


#include"mytest.h"


using namespace std;


void solve(TreeNode* u, int d, vector<vector<int> >& ans) {
    if(!u) return;
    if(ans.size() < d+1) ans.resize(d+1);
    ans[d].push_back(u->val);
    solve(u->left, d+1, ans);
    solve(u->right, d+1, ans);


}


vector<vector<int> > levelOrderBottom(TreeNode* root) {
    vector<vector<int> > tmp, ans;
    solve(root, 0, tmp);
    ans.resize(tmp.size());
    for(int i = 0; i < tmp.size(); i ++) {
        ans[i] = tmp[tmp.size()-1-i];
    }

    return ans;

}  


int main() {
	srand(time(NULL));




    return 0;
}
