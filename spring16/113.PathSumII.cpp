// Note: slow (31.25%)
// Feature:
// root-leaf sum
// DFS

#include"mytest.h"


using namespace std;

bool isleaf(TreeNode* u) {
    if(!u || u->left || u->right) return false;
   return true; 
}

void solve(TreeNode* u, vector<vector<int> >& ans, vector<int> v, int sum) {

    int initsz = v.size();
    if(!u) return;
    if(isleaf(u)) {
        if(u->val == sum) {
            v.push_back(u->val);
            ans.push_back(v);
            v.resize(initsz);
        }
        return;
    }

    if(u->left) {
        v.push_back(u->val);
        solve(u->left, ans, v, sum-u->val);
        v.resize(initsz);
    }
    if(u->right) {
        v.push_back(u->val);
        solve(u->right, ans, v, sum-u->val);
        v.resize(initsz);
    }
}

vector<vector<int> > pathSum(TreeNode* u, int sum) {
    vector<vector<int> > ans;
    vector<int> v;
    solve(u, ans, v, sum);

    return ans;
                
}


int main() {
	srand(time(NULL));




    return 0;
}
