// 25.2% 1st group
// greedy
// scanning

#include"mytest.h"

int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;

    int p1 = 0, p2 = 0;
    int sum = 0;
    int ans = n+1;
    while(p2<n) {
        sum += nums[p2++];
        while(sum >= s) {
            ans = min(ans, p2-p1);
            sum -= nums[p1++];
        }
    }
    return (ans>n)?0:ans;
}



int main() {
	srand(time(NULL));

    int a;
    cin>>a;
    vector<int> v;
    readVector(v);
    cout<<minSubArrayLen(a, v)<<endl;




    return 0;
}
