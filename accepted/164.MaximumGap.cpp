// 6.75% slow med
// radix sort

#include"mytest.h"


void radixSort(vector<int>& v) {
    int n = v.size();
    vector<int> u;
    u.resize(n);
    for(int k = 0; k < 32; k ++) {
        int ptr = 0;
        int mask = 1<<k;
        for(int i = 0; i < n; i ++) {
            if(v[i]&mask) {
                u[ptr++] = v[i];
            }
        }
        for(int i = 0; i < n; i ++) {
            int mask = 1<<k;
            if(!(v[i]&mask)) {
                u[ptr++] = v[i];
            }
        }
        for(int i = 0; i < n; i ++) {
            v[i] = u[i];
        }
    }

}

int maximumGap(vector<int>& v){
    int n = v.size();
    if(n<2) return 0; 
    radixSort(v);
//    printVector(v);

    int ans = 0;
    for(int i = 0; i < v.size()-1; i ++) {
        ans = max(ans, v[i]-v[i+1]);
    }
    return ans;
}

int main() {
	srand(time(NULL));
    int slow_maximumGap(vector<int>& nums);
    int med_maximumGap(vector<int>& nums);



    for(int i = 0; i < 1000; i ++) {
        vector<int> v;
        genVector(v, 10);
        int a = maximumGap(v); 
        int b = med_maximumGap(v);
        if(a!=b) {
            printVector(v);
        }
            cout<<a<<" "<<b<<endl;
    }






    return 0;
}

int med_maximumGap(vector<int>& v) {
    if(v.size()<2) return 0;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < v.size()-1; i ++) {
        ans = max(ans, v[i+1]-v[i]);
    }
    return ans;
}



int slow_maximumGap(vector<int>& nums) {
    int ans = 0, n = nums.size();
    if(n<2) return 0;
    for(int i = 0; i < n; i ++)  {
        for(int j = 0; j < n; j ++) {
            if(nums[j] > nums[i]) {
                ans = max(ans, nums[j]-nums[i]);
            }
        }
    }
    return ans;
}
