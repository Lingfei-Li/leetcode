#include"mytest.h"


// 0.先trim
// 1.如果到i已经平衡了，则不能从i以前去掉'（'，但是可以去掉'）'
// 2.不能从第一个去掉（，不能从最后一个去掉）


void solve(string& s, int pos, int cnt, vector<string>& ans){
    if(pos == s.length()) {
    

        return;
    }
    char c = s[pos];
    if(c == '(') {
        cnt ++;
    }
    else if(c == ')'){
        if(cnt == 0){
            //something wrong

        }
        else {
            cnt--;
        }
    }
    else {
    
    }


}


vector<string> removeInvalidParentheses(string s) {
    int n = s.length();
    vector<int> rem;
    rem.resize(n);
    int i = 0;
    while(i < n && s[i] == ')') rem[i++] = 1;
    i = n-1;
    while(i >= 0&& s[i] == '(') rem[i--] = 1;
            
}



int main() {
	srand(time(NULL));




    return 0;
}
