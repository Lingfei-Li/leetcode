// Feature:
// leaf node
// DFS

#include"mytest.h"


using namespace std;

bool hasPathSum(TreeNode* r, int sum) {

    if(!r) return false;
    if(!r->left && !r->right) return r->val == sum;


    return hasPathSum(r->left, sum-r->val) || hasPathSum(r->right, sum-r->val);

}



int main() {
	srand(time(NULL));




    return 0;
}
