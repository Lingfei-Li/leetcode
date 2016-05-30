// 96.61% 2nd group
// backtracking
// DFS

#include"mytest.h"
/*
 * param:
 *  vector<pair<string,string> >&   tickets
 *  vector<int>&                    vis
 *  int                             cnt
 *  int                             pos
 *  unordered_map<string,int>&      startpos
 *  vector<string>&                 ans
 */
bool solve(vector<pair<string,string> >& tickets, vector<int>& vis, int cnt, int pos, unordered_map<string,int>& startpos, vector<string>& ans) {
    if(cnt == 0) {
        //no ticket left. succeeded
        ans.push_back(tickets[pos].second);
        return true;
    }

    int oldsz = ans.size();
    for(int i = startpos[tickets[pos].second]; i < tickets.size() && tickets[i].first == tickets[pos].second; i ++) {

        if(vis[i] == 1) continue;
        //searching for tickets that starts from tickets[pos].second
        vis[i] = 1;
        ans.push_back(tickets[i].first);

        if(solve(tickets, vis, cnt-1, i, startpos, ans)) return true;

        //backtracking
        ans.resize(oldsz);
        vis[i] = 0;
    }

    return false;
}


vector<string> findItinerary(vector<pair<string, string> > tickets) {
    int n = tickets.size();
    vector<string> ans;
    ans.push_back("JFK");

    vector<int> vis;
    if(!n) return ans;

    vis.resize(n+5);

    unordered_map<string, int> startpos;

    sort(tickets.begin(), tickets.end());

    for(int i = 0; i < n; i ++) {
        while(i && i < n && tickets[i].first == tickets[i-1].first) i++;
        if(i >= n) break;
        startpos[tickets[i].first] = i;
    }

    int start = startpos[string("JFK")];
    for(int i = start; i < tickets.size() && tickets[i].first == "JFK"; i ++) {
        vis[i] = 1;
        if(solve(tickets, vis, n-1, i, startpos, ans)) break;;
        vis[i] = 0;
    }
    return ans;
}



int main() {
	srand(time(NULL));

    vector<pair<string,string> > tickets;
    string a,b;
    while(cin>>a>>b) {
        tickets.push_back(pair<string,string>(a,b));
//        cout<<a<<" "<<b<<endl;
    }

    vector<string> ans = findItinerary(tickets);
    printVector(ans);



    return 0;
}
