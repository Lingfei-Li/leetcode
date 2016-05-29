// 90.57%
// k pointers
// ugly number

#include"mytest.h"


int nthSuperUglyNumber(int n, vector<int>& primes) {
    int k = primes.size();
    vector<int> ptr;
    ptr.resize(k);
    vector<long long> uglyNum;
    uglyNum.push_back(1);

    for(int i = 0; i < n; i ++) {
        long long tmp[k+1];
        long long minN = (1<<31)-1;

        for(int j = 0; j < k; j ++) {
            tmp[j] = primes[j]*uglyNum[ptr[j]];
            minN = min(minN, tmp[j]);
        }
        for(int j = 0; j < k; j ++) {
            if(tmp[j] == minN) {
                ptr[j] ++;
            }
        }
        uglyNum.push_back(minN);
    }
    return (int)uglyNum[n-1];
}



int main() {
	srand(time(NULL));

    int n;
    cin>>n;
    vector<int> v;
    read(v);
    cout<<nthSuperUglyNumber(n, v);




    return 0;
}
