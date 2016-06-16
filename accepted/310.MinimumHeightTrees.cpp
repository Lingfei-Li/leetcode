#include"mytest.h"
#include<limits.h>
/*
class Solution {
public:

    vector<vector<int> > G;

    int dfs(int u, int p, int d) {
        if(p != -1 && G[u].size() == 1) return d;
        int maxd = d;
        for(auto it:G[u]){
            if(it != p){
                maxd = max(maxd, dfs(it, u, d+1));
            }
        }
        return maxd;
    }


    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        G.resize(n);
        for(auto it:edges){
            G[it.first].push_back(it.second);
            G[it.second].push_back(it.first);
        }

        unordered_map<int, vector<int> > dmp;
        int mind = INT_MAX;
        for(int i = 0; i < n; i ++) {
            int d = dfs(i, -1, 0);
//            printf("%d %d\n", i, d);
            mind = min(mind, d);
            dmp[d].push_back(i);
        }
        return dmp[mind];
    }
};
*/

class Solution {
public:

    vector<unordered_set<int> > G;

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        G.resize(n);
        for(auto it:edges){
            G[it.first].insert(it.second);
            G[it.second].insert(it.first);
        }

        vector<int> u;
        for(int i = 0; i < n; i ++){
            if(G[i].size() == 1){
                u.push_back(i);
            }
        }

        while(u.size()){
            vector<int> v;
            for(int i:u){
                for(int j:G[i]){
                    G[j].erase(i);
                    if(G[j].size() == 1) v.push_back(j);
                }
            }
            if(v.empty()){
                sort(u.begin(), u.end());
                return u;
            }
            u = v;
        }
        vector<int> default;
        default.push_back(0);
        return vector<int>();
    }
};


int main() {
	srand(time(NULL));

    int n;
    int a, b;
    cin>>n;
    vector<pair<int,int> > v;
    while(cin>>a>>b){
        v.push_back(pair<int,int>(a,b));
    }


    Solution sol;
    print(sol.findMinHeightTrees(n, v));



    return 0;
}
