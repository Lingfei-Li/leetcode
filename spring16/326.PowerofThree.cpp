// 62% med
// trick, trick....

#include"mytest.h"


void printbin(int a){
    while(a){
        cout<<a%2;
        a/=2;
    }
    cout<<endl;

}

bool isPowerOfThree(int n) {

    return n > 0 && 1162261467%n == 0;


    long long a = 1;
    while(a<n){
        a*=3;
        cout<<a<<endl;
    }
    return a==n;
}



int main() {
	srand(time(NULL));


    int a = 1;
    for(int i = 0; i < 10; i ++) {
        printbin(a);
        a*=3;
//        cout<<isPowerOfThree(a)<<endl;
//        cout<<isPowerOfThree(a+1)<<endl;
    
    }
    cout<<endl;

    cout<<isPowerOfThree(-3)<<endl;


    return 0;
}
