// slow
// BST

#include"mytest.h"

class Solution {
public:
    vector<int> solve(TreeNode* root, int& ans){
        vector<int> c;
        if(!root) return c;
        vector<int> a = solve(root->left, ans);
        vector<int> b = solve(root->right, ans);
        if(root->left == 0 && root->right == 0) {
            ans = max(ans, 1);
            c.push_back(1);
            c.push_back(root->val); //min of subtree
            c.push_back(root->val); //max of subtree
            return c;
        }
        else if(root->left == 0){
            if(b.size() == 0) return c;    //not BST
            if(root->val <= b[1]) {       //is BST
                ans = max(ans, b[0]+1);
                c.push_back(b[0] + 1);
                c.push_back(root->val); //min of subtree
                c.push_back(b[2]); //max of subtree
                return c;
            }
            return c;           //not BST
        }
        else if(root->right == 0){
            if(a.size() == 0) return c;
            if(root->val >= a[2]) {
                ans = max(ans, a[0]+1);
                c.push_back(a[0] + 1);
                c.push_back(a[1]);      //min of subtree
                c.push_back(root->val); //max of subtree
                return c;
            }
            return c;
        }
        else {
            if(a.size() == 0 || b.size() == 0) return c;
            if(root->val >= a[2] && root->val <= b[1]){
                ans = max(ans, a[0]+b[0]+1);
                c.push_back(a[0]+b[0] + 1);
                c.push_back(a[1]);      //min of subtree
                c.push_back(b[2]);      //max of subtree
                return c;
            }
            return c;
        }
    }

    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};


int main() {
	srand(time(NULL));

    TreeNode* t;
    t = readTree();
    printTree(t);


    Solution sol;
    cout<<sol.largestBSTSubtree(t)<<endl;



    return 0;
}
