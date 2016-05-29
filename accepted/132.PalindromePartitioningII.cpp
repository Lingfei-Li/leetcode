// Note: slow implementation (27.34%)
// Feature:
// Avoiding repeating (palindrom checking)
// dynamic programming

#include"mytest.h"


using namespace std;





int solve(string& s, int l, vector<int>& dp) {
    unordered_set<int> st1, st2;
    int n = s.length();
    dp[n-1] = 0;
    dp[n] = -1;

    vector<vector<int> > isp;
    isp.resize(n+5);
    for(int i = 0; i < n+5; i ++) {
        isp[i].resize(n+5);
    }

    for(int k = 0; k < n; k ++) {
        for(int l = 0; l+k < n; l ++) {
            int r = l+k;
            if(k == 0) isp[l][l] = 1;
            else if(k == 1) {
                isp[l][r] = (s[l] == s[r]);
            }
            else {
                isp[l][r] = (s[l] == s[r]) && isp[l+1][r-1];
            }
        }
    }

    for(int i = n-2; i >= 0; i --) {
        for(int j = i; j < n; j ++) {
            if(isp[i][j]) {
                dp[i] = min(dp[i], dp[j+1]+1);
            }
        }
    }
    return dp[0];
}



int minCut(string s) {
    if(s.length() <= 1) return 0;
    vector<int> dp;
    int n = s.length();
    dp.resize(n+5);
    for(int i = 0; i < n+5; i ++) dp[i] = (1<<31)-1;

    return solve(s, 0, dp);

}

/*
bool ispalindrom(string& s, int l, int r){
    while(l<r) {
        if(s[l] != s[r]) {
            return false;
        }
        r--; l++;
    }
    return true;
}
*/

bool ispalindrom2(string& s, int l, int r) {
    while(l<r) {
        if(s[l] != s[r]) {
            return false;
        }
        r--; l++;
    }
    return true;
}
int solve2(string& s, int l, vector<int>& dp) {
    if(l == s.length()) return -1;   //base case
    if(dp[l] != (1<<31)-1) return dp[l];    //memo
    for(int i = l; i <= s.length(); i ++) {
        if(ispalindrom2(s, l, i)) {
            if(i == s.length()) dp[l] = -1;   //base case
            else
                dp[l] = min(dp[l], solve2(s, i+1, dp)+1); //transition
        }
    }
    return dp[l];
}
int minCut2(string s) {
    if(s.length() <= 1 || ispalindrom2(s, 0, s.length()-1)) return 0;
    vector<int> dp;
    int n = s.length();
    dp.resize(n+5);
    for(int i = 0; i < n+5; i ++) dp[i] = (1<<31)-1;

    return solve2(s, 0, dp);

}


int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) {
    cout<<minCut(s)<<endl;
    cout<<minCut2(s)<<endl;
    }


    return 0;
}
