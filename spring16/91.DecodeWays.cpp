// Feature:
// dynamic programming
// comprehensive special/corner cases handling

#include"mytest.h"


using namespace std;

int numDecodings(string s) {
    int n = s.length();
    if(n == 0) return 0;
    vector<int> dp;
    dp.resize(n+5);
    if(s[n-1] != '0') dp[n-1] = 1;
    dp[n] = 1;
    for(int i = n-2; i >= 0; i --) {
        char c = s[i];
        if(c == '1' || (c == '2' && s[i+1] <= '6'))
            dp[i] += dp[i+2]+dp[i+1];
        else if(c == '0')
            dp[i] = 0;
        else
            dp[i] = dp[i+1];
    }

    return dp[0];
}


int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) {
        cout<<numDecodings(s)<<endl;
    }



    return 0;
}
