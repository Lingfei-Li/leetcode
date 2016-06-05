//graph: dfs/bfs

#include"mytest.h"


class Solution {
public:


    int countComponents(int n, vector<pair<int, int> >& edges) {
        if(!n) return 0;
        vector<vector<int> > G;
        G.resize(n+5);
        for(auto p:edges){
            G[p.first].push_back(p.second);
            G[p.second].push_back(p.first);
        }
        int ans = 0;
        int vis[n] = {0};
        for(int i = 0; i < n; i ++) {
            if(vis[i] == 0) {
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    for(auto j:G[v]){
                        if(vis[j] == 0){
                            q.push(j);
                        }
                    }
                    vis[v] = 1;
                }
                ans ++;
            }
        }
        return ans;
    }
};


int main() {
	srand(time(NULL));

    Solution sol;
    vector<pair<int,int> > edges;
    int n, a, b;
    cin>>n;
    while(cin>>a>>b){
        edges.push_back(pair<int,int>(a,b));
    }
    cout<<sol.countComponents(n, edges)<<endl;



    return 0;
}
