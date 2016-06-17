#include"mytest.h"


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        int n = envelopes.size();
        priority_queue<pair<int,int> > q[2];
        int t = 0;
        for(auto it : envelopes) q[t].push_back(it);

        int ans = 0;
        while(!q[t].empty()) {
            int d = 1;
            pair<int,int> u = q[t].top();
            q[t].pop();
            while(!q[t].empty()) {
                pair<int,int> v = q[t].top();
                q[t].pop();

                if(v.first < u.first && v.second < v.second){
                    d ++;
                }
                else {
                    q[t^1].push(v);
                }
            }
            t ^= 1;
            ans = max(ans, d);
        }
        return ans;
    }

    int maxEnvelopes_n2(vector<pair<int, int> >& envelopes) {
        int n = envelopes.size();
        vector<int> dp;
        dp.resize(n);

        sort(envelopes.begin(), envelopes.end());

        int ans = 0;
        for(int i = n-1; i >= 0; i --) {
            pair<int,int>& u = envelopes[i];
            int d = 1;
            for(int j = i+1; j < n; j ++) {
                pair<int,int>& v = envelopes[j];
                if(v.first > u.first && v.second > u.second){
                    d = max(d, 1+dp[j]);
                }
            }
            dp[i] = d;
            ans = max(ans, d);
        }
        return ans;
    }
};

int main() {
	srand(time(NULL));

    Solution sol;
    int a, b;
    vector<pair<int,int> > v;
    while(cin>>a>>b)
        v.push_back(pair<int,int>(a,b));
    cout<<sol.maxEnvelopes(v)<<endl;



    return 0;
}
