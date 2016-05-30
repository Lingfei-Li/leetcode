// 37.6%
// ugly number
// A very interesting algorithm to find the n-th ugly number!

#include"mytest.h"


int nthUglyNumber(int n) {
    if(n <= 0) return 0;
    vector<long long> v;
    int ptr[3];
    ptr[0] = ptr[1] = ptr[2] = 1;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    while(v.size() < n) {
        long long u = min(v[ptr[0]]*2, v[ptr[1]]*3);
        u = min(u, v[ptr[2]]*5);
        if(u == v[ptr[0]]*2) {
            ptr[0] ++;
        }
        //don't use else if. all pointers must be updated
        if(u == v[ptr[1]]*3) {
            ptr[1] ++;
        }
        if(u == v[ptr[2]]*5) {
            ptr[2] ++;
        }
        if(u > v[v.size()-1]){ 
            v.push_back(u);
        }
    }
    return v[n-1];
}


int main() {
	srand(time(NULL));

    int a;
    while(cin>>a) cout<<nthUglyNumber(a)<<endl<<endl;



    return 0;
}
