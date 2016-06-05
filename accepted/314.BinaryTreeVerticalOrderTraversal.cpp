// map, graph(tree)

#include"mytest.h"

class Solution {
public:
    void solve(TreeNode* u, int pos, int d, map<int, map<int, vector<int> > >& mp) {
        if(!u) return;

        if(!mp.count(pos)) {
            map<int, vector<int> > m;
            mp[pos] = m;
        }
        if(!mp[pos].count(d)){
            vector<int> v;
            mp[pos][d] = v;
        }

        mp[pos][d].push_back(u->val);

//        mp[pos].push_back(pair<pair<int,int>,int>(pair<int,int>(d, pos), u->val));

        if(u->left)
            solve(u->left, pos-1, d+1, mp);
        if(u->right)
            solve(u->right, pos+1, d+1, mp);

    }
    vector<vector<int> > verticalOrder(TreeNode* root) {
        map<int, map<int, vector<int> > > mp;

        solve(root, 0, 0, mp);

        vector<vector<int> > ans;

        for(auto it:mp){
            map<int, vector<int> >& m = it.second;
            vector<int> tmp;
            for(auto it2:m){
                vector<int>& v = it2.second;
                for(auto it3:v){
                    tmp.push_back(it3);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};




int main() {
	srand(time(NULL));

    TreeNode* u = readTree();
    printTree(u);

    Solution sol;
    vector<vector<int> > ans = sol.verticalOrder(u);
    for(auto v: ans) {
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
    }



    return 0;
}
