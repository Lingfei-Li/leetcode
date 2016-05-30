// 10.05% slow
// stack, greedy...exactly as the tag says
// sort of like the monotonic queue

#include"mytest.h"

string removeDuplicateLetters(string s) {
    int n = s.length();
    if(!n) return s;

    stack<char> stk;
    unordered_map<char, int> cnt;
    int distinctCnt = 0;
    for(int i = 0; i < n; i ++) {
        if(cnt[s[i]] == 0) distinctCnt ++;
        cnt[s[i]] ++;
    }

    unordered_set<char> st;
    for(int i = 0; i < n; i ++) {
        if(st.count(s[i])) {
            cnt[s[i]] --;
            continue;
        }
        while(!stk.empty() && cnt[stk.top()] > 1 && stk.top() >= s[i] ){
            cnt[stk.top()] --;
            st.erase(stk.top());
            stk.pop();
        }
        stk.push(s[i]);
        st.insert(s[i]);
    }
    string ans;
    ans.resize(distinctCnt);
    int p = distinctCnt-1;
    while(!stk.empty()) {
        ans[p--] = stk.top();
        stk.pop();
    }

    return ans;
                
}



int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) cout<<removeDuplicateLetters(s)<<endl;



    return 0;
}
