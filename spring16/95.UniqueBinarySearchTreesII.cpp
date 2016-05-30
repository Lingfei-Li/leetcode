#include"mytest.h"


using namespace std;


vector<TreeNode*> solve(int l, int r) {

    vector<TreeNode*> ans;
    if (l > r) {
        ans.push_back(NULL);
        return ans;
    }
    else if(l == r) {
        ans.push_back(new TreeNode(l));
        return ans;
    }

    for(int root = l; root <= r; root ++) {
    
        vector<TreeNode*> left = solve(l, root-1);
        vector<TreeNode*> right = solve(root+1, r);
        
        for(int i = 0; i < left.size(); i ++) {
            for(int j = 0; j < right.size();j ++) {
                TreeNode* u = new TreeNode(root);
                u->left = left[i];
                u->right = right[j];
                ans.push_back(u);
            }
        }

    }
    return ans;
}



vector<TreeNode*> generateTrees(int n) {

    vector<TreeNode*> v;
    if(!n) return v;
    return solve(1,n);
}


int main() {
	srand(time(NULL));


    int a;
    while(cin>>a);




    return 0;
}
