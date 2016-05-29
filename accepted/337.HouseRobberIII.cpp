// dp in trees

#include"mytest.h"


// rob, norob
unordered_map<TreeNode*, int> norobmp;
unordered_map<TreeNode*, int> robmp;

int solve(TreeNode* u, int canrob) {
    if(!u) return 0;
    if(canrob && robmp.count(u)) return robmp[u];
    else if(!canrob && norobmp.count(u)) return norobmp[u];

    int a = u->val + solve(u->left, 0) + solve(u->right, 0);
    int b = solve(u->left, 1) + solve(u->right, 1);

    robmp[u] = max(a,b);
    norobmp[u] = b;

    if(canrob) return max(a,b);
    else return b;
}

int rob(TreeNode* root) {
    if(root == 0) return 0;


    return solve(root, 1);

                
}



int main() {
	srand(time(NULL));



    TreeNode* u = readTree();
    printTree(u);
    cout<<rob(u)<<endl;

    return 0;
}
