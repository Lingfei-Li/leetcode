#include"mytest.h"

void printbin(int a) {
    while(a){
        cout<<a%2;
        a/=2;
    }
    cout<<endl;
}



bool isPowerOfFour(int num) {
    uint a = 0x55555555;
    return ((num&(num-1)) == 0) && (a&num);
            
}


int main() {
	srand(time(NULL));

    int a;
    while(cin>>a)
        cout<<isPowerOfFour(a)<<endl;



    return 0;
}
