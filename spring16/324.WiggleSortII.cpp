// 71.43%
// Radix sort
// Even/odd patterns

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
//    print(v);
}

void wiggleSort(vector<int>& nums) {
    radixSort(nums);
//    print(nums);
//    sort(nums.begin(), nums.end(), cmp);
//    print(nums);
    vector<int> tmp;
    int n = nums.size();
    tmp.resize(n);
    /*
//    if(n%2) {
        int i = 0, j = 0;
        //odd number of nums
        for(; j < n; i ++) {
            tmp[j] = nums[i];
            j += 2;
        }
        for(j = 1; j < n; i ++) {
            tmp[j] = nums[i];
            j += 2;
        }
    */
//    }
//    else {
        int i = n-1, j = 1;
        for(; j < n; i --) {
            tmp[j] = nums[i];
            j += 2;
        }
        for(j = 0; j < n; i --) {
            tmp[j] = nums[i];
            j += 2;
        }
        
//    }
    nums = tmp;
}


int main() {
	srand(time(NULL));

    vector<int> v;
    read(v);
//    genVector(v,5,20);
//    for(int i = 0; i < v.size(); i ++) {
//        v[i] -= 10;
//    }
//    print(v);
    wiggleSort(v);
    print(v);



    return 0;
}
