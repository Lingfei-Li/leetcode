// 39.68% 1st group
// math
// find trends

#include"mytest.h"

int addDig(int num) {
    while(num >= 10) {
        int tmp = 0;
        while(num) {
            tmp+=num%10;
            num/=10;
        }
        num = tmp;
    }
    return num;
}

int addDigits(int num) {
    if(num == 0) return 0;
    return (num-1)%9+1;
}



int main() {
	srand(time(NULL));

    int n;
    while(cin>>n){
        cout<<addDig(n)<<" "<<addDigits(n)<<endl;
    }



    return 0;
}
