// 36.70 1.5-th group
// brute force..

#include"mytest.h"

bool isHappy(int n) {
    
    unordered_set<int> st;

    while(1) {
        int m = 0;
        while(n) {
            m += (n%10)*(n%10);
            n /= 10;
        }
//        cout<<m<<endl;
        if(m==1) return true;
        if(st.count(m)) return false;
        st.insert(m);
        n = m;
    }
    cout<<"panic\n";
}



int main() {
	srand(time(NULL));

    int a;
    while(cin>>a) {
        cout<<isHappy(a)<<endl;
    }


    return 0;
}
