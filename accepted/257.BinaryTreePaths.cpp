// 9.95% fastest
// Tree
// Leaf! Leaf! Leaf!

#include"mytest.h"


bool isleaf(TreeNode* u) {
    if(u && !u->left && !u->right) return true;
    return false;
}

void solve(TreeNode* u, vector<string>& ans, string curPath) {
    if(!u) return;
    if(isleaf(u)) {
        curPath += to_string(u->val);
        ans.push_back(curPath);
        return;
    }

    curPath += to_string(u->val)+"->";
    solve(u->left, ans, curPath);
    solve(u->right, ans, curPath);
}


vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string s;
    solve(root, ans, s);

    return ans;
}



int main() {
	srand(time(NULL));

    TreeNode* u = readTree();
    printTree(u);
    vector<string> ans = binaryTreePaths(u);
    printVector(ans);



    return 0;
}
