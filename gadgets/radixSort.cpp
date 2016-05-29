#include"mytest.h"

int getmax(vector<int>& v) {
    int ans = 1<<31;
    for(int i = 0; i < v.size(); i ++) ans = max(ans, v[i]);
    return ans;
}

void countSort(vector<int>& v, int mask) {
    int cnt[10] = {0};
    for(int i = 0; i < v.size(); i ++) {
        int digit = (v[i]/mask)%10;
        cnt[digit] ++;
    }

    for(int i = 1; i < 10; i ++) {
        cnt[i] += cnt[i-1];
    }

    vector<int> tmp;
    tmp.resize(v.size());
    for(int i = v.size()-1; i >= 0; i --) {
        int digit = (v[i]/mask)%10;

        tmp[--cnt[digit]] = v[i];
    }

    v = tmp;
}


void radixSort(vector<int>& v) {
    int maxNum = getmax(v);
    int mask = 1;
    while(maxNum / mask) {
        countSort(v,mask);
        mask *= 10;
    }
    print(v);
}



int main() {
	srand(time(NULL));


    vector<int> v;
    genVector(v,10,100);
    print(v);
    radixSort(v);
    print(v);



    return 0;
}
