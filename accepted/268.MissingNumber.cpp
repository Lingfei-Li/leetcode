// 77.9%
// binary searching the answer
// linear complexity with halving and linear scanning

#include"mytest.h"


int missingNumber_nlgn_constsp(vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;
    int l = 0, r = n+1;
    while(1){
        int m = (l+r)/2;
        int less = 0, greater = 0, flag = 1;
        for(int i = 0; i < n; i ++) {
            if(nums[i] < m) { less ++; }
            else if(nums[i] > m) { greater ++; }
            else { flag = 0; }
        }
        if(flag) return m;
        if(less < m) {
            r = m;
        }
        else if(greater < n-m) {
            l = m+1;
        }
        else {
            printf("?\n");
        }
    }
    return -1;
}


int missingNumber_linear_tmsp(vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;
    vector<int> vis;
    vis.resize(n+1);
    for(int i = 0; i < n; i ++) {
        vis[nums[i]] = 1;
    }
    for(int i = 0; i < n+1; i ++) {
        if(vis[i] == 0) return i;
    }
    return -1;
}


int missingNumber(vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;
    int flag = -1;
    for(int i = 0; i < n; i ++) {
        if(nums[i] == 0) {
            flag = i;
            break;
        }
    }
    if(flag == -1) return 0;

    nums[flag] = nums[0];

    for(int i = 1; i < n; i ++) {
        int tmp = abs(nums[i]);
        if(tmp < n) nums[tmp] = -nums[tmp];
    }
    for(int i = 1; i < n; i ++) {
        if(nums[i] > 0) return i;
    }
    return n;


}

int main() {
	srand(time(NULL));

    vector<int> v;
    read(v);
    print(v);
    cout<<missingNumber(v)<<endl;




    return 0;
}
