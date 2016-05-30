// Feature:
// definition of BST

#include"mytest.h"


using namespace std;


TreeNode* solve(vector<int>& v, int l, int r) {
    if(l > r) return 0;
    int m = (l+r+1)/2;
    TreeNode* u = new TreeNode(v[m]);
    u->left = solve(v, l, m-1);
    u->right = solve(v, m+1, r);
    
    return u;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    return solve(nums, 0, n-1);
} 


int main() {
	srand(time(NULL));




    return 0;
}
