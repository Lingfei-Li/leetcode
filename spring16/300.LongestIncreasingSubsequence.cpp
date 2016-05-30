// 18.19% 
// dynamic programming
// can use binary search to speed up

#include"mytest.h"

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;
    vector<int> dp;
    dp.resize(n);

    int ans = 1;
    for(int i = 0; i < n; i ++) {
        dp[i] = 1;
        for(int j = 0; j < i; j ++) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}



int main() {
	srand(time(NULL));

    vector<int> v;
    readVector(v);
//    genVector(v,5);
    printVector(v);
    cout<<lengthOfLIS(v)<<endl;



    return 0;
}
