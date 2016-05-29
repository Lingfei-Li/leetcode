// 14.69% 1st group
// dfs
// level information

#include"mytest.h"

void dfs(vector<int>& ans, TreeNode* u, int d, unordered_set<int>& st) {
    if(!u) return;
    if(!st.count(d)) {
        st.insert(d);
        ans.push_back(u->val); 
    }
    dfs(ans, u->right, d+1, st);
    dfs(ans, u->left, d+1, st);

}


vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    unordered_set<int> st;
    dfs(ans, root, 0, st);
    return ans;
}


int main() {
	srand(time(NULL));




    return 0;
}
