// 85.73% 1.5-th group
// topo graph

#include"mytest.h"



bool dfs(int n, vector<vector<int> >& G, vector<int>& ans, vector<int>& vis, int u) {

    for(int i = 0; i < G[u].size(); i ++) {
        if(vis[G[u][i]] == -1) return false;
        if(vis[G[u][i]] == 0) {
            vis[G[u][i]] = -1;
            if(dfs(n, G, ans, vis, G[u][i]) == false) return false;
        }
    }
    ans.push_back(u);

    vis[u] = 1;
    return true;
}



vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {


    vector<int> ans, vis;
    int n = numCourses;
    if(!n) return ans;
    vector<vector<int> > G;
    G.resize(n);
    for(int i = 0; i < prerequisites.size(); i ++) {
        G[prerequisites[i].first].push_back(prerequisites[i].second);
    }

    vis.resize(n+5);
    for(int i = 0; i < n; i ++) {
        if(!vis[i]) {
            if(dfs(n, G, ans, vis, i) == false) return vector<int>();
        }
    }
    return ans;

}


int main() {
	srand(time(NULL));


    int n = 0;
    vector<pair<int,int> > req;
//    req.push_back(pair<int,int>(1,0));
//    req.push_back(pair<int,int>(0,2));
//    req.push_back(pair<int,int>(0,2));
//    req.push_back(pair<int,int>(2,0));
//    req.push_back(pair<int,int>(3,1));
//    req.push_back(pair<int,int>(3,2));
//    req.push_back(pair<int,int>(2,3));
    vector<int> ans = findOrder(n, req);
    printVector(ans);



    return 0;
}
