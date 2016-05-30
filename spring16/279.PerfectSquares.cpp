// 4.49%
// dynamic programming

#include"mytest.h"


int numSquares(int n) {
    vector<int> d;
    d.resize(n+5);
    vector<int> sqr;
    for(int i = 1; i*i<=n; i ++) {
        if(i*i == n) return 1;
        d[i*i] = 1;
        sqr.push_back(i*i);
    }

    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j < sqr.size(); j ++) {
            if(sqr[j] >= i) break;
            int tmp = d[i-sqr[j]]+1;
            if(d[i] == 0)
                d[i] = tmp;
            else
                d[i] = min(d[i], tmp);
        }
    }

    return d[n];
}



int main() {
	srand(time(NULL));

    cout<<(1<<31)-1<<endl;

    int n;
    while(cin>>n)
        cout<<numSquares(n)<<endl;




    return 0;
}
