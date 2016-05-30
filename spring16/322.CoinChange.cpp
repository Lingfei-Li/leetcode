// 85.21%
// dynamic programming
// arrays are (much) faster than vectors. 
// cpp supports variable-sized arrays

#include"mytest.h"

int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    int n = coins.size();
    int dp[amount+5];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[amount] = -1;
    for(int i = 0; i < amount; i ++) {
        if(i == 0 || dp[i] > 0) {
            for(int j = 0; j < n; j ++) {
                if(coins[j] <= 0) continue;
                int u = i+coins[j];
                if(u > amount) continue;
                if(dp[u] == 0 || dp[u] == -1){
                    dp[u] = dp[i] + 1;
                }
                else {
                    dp[u] = min(dp[u], dp[i] + 1);
                }
            }
        }
    }
    return dp[amount];
}



int main() {
	srand(time(NULL));

    vector<int> v;
    read(v);
    print(v);
    int a = 16;
    cout<<coinChange(v, a)<<endl;




    return 0;
}
