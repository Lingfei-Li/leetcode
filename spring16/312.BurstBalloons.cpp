// 8.37% slow (but speed close to med)
// dynamic programming
// divide and conquer
// for all that combines left&right: try D&C.

#include"mytest.h"

vector<vector<int> > dp;

int solve(vector<int>& nums, int l, int r, int lb, int rb) {
    if(l>=r) return 0;
    if(l == r-1) return lb*nums[l]*rb;

    if(dp[l][r]) return dp[l][r];
    int a, b, c;
    int ans = 0;
    for(int k = l; k < r; k ++) {
        a = solve(nums, l, k, lb, nums[k]);
        b = lb*nums[k]*rb;
        c = solve(nums, k+1, r, nums[k], rb);
        ans = max(ans, a+b+c);
    }
    return dp[l][r] = ans;
}


int maxCoins(vector<int>& nums) {
    int n = nums.size();
    if(n==0)return 0;
    dp.resize(n+5);
    for(int i = 0; i < n+5; i ++) {
        dp[i].resize(n+5);
    }

    return solve(nums, 0, n, 1, 1);
                        
}



int main() {
	srand(time(NULL));

    vector<int> v;
//    gen(v, 10);
    read(v);
    print(v);
    cout<<maxCoins(v)<<endl;




    return 0;
}
