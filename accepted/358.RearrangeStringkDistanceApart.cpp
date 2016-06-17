#include"mytest.h"

class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k < 1) k = 1;
        map<char, int> occur;
        for(char c : str) occur[c] ++;
        priority_queue<pair<int,char> > q;
        for(auto it:occur) q.push(pair<int,char>(it.second, it.first));

        unordered_set<char> st;
        string ans;
        ans.resize(str.size());
        int len = 0;

        while(!q.empty()) {
            vector<pair<int, char> > tmp;
            while(true){
                if(q.empty()) return "";
                pair<int,char> p = q.top();
                q.pop();
                if(st.count(p.second)){
                    tmp.push_back(p);
                }
                else {
                    for(auto it : tmp){
                        q.push(it);
                    }
                    ans[len ++] = p.second;
                    st.insert(p.second);
                    if(len-k >= 0) st.erase(ans[len-k]);
                    p.first --;
                    if(p.first > 0){
                        q.push(p);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
	srand(time(NULL));

    Solution sol;

    string s;
    int a;
    while(cin>>s>>a)
        cout<<sol.rearrangeString(s, a)<<endl;



    return 0;
}
