// Feature:
// The definition of BST
// Dynamic programming

#include"mytest.h"


using namespace std;


int numTrees(int n) {

    vector<int> dp;
    dp.resize(n+5);

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i ++) {
        for(int k = 1; k <= i; k ++) {
            dp[i] += dp[k-1]*dp[i-k];
        }
    }



    return (n)?dp[n]:0;

}



int main() {
	srand(time(NULL));

    int a;
    while(cin>>a){
        cout<<a<<endl;
        cout<<numTrees(a)<<endl;
    }


    return 0;
}
