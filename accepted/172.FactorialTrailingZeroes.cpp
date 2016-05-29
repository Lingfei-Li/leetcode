#include"mytest.h"


int countTwo(int n) {
    if(n<2) return 0;
    return n/2+countTwo(n/2);
}

int trailingZeroes(int n) {
    if(n<5) return 0;
    return n/5+trailingZeroes(n/5);
}



int main() {
	srand(time(NULL));
    int a;
    while(cin>>a){
        cout<<trailingZeroes(a)<<endl;
    }


    return 0;
}
