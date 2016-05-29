// 0ms
// iterative tree traversal

#include"mytest.h"


using namespace std;


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;

    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode* u = s.top();
        s.pop();
        ans.push_back(u->val);
        if(u->right) s.push(u->right);
        if(u->left) s.push(u->left);
    }

    return ans;

}


int main() {
	srand(time(NULL));




    return 0;
}
