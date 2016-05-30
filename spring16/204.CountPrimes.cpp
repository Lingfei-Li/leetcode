// 60.13% 3rd -4th group
// math
// O(nloglogn) complexity for finding primes

#include"mytest.h"


int countPrimes(int n) {
    vector<int> notprime;
    notprime.resize(n+5);

    int ans = 0;    //1 is not a prime
    for(int i = 2; i < n; i ++){
        if(i < sqrt(n)) {
            if(!notprime[i]) {
                ans ++;
                for(int j = i; (long long)i*(long long)j < (long long)n; j ++) {
                    notprime[i*j] = 1;
                }
            }
        }
        else {
            if(!notprime[i]) ans ++;
        }
    }
    return ans;
}



int main() {
	srand(time(NULL));

    int a;
    while(cin>>a) cout<<countPrimes(a)<<endl;



    return 0;
}
