// 45.07%
// prefix & postfix arrays

#include"mytest.h"

vector<int> productExceptSelf(vector<int>& nums) {

    int n = nums.size();
    vector<long long> p[2]; //prefix & postfix
    p[0].resize(n+5);
    p[1].resize(n+5);
    p[0][0] = nums[0];
    p[1][n-1] = nums[n-1];
    for(int i = 1; i < n; i ++) {
        p[0][i] = p[0][i-1]*nums[i];
        p[1][n-1-i] = p[1][n-1-i+1]*nums[n-1-i];
    }
//    printVector(p[0])
    vector<int> ans;
    ans.resize(n);
    for(int i = 0; i < n; i ++) {
        int a = (i==0)?1:p[0][i-1];
        int b = (i==n-1)?1:p[1][i+1];
        ans[i] = a*b;
    }
    return ans;
}



int main() {
	srand(time(NULL));

    vector<int> v;
    genVector(v,2,4);
    printVector(v);
    vector<int> ans = productExceptSelf(v);
    printVector(ans);




    return 0;
}
