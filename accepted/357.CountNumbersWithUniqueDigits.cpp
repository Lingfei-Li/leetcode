// combanatorics

#include"mytest.h"

class Solution {
public:
    long long perm(int a, int b){
        long long res = 1;
        for(int i = 0; i < a; i ++) {
            res *= (b-i);
        }
        return res;
    
    }
    int countNumbersWithUniqueDigits(int n) {
        if(!n) return 1;
        int ans = 0;
        int dp[n+5] = {0};

        for(int i = 0; i <= n; i ++) {
            if(i == 1) dp[i] = perm(i, 10);
            else dp[i] = perm(i, 10) - perm(i-1, 9);
            ans += dp[i];
        }

        return ans;
    }
};


int main() {
	srand(time(NULL));

    Solution sol;
    int a, b;

    while(cin>>a)
        cout<<sol.countNumbersWithUniqueDigits(a)<<endl;


    return 0;
}
