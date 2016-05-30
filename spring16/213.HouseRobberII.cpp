// 8.92% 0ms
// dynamic programming

#include"mytest.h"


int rob(vector<int>& nums) {
    
    int n = nums.size();

    if(!n) return 0;
    else if(n == 1) return nums[0];
    else if(n == 2) return max(nums[0], nums[1]);


    vector<int> dp[2];
    dp[0].resize(n);
    dp[1].resize(n);
    dp[0][0] = 0; dp[0][1] = nums[1];
    dp[1][0] = dp[1][1] = nums[0];
    for(int i = 2; i < n; i ++) {
        dp[0][i] = max(dp[0][i-2] + nums[i], dp[0][i-1]);
        dp[1][i] = max(dp[1][i-2] + nums[i], dp[1][i-1]);
    }
    return max(dp[0][n-1], dp[1][n-2]);
}


int main() {
	srand(time(NULL));
    
    vector<int> v;
    readVector(v);
    printVector(v);
    cout<<rob(v)<<endl;




    return 0;
}
