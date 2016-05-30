// 2ms
// when you don't have any clue, try some small numbers!

#include"mytest.h"


int integerBreak(int n) {
    if(n <= 3) return n-1;
//    long long prod = 1;
    int prod = 1;

    for(int i = 0; i < (n-1)/3-1; i ++) {
        prod *= 3;
    }

    if(n%3 == 1) {
        prod *= 2*2;
    }
    else if(n%3 == 2) {
        prod *= 2*3;
    }
    else {
        prod *= 3*3;
    }


    return prod;
}


int main() {
	srand(time(NULL));

    int a;
    while(cin>>a) cout<<integerBreak(a)<<endl;



    return 0;
}
