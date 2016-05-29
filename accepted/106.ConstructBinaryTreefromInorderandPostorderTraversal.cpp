// Note: slow implementation: 2.46%
// Feature:
// Construction of tree with inorder&postorder traversal

#include"mytest.h"


using namespace std;

TreeNode* solve(vector<int>& in, vector<int>& post, int inl, int inr, int pol, int por) {

    if(pol > por) return NULL;

    TreeNode* u = new TreeNode(post[por]);
    if(pol == por) return u;

    for(int i = inl; i <= inr; i ++) {
        if(in[i] == post[por]) {
            int len = inr - i;  //len of right child
            u->left = solve(in, post, inl, i-1, pol, por-1-len);
            u->right = solve(in, post, i+1, inr, por-len, por-1);
            break;
        }
    }
    return u;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            
    return solve(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);


} 


int main() {
	srand(time(NULL));




    return 0;
}
