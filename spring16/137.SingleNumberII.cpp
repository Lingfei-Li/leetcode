// Feature:
// hashmap
// Note: slow & spacy (O(n)) implementation
//  need to refine.

#include"mytest.h"


using namespace std;


int singleNumber(vector<int>& nums) {
    unordered_map<int,int> m;

    for(int i = 0; i < nums.size(); i ++) 
        m[nums[i]] += 1;

    for(int i = 0; i < nums.size(); i ++) 
        if(m[nums[i]] == 1) return nums[i];

    return 0;
}



int main() {
	srand(time(NULL));

    vector<int> v;
    readVectorInt(v);
    printVector(v);
    cout<<singleNumber(v)<<endl;



    return 0;
}
