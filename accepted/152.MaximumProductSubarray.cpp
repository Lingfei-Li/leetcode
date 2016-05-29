// 4.06% med
// dynamic programming
// sign - math

#include"mytest.h"


using namespace std;


int maxProduct(vector<int>& nums) {


    int n = nums.size();
    if(!n) return 0;
    vector<int> dp[2];
    dp[0].resize(n);
    dp[1].resize(n);

    int ans = 1<<31;
    for(int i = 0; i < n; i ++) {
        int& a = nums[i];
        if(!i) {
            if(a > 0) {
                dp[0][i] = a;
                dp[1][i] = 0;
            }
            else if(a < 0) { 
                dp[1][i] = a;
                dp[0][i] = 0;
            }
            else {
                dp[0][i] = dp[1][i] = 0;
            }
            ans = a;
            continue;
        }
        int posP = dp[0][i-1], negP = dp[1][i-1];
        if(a > 0) {
            if(posP>1) {
                dp[0][i] = posP*a;
            }
            else {
                dp[0][i] = a;
            }
            dp[1][i] = negP*a;
        }
        else if(a < 0){
            if(posP>1) {
                dp[1][i] = a*posP;
            }
            else {
                dp[1][i] = a;
            }
            dp[0][i] = a*negP;
        }
        else {
            dp[0][i] = dp[1][i] = 0;
        }
        printf("%d %d %d\n", i, dp[0][i], dp[1][i]);
        ans = max(ans, dp[0][i]);
    }
    return ans;
}



int main() {
	srand(time(NULL));

    vector<int> v;
    readVectorInt(v);
    cout<<maxProduct(v)<<endl;




    return 0;
}
