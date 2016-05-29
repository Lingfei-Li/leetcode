// 11.4% fastest
// binary search
// search method

#include"mytest.h"


int hIndex_v1(vector<int>& citations) {
    int n = citations.size();
    if(!n) return 0;
    if(n == 1) return citations[0]>0;
    vector<int> v;
    v.resize(n+10);

    for(int i = 0; i < n; i ++) {
        v[min(citations[i], n)] ++;
    }
    
    for(int i = n; i >= 0; i --) {
        v[i] = v[i+1]+v[i];
        if(v[i] >= i) return i;
    }

    return 0;
}

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size();
    if(n == 0) return 0;
    if(n == 1) return citations[0] > 0;

    int l = 0, r = n;
    int ans = 0;
    while(l<r) {
        int m = (l+r)/2;
        int cand = n-m;
        if(citations[m] >= cand) {
            ans = max(ans, cand);
            r = m;
        }
        else if(citations[m] < cand) {
            l = m+1;
        }
    }
    return ans;
}



int main() {
	srand(time(NULL));


    vector<int> h;
    readVector(h);
    printVector(h);
    cout<<hIndex(h)<<endl;
    return 0;



    for(int i = 0; i < 5; i ++) {
        vector<int> v;
        genVector(v, 10);
        cout<<hIndex(v)<<endl;
        sort(v.begin(), v.end());
        printVector(v);
    }




    return 0;
}
