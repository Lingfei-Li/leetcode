// slow 8.63%
// Dynamic programming (recording 'p') + backtracking (building answer)
// 139 + answer building

#include"mytest.h"


using namespace std;


void buildans(unordered_map<int, vector<int> >& p, int u, string& tmp, string& s, vector<string>& ans) {
    int n = s.length();
    if(u >= n){
        tmp.resize(tmp.length()-1);
        ans.push_back(tmp);
        return;
    }
    int initlen = tmp.length();
    vector<int>& v = p[u];
    for(int i = 0; i < v.size(); i ++) {
        tmp += s.substr(u, v[i]-u)+" ";
        buildans(p, v[i], tmp, s, ans);
        tmp.resize(initlen);
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {

    vector<string> ans;

    int n = s.length();
    if(!n) return ans;
    unordered_map<int, vector<int> > p;

    vector<int> dp;
    dp.resize(n+5);
    dp[n] = 1;
    for(int i = n-1; i >= 0; i --) {
        vector<int> tmp;
        dp[i] = 0;
        for(int j = i; j < n; j ++) {
            if(wordDict.count(s.substr(i, j-i+1))) {
                if(dp[j+1]) {
                    tmp.push_back(j+1);
                    dp[i] = 1;
                }
            }
        }
        p[i] = tmp;
    }
    string tmp;
    buildans(p, 0, tmp, s, ans);

    return ans;

}


int main() {
	srand(time(NULL));


    while(1) {
        string s, tmp;
        unordered_set<string> wordDict;
        cin>>s;
        if(s=="-") break;
        while(cin>>tmp && tmp != "-") {
            wordDict.insert(tmp);
        }

        vector<string> ans = wordBreak(s, wordDict);
        for(int i = 0; i < ans.size(); i ++) {
            cout<<ans[i]<<endl;
        }
        cout<<endl;
    }




    return 0;
}
