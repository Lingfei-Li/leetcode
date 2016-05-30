// Not 100% done. O(n) space - should achieve O(1)

#include"mytest.h"


using namespace std;


void traverse(vector<int>& nums, vector<TreeNode*>& nodes, TreeNode* root) {
    if(root == 0) return;
    if(root->left != NULL) {
        traverse(nums, nodes, root->left);
    }
    nums.push_back(root->val);
    nodes.push_back(root);
    if(root->right != NULL) {
        traverse(nums, nodes, root->right);
    }
}


void recoverTree(TreeNode* root) {
    vector<int> nums;
    vector<TreeNode*> nodes;

    traverse(nums, nodes, root);

    int i = 0;
    while(i != nums.size()) {
        int targ = -1;
        for(i = 0; i < nums.size(); i ++) {
            if((i != 0 && nums[i] < nums[i-1]) || (i != nums.size()-1 && nums[i] > nums[i+1]))  {
                if(targ == -1) targ = i;
                else {
                    swap(nodes[targ]->val, nodes[i]->val);
                    swap(nums[targ], nums[i]);
                    break;
                }
            }
        } 
    }

}


int main() {
	srand(time(NULL));

    TreeNode* u = new TreeNode(0);
    TreeNode* v = new TreeNode(1);
    u->left = v;
    recoverTree(u);



    return 0;
}
