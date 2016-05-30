#include"mytest.h"


using namespace std;


TreeNode* solve(vector<int>& pre, vector<int>& in, int pl, int pr, int il, int ir) {

    if(pl > pr) return NULL;
    
    TreeNode* node = new TreeNode(pre[pl]);
    printf("%d %d %d %d\n", pl, pr, il, ir);

    if(pl == pr) return node;

    for(int k = il; k <= ir; k ++) {
        if(in[k] == pre[pl]) {
            int len = k-il;
            node->left = solve(pre, in, pl+1, pl+len, il, k-1);
            node->right = solve(pre, in, pl+len+1, pr, k+1, ir);
            return node;
        }
    }
    return node;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0 || inorder.size() == 0) return NULL;
    return solve(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}

int main() {
	srand(time(NULL));

    vector<int> u, v;

    u.push_back(1);
    u.push_back(2);
    u.push_back(3);

    v.push_back(2);
    v.push_back(1);
    v.push_back(3);

    TreeNode* a = buildTree(u, v);
    cout<<a->val<<endl;



    return 0;
}
