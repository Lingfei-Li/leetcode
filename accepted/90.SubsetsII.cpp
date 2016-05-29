// Feature:
// backtracking for generating subsets
// remove duplicate: if previous one is the same, don't ignore
// current one, because ignoring will give duplicate. think.

#include"mytest.h"


using namespace std;


void genSubset(vector<int>& nums, vector<vector<int> >& ans, vector<int>& subset, int pos) {

    int n = nums.size(), m = subset.size();
    if(pos >= n) {
        ans.push_back(subset);
        return;
    }

    if(m > 0 && subset[m-1] == nums[pos]) {
        subset.push_back(nums[pos]);
        genSubset(nums, ans, subset, pos+1);
        subset.resize(m);
    }
    else {
        genSubset(nums, ans, subset, pos+1);
        subset.push_back(nums[pos]);
        genSubset(nums, ans, subset, pos+1);
        subset.resize(m);
    }
}



vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    vector<vector<int> > ans;

    sort(nums.begin(), nums.end());

//    printVector(nums);
    vector<int> subset;
    genSubset(nums, ans, subset, 0);


    return ans;

}


int main() {
	srand(time(NULL));

    vector<int> v;
    genVector(v,3);


    vector<vector<int> > ans;
    ans = subsetsWithDup(v);
    for(int i = 0; i < ans.size(); i ++) {
        for(int j = 0; j < ans[i].size(); j ++) {
            printf("%d ", ans[i][j]);
        }
        cout<<endl;
    }


    return 0;
}
