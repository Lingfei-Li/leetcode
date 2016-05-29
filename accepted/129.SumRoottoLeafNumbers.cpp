// Feature:
// Property of "Root-to-leaf"

#include"mytest.h"


using namespace std;

bool isleaf(TreeNode* u) {
    if(!u->left && !u->right) return true;
    return false;
}

void solve(TreeNode* u, int sum, int& ans) {
    if(!u) return;
    sum *= 10;
    sum += u->val; 
    if(isleaf(u)) {
        ans += sum;
        return;
    }
    solve(u->left, sum, ans);
    solve(u->right, sum, ans);
}

int sumNumbers(TreeNode* u) {
    int ans = 0;
    solve(u, 0, ans);
    return ans;
}

int main() {
	srand(time(NULL));




    return 0;
}
