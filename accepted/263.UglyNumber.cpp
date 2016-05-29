// 69.82% 1.5-th group
// nothing..........
// definition of ugly number, maybe
// range (validality) of input?

#include"mytest.h"

bool isUgly(int num) {
    if(num <= 0) return false;
    while(num!=1) {
        if(num%2 == 0) {
            num/=2;
            continue;
        }
        if(num%5 == 0) {
            num/=5;
            continue;
        }
        if(num%3 == 0) {
            num/=3;
            continue;
        }
        return false;
    }
    return true;
}



int main() {
	srand(time(NULL));


    int a;
    while(cin>>a) cout<<isUgly(a)<<endl;



    return 0;
}
