// Feature:
// Recursion
// Comprehensive analysis of all conditions

#include"mytest.h"


using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == 0 && q == 0) return true;
    if((p == 0 && q != 0) || (p != 0 && q == 0)) return false;
    if(p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);


}


int main() {
	srand(time(NULL));




    return 0;
}
