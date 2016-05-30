// 13.68%
// iterative tree traversal

#include"mytest.h"


using namespace std;

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;

    stack<TreeNode*> s;
    stack<int> tmp;
    s.push(root);
    while(!s.empty()) {
        TreeNode* u = s.top();
        s.pop();
        ans.push_back(u->val);
        if(u->left) s.push(u->left);
        if(u->right) s.push(u->right);
    }

    int len = ans.size();
    for(int i = 0; i < len/2; i ++) {
        swap(ans[i], ans[len-1-i]);
    }

    return ans;
                
}


int main() {
	srand(time(NULL));




    return 0;
}
