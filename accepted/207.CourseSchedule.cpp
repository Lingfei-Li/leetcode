// 72.02% 2nd group
// dfs
// topology (loop checking)

#include"mytest.h"

bool dfs(vector<int>& vis, int u, vector<vector<int> >& G) {
    if(vis[u] == 1) return true;
    for(int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i];
        if(vis[v] == -1) return false;  //loop
        if(vis[v] == 1) continue;   //checked
        vis[v] = -1;
        if(!dfs(vis, v, G)) return false;
    }
    vis[u] = 1;
    return true;
}


bool canFinish(int n, vector<pair<int, int> >& prerequisites) {
    if(!n) return true;
    if(prerequisites.size() <= 1) return true;
    vector<vector<int> > G;
    G.resize(n);
    for(int i = 0; i < prerequisites.size(); i ++) {
        int u = prerequisites[i].first, v = prerequisites[i].second;
        G[u].push_back(v);
    }

    vector<int> vis;
    vis.resize(n);
    for(int i = 0; i < n; i ++) {
        if(vis[i] == 0){
            if(dfs(vis, i, G) == false) return false;
        }
    }

    return true;

}



int main() {
	srand(time(NULL));


    int n = 5;
    vector<pair<int,int> > req;
    req.push_back(pair<int,int>(0,1));
    req.push_back(pair<int,int>(1,2));
    req.push_back(pair<int,int>(2,3));
    cout<<canFinish(n, req)<<endl;



    return 0;
}
