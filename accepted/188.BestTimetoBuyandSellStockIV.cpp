// 21.44% 2nd group med
// dynamic programming
// optimization. reduce overlapping calculations

#include"mytest.h"


int maxProfit_correct(int k, vector<int>& prices) {
    vector<int> dp[2];
    int t = 0, n = prices.size();
    dp[0].resize(n+5);
    dp[1].resize(n+5);

    for(int p = 1; p <= k; p ++) {
        t ^= 1;
        dp[t].clear();
        for(int i = 0; i < n; i ++) {
            int tmp = 0;
            for(int j = 0; j < i; j ++) {
                tmp = max(tmp, dp[t^1][j]+prices[i]-prices[j]);
            }
            dp[t][i] = max(dp[t][i-1], tmp);
        }
    }

    return dp[t][n-1];
}

int maxProfit(int k, vector<int>& prices) {
    int t = 0, n = prices.size();
    if(n<=1 || !k) return 0;
    
    if(k >= n/2+1) {
        int ans = 0;
        for(int i = 1; i < n; i ++) {
            if(prices[i] > prices[i-1]) {
                ans += prices[i]-prices[i-1];
            }
        }
//        return ans;
        cout<<ans<<endl;
    }

    vector<int> dp[2];
    dp[0].resize(n+5);
    dp[1].resize(n+5);


    vector<int> tmp;
    tmp.resize(n+5);
    int change = 0;
    for(int p = 0; p < min(k,n/2+1); p ++) {
        t^=1;
//        dp[t].clear();
//        tmp.clear();
        for(int j = 0; j < n; j ++) {
            tmp[j] = dp[t^1][j]-prices[j];
            if(j) tmp[j] = max(tmp[j-1], tmp[j]);
        }

        for(int i = 0; i < n; i ++) {
            dp[t][i] = max(dp[t][i-1], prices[i]+tmp[i]);
        }
    }

    return dp[t][n-1];
}

int main() {
	srand(time(NULL));


    vector<int> v;
    genVector(v,2);
//    printVector(v);
    cout<<maxProfit(1, v)<<endl;
//    cout<<maxProfit_n(100000000, v)<<endl;
//    cout<<maxProfit_correct(0, v)<<endl;



    return 0;
}
