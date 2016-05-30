// 21.39% ok
// scanning
// (counting sort)

#include"mytest.h"



void moveZeroes(vector<int>& nums) {
    int cnt = 0;
    int n = nums.size();
    int ptr = 0;
    for(int i = 0; i < n; i ++) {
        if(nums[i] != 0) nums[ptr++] = nums[i];
        else cnt ++;
    }
    for(int i = n-cnt; i < n; i ++) {
        nums[i] = 0;
    }
}


int main() {
	srand(time(NULL));

    vector<int> v;
    read(v);
    print(v);
    moveZeroes(v);
    print(v);




    return 0;
}
