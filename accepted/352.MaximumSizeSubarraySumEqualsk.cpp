#include"mytest.h"

class Solution {
public:
    int maxSubArrayLen(vector<int>& v, int k) {
        int n = v.size();
        if(!n) return 0;

        unordered_map<int,int> mp;


        int sum[n+5] = {0};
        mp[0] = 0;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            sum[i+1] = sum[i] + v[i];
            int minus = sum[i+1] - k;
            if(mp.count(minus)) {
                ans = max(ans, i+1-mp[minus]);
            }
            if(!mp.count(sum[i+1])){
                mp[sum[i+1]] = i+1;
            }
        }
        return ans;
    }
};

int main() {
	srand(time(NULL));

    Solution sol;
    vector<int> v;
    int k;
    while(cin>>k){
        read(v);
        print(v);

        cout<<sol.maxSubArrayLen(v, k)<<endl;
    }




    return 0;
}
