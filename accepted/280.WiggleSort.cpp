// slow
// sort
// array manipulation - in place

#include"mytest.h"
#include <ctype.h>


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int t = 0;
        for(int i = 0; i < n-1; i ++) {
            int idx = i;
            int val = nums[i];
            for(int j = i+1; j < n; j ++) {
                if(t && nums[j] > val || !t && nums[j] < val) {
                    val = nums[j];
                    idx = j;
                }
            }
//            printf("t=%d, swap %d %d (idx %d %d)\n", t, nums[i], nums[idx], i, idx);
            swap(nums[i], nums[idx]);
            t ^= 1;
//            print(nums);
        }
    }
};


int main() {
	srand(time(NULL));

    Solution sol;
    vector<int> v;
//    read(v);
    gen(v, 0);
    print(v);
    sol.wiggleSort(v);
    print(v);



    return 0;
}
