// 0ms
// OVERFLOW!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include"mytest.h"


vector<int> bad;
int isBadVersion(int v) {
    return bad[v-1];
}

int firstBadVersion(int n) {

    long long l = 0, r = n;       //range is 1..n. remember to +1!!

    int ans = -1;
    while(l<r) {
        printf("%d %d\n", l, r);
        long long m = (l+r)/2;
        if(isBadVersion(m+1)) {
            ans = m+1;
            r = m;
        }
        else {
            l = m+1;
        }
    }
    return ans;
}



int main() {
	srand(time(NULL));


//    int n = 2126753390, m = 1702766719;
    int n = 212675339, m = 170276671;
    for(int i = 0; i < n; i ++) {
        if(i < m) bad.push_back(0);
        else bad.push_back(1);
    }
//    printVector(bad);

    cout<<firstBadVersion(n)<<endl;


    return 0;
}
