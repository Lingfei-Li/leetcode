// 87.79% 2nd group
// greedy
// scanning (maintain information along path)
// only last occurence of each number is important

#include"mytest.h"

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int n = nums.size();
    if(n<=1) return false; 
    for(int i = 0; i < n; i ++) {
        if(mp.count(nums[i])) {
            if(i-mp[nums[i]] <= k) return true;
        }
        mp[nums[i]] = i;
    }
    return false;
}


int main() {
	srand(time(NULL));


    vector<int> v;
    genVector(v, 10);
    printVector(v);
    int k;
    while(cin>>k)
    cout<<containsNearbyDuplicate(v, k)<<endl;




    return 0;
}
