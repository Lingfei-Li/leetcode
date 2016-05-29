//Feature:
//  The use of XOR to detect duplicaiton

#include"mytest.h"


using namespace std;


int singleNumber(vector<int>& nums) {
    int n = nums.size();

    int a = 0;

    for(int i = 0; i < n; i ++)  {
        a ^= nums[i];
    }
    return a;


}



int main() {
	srand(time(NULL));




    return 0;
}
