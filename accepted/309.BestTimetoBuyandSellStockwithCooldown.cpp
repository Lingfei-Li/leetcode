// 1.72% slow
// dynamic programming

#include"mytest.h"


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(!n) return 0;
    vector<int> dp;
    dp.resize(n+5);

    // dp[i]: max profit starting from i 
    for(int i = n-2; i >= 0; i --){
        int minp = prices[i];           //buy at min of price[i,j)
        for(int j = i+1; j < n; j ++) { //sell at j
            int tmpprofit = max(0,prices[j]-minp);
            dp[i] = max(dp[i], tmpprofit + dp[j+2]);
            minp = min(minp, prices[j]);
        }
    }
    return dp[0];
}



int main() {
	srand(time(NULL));

    vector<int> v;
//    genVector(v,10000);
    read(v);
    print(v);
    cout<<maxProfit(v)<<endl;



    return 0;
}
