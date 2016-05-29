#include"mytest.cpp"


using namespace std;

void genSubsets(vector<int>& nums, int pos, vector<int>& subset, vector<vector<int> >& ans) {
    if(pos == nums.size()) {
            ans.push_back(subset);
            return;
    }
    int initsize = subset.size();
    subset.push_back(nums[pos]);
    genSubsets(nums, pos+1, subset, ans);
    subset.resize(initsize);
    genSubsets(nums, pos+1, subset, ans);
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    if(nums.empty()) return ans;
    sort(nums.begin(), nums.end());
    vector<int> dummy;
    genSubsets(nums, 0, dummy, ans);
    return ans;
}


int main() {
	srand(time(NULL));


    int s;
    vector<int> nums;
    while(cin>>s) {
        if(s>=0) {
            nums.push_back(s);
        }
        else {
            vector<vector<int> > ans = subsets(nums);
            for(int i = 0; i < ans.size(); i ++) {
                for(int j = 0; j < ans[i].size(); j ++) {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
            nums.clear();
        }
    }





    return 0;
}
