// 70% ok
// hashtable
// sliding window

#include"mytest.h"


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        if(n == 0 || k <= 0) return 0;
        int i = -1, j = 0;
        int cnt = 0;
        int ans = 0;
        int mp[200] = {0};
        while(j < n){
            mp[s[j]] ++;
            if(mp[s[j]] == 1) {
                cnt ++;
            }
            while(cnt > k) {
                i ++;
                mp[s[i]] --;
                if(mp[s[i]] == 0) cnt --;
            }
            ans = max(ans, j-i);

            j++;
        }
        return ans;
    }
};




int main() {
	srand(time(NULL));

    Solution sol;
    string s;
    int k;
    while(cin>>s>>k)
        cout<<sol.lengthOfLongestSubstringKDistinct(s,k)<<endl;

    return 0;
}
