#include"mytest.cpp"


using namespace std;


int climbStairs(int n) {
    if(!n) return 0;
    if(n == 1) return 1;
    vector<int> dp;
    dp.resize(n);
    dp[n-1] = 1;
    dp[n-2] = 2;
    for(int i = n-3; i >= 0; i --) {
        dp[i] = dp[i+1] + dp[i+2];
    }
    return dp[0];
}


int main() {
	srand(time(NULL));

    int n;
    while(cin>>n) {
        cout<<climbStairs(n)<<endl;
    }
    return 0;
}
