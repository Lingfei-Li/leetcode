// 42.77% med
// hashmap

#include"mytest.h"


int majorityElement(vector<int>& nums) {
    int n = nums.size();
    if(n<=2) return nums[0];

    unordered_map<int,int> mp;
//    map<int,int> mp;

    for(int i = 0; i < n; i ++) {
        int a = nums[i];
        if(++mp[a] > n/2) return a;
    }
    return nums[0];
}



int main() {
	srand(time(NULL));






    return 0;
}
