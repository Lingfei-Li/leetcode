// Feature:
// what's the depth of a tree?

#include"mytest.h"


using namespace std;


/*
int minDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;

    int a = 1<<30, b = 1<<30;
    if(root->left) a = minDepth(root->left);
    if(root->right) b = minDepth(root->right);
    return min(a,b)+1;
}
*/
/*
int minDepth(TreeNode* r) {
    if(!r) return 0;
    int ans = 1<<30;
    stack<pair<TreeNode*,int> > s;
    s.push(pair<TreeNode*,int>(r, 1));
    while(!s.empty()) {
        pair<TreeNode*,int> p = s.top();  s.pop();
        TreeNode* u = p.first;
        if(!u->left && !u->right) ans = min(ans, p.second);
        else {
            if(u->left) s.push(pair<TreeNode*,int>(u->left, p.second+1));
            if(u->right) s.push(pair<TreeNode*,int>(u->right, p.second+1));
        }
    }
    return ans;

}
*/


int minDepth(TreeNode* r) {
    if(!r) return 0;
    TreeNode* s1[5000];
    int s2[5000];
    int ptr = 0, cnt = 0;

    s1[cnt] = r;
    s2[cnt] = 1;
    cnt ++;
    while(ptr < cnt) {
        TreeNode* u = s1[ptr];
        int d = s2[ptr];
        ptr ++;
        if(!u->left && !u->right) {
            return d;
        }
        else {
            if(u->left) {
                s1[cnt] = u->left;
                s2[cnt] = d+1;
                cnt ++;
            }
            if(u->right) {
                s1[cnt] = u->right;
                s2[cnt] = d+1;
                cnt ++;
            }
        }
    }
    return 0;
}



int main() {
	srand(time(NULL));




    return 0;
}
