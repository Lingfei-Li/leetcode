// 7.5% 0ms
// dynamic programming

#include"mytest.h"


int rob(vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;
    if(n==1) return nums[0];;
    if(n==2) return max(nums[0], nums[1]);
    int dp[1500];
    dp[n-1] = nums[n-1];
    dp[n-2] = max(nums[n-1], nums[n-2]);

    for(int i = n-3; i >= 0; i --) {
        dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
    }
    return dp[0];
}


int main() {
	srand(time(NULL));

    vector<int> v;
    while(readVector(v)) {
        cout<<rob(v)<<endl;
    }





    return 0;
}
