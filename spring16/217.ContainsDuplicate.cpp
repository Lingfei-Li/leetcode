// 48.09% 3rd group
// hashset


#include"mytest.h"


bool containsDuplicate(vector<int>& nums) {
    if(nums.size() <= 1) return false;
    unordered_set<int> st;
    for(int i = 0; i < nums.size(); i ++) {
        if(st.count(nums[i])) return true;
        st.insert(nums[i]);
    }
    return false;
}



int main() {
	srand(time(NULL));




    return 0;
}
