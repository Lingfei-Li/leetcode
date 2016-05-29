#include"mytest.h"




bool isPowerOfTwo_1(int n) {
    if(n<=0) return false;
    int flag = 0;
    int mask = 1;
    for(int i = 0; i < 31; i ++, mask<<=1) {
        if(mask & n) {
            if(!flag) flag = 1;
            else return false;
        }
    }
    return true;
}


bool isPowerOfTwo(int n) {
    if(n<=0) return false;

    int a[35] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

    int l = 0, r = 32;
    while(l<r) {
        int m = (l+r)/2;
        if(a[m] == n) return true;
        else if(a[m] > n) {
            r = m;
        }
        else {
            l = m+1;
        }
    }
    return false;
}

int main() {
	srand(time(NULL));

    int a;
    while(cin>>a)cout<<isPowerOfTwo(a)<<endl;




    return 0;
}
