// 30.76%
// Scanning, with binary search tree to maintain information
// multiset

#include"mytest.h"

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    //k: index diff
    //t: value diff

    if(nums.size() <= 1) return false;
    if(k == 0) return false;

    multiset<int> bst;
    for(int i = 0; i < nums.size(); i ++) {
        auto it = bst.lower_bound(nums[i]-t);
        if(it!=bst.end() && abs(*it-nums[i]) <= t) return true;
        bst.insert(nums[i]);
        if(bst.size() > k) {
            bst.erase(nums[i-k]);
        }
    }
            
    return false;
}



int main() {
	srand(time(NULL));

    int k, t;
    cin>>k>>t;
    vector<int> v;
    readVector(v);
    cout<<containsNearbyAlmostDuplicate(v, k, t)<<endl;




    return 0;
}
