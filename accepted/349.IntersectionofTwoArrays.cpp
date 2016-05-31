// med

#include"mytest.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> ansst;
        unordered_set<int> st;
        for(auto it:nums1){
            st.insert(it);
        }
        for(auto it:nums2){
            if(st.count(it)) ansst.insert(it);
        }

        for(auto it:ansst){
            ans.push_back(it);
        }
        return ans;
    }
};



int main() {
	srand(time(NULL));

    Solution sol;
    vector<int> v1, v2;
    gen(v1,10);
    gen(v2,5);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    print(v1);
    print(v2);
    print(sol.intersection(v1, v2));



    return 0;
}
