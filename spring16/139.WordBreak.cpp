// 45.49%
// Feature:
// dynamic programming
// rolling array

#include"mytest.h"


using namespace std;



bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.length();
    if(!n) return false;

//    vector<int> dp;
//    dp.resize(n+5);
    int dp[1500];
    dp[n] = 1;
    for(int i = n-1; i >= 0; i --) {
        dp[i] = 0;
        for(int j = i; j < n; j ++) {
            if(wordDict.count(s.substr(i, j-i+1))) {
                dp[i] = dp[j+1];
                if(dp[i]) break;
            }
        }
    }
    return dp[0];
}


int main() {
	srand(time(NULL));


    while(1) {
        string s, tmp;
        unordered_set<string> wordDict;
        cin>>s;
        if(s=="end") break;
        while(cin>>tmp && tmp != "end") {
            wordDict.insert(tmp);
        }

        cout<<wordBreak(s, wordDict)<<endl;
    }




    return 0;
}
