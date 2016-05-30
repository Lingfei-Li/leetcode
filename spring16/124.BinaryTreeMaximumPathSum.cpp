// Feature:
// reversable path of a tree

#include"mytest.h"


using namespace std;

bool isleaf(TreeNode* u) {
    if(!u->left && !u->right) return true;
    return false;
}

//return max single-path
int solve(TreeNode* u, int& ans) {
    if(!u) return 0;


    int val = u->val;

    int left = solve(u->left, ans); 
    int right = solve(u->right, ans); 

    int doublepath = left+right+val;
    int singlepath = max(max(left, right)+val, val);
    ans = max(ans, max(singlepath, doublepath));
    return singlepath;
}

int maxPathSum(TreeNode* u) {
    int int_min = 1<<31;
    int ans = int_min;    //int_min

    solve(u, ans);

    return ans;

}

int main() {
	srand(time(NULL));

    TreeNode* u = readTree();
    printTree(u);
    cout<<maxPathSum(u)<<endl;


    return 0;
}
