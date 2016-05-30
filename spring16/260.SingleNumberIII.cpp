// 1.93% slow
// radix sort

#include"mytest.h"


void radixSort(vector<int>& v) {
    for(int k = 0; k < 32; k ++) {
        vector<int> tmp;
        for(int i = 0; i < v.size(); i ++) {
            if(!(v[i]&(1<<k))) {
                tmp.push_back(v[i]);
            }
        }
        for(int i = 0; i < v.size(); i ++) {
            if(v[i]&(1<<k)) {
                tmp.push_back(v[i]);
            }
        }
        v = tmp;
    }

}


vector<int> singleNumber(vector<int>& nums) {
    vector<int> ans;
    radixSort(nums);
//    printVector(nums);
    for(int i = 0; i < nums.size(); i ++) {
        if(i == nums.size()-1) 
            ans.push_back(nums[i]);
        else {
            if(nums[i] == nums[i+1]) i++;
            else {
                ans.push_back(nums[i]);
            }
        
        }
    }
    return ans;
                
}


int main() {
	srand(time(NULL));


    vector<int> v;
    readVector(v);
    printVector(v);
    vector<int> ans = singleNumber(v);
    printVector(ans);



    return 0;
}
