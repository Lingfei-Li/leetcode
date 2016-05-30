// Feature:
// "Scanning" method

#include"mytest.h"


using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n<=1) return 0;
    int minPrice = prices[0];
    int p = 0;
    for(int i = 1; i < n; i ++) {
        p = max( p , prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return p;
}


int main() {
	srand(time(NULL));




    return 0;
}
