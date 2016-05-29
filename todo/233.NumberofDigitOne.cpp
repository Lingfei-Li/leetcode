#include"mytest.h"


long long pow10[15];
long long num[15];


int solve(int n) {
    int tmp = n;
    int k = 0;      //number of digits
    while(tmp) {
        k ++;
        tmp/=10;
    }
    int mask = pow10[k-1];
    int p = n/mask;

    if(k == 0) return 0;
    if(k == 1) return n>=1;
    int ans;
    if(p>1) {
        ans = pow10[k-1]+p*num[k-1];

        n -= mask;
        ans += countDigitOne(n);
    }
    else {
        ans += (n-mask+1);
        ans += solve(n-mask);
    }

    return ans;

}


int countDigitOne(int n) {
    long long b = 1;
    pow10[0] = 1;
    for(int i = 0; i < 10; i ++) {
        b *= 10;
        pow10[i+1] = b;
    }
    int ans = 0;
    num[0] = 0;
    num[1] = 1;
    for(int k = 2; k < 15; k ++) {
        num[k] = 10*num[k-1]+pow10[k-1];
    }

    solve(n);

                
    return ans;
}


int main() {
	srand(time(NULL));

    int a;
    while(cin>>a)
    countDigitOne(a);



    return 0;
}
