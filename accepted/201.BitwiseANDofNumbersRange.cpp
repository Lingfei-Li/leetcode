// 11.04% 1ac 2nd group-3rd group
// binary number properties

#include"mytest.h"

void printBin(int a) {
    for(int i = 0; i < 32 && a; i ++, a/=2) {
        printf("%d", a%2);
        if(!((i+1)%4)) printf(" ");
    }
    cout<<endl;
}

int rangeBitwiseAnd(int m, int n) {
    if(m==n) return m;

    int ans = 0;
    for(int k = 30; k >= 0; k --) {
        int mask = 1<<k;
        if(n&mask) {
//            printBin(mask);
//            printBin(m);
//            printBin(n);
//            cout<<endl;
            if(m&mask) {
                ans += mask;
                n -= mask;
                m -= mask;
            }
            else {
                return ans;
            }
        }
    }
    return ans;
}


int main() {
	srand(time(NULL));

    int m, n;
    while(cin>>m>>n) {
        cout<<rangeBitwiseAnd(m,n)<<endl;
    }



    return 0;
}
