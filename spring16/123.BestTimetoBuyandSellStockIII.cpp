// Feature:
// "Scanning" method

#include"mytest.h"


using namespace std;

int maxProfit(vector<int>& prices) {

    int n = prices.size();
    if(n<=1) return 0;

    vector<int> p[2];
    p[0].resize(n+5);
    p[1].resize(n+5);

    int minP = prices[0];
    p[0][0] = 0;
    for(int i = 1; i < n; i ++) {
        p[0][i] = max(p[0][i-1], prices[i] - minP);
        minP = min(minP, prices[i]);
    }

    int maxP = prices[n-1];
    p[1][n-1] = 0;
    for(int i = n-2; i >= 0; i --) {
        p[1][i] = max(p[1][i+1], maxP - prices[i]);
        maxP = max(maxP, prices[i]);
    }

    maxP = 0;
    for(int i = 0; i < n; i ++) {
        maxP = max(maxP, max(p[0][i], p[1][i]));
        if(i!=n-1) maxP = max(maxP, p[0][i]+p[1][i+1]);
    }

    return maxP;


}


int main() {
	srand(time(NULL));



    vector<int> v;
    genVector(v, 4);
    printVector(v);
    cout<<maxProfit(v)<<endl;

    return 0;
}
