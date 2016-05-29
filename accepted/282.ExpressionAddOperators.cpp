// 1.12% slow (good job)
// DFS
// backtracking

#include"mytest.h"

void solve(vector<string>& ans, string& exp, int pos, string& num, long long target, int multiplyflag, long long multiplier) {

    int n = num.size();
    if(pos == -1) {
        if(target == 0) ans.push_back(exp);
        return;
    }
    for(int i = pos; i >= 0; i --) {
        if(i != pos && num[i] == '0') continue;

        long long tmp = atoi(num.substr(i, pos-i+1).c_str());
        long long val = tmp;
        if(multiplyflag) val *= multiplier;
        if(val < 0) break;  //overflow

        int oldsz = exp.length();

        exp += to_string(tmp);
        if(i) exp.push_back('+');
        solve(ans, exp, i-1, num, target-val, 0, 0);
        exp.resize(oldsz);

        if(i) {
            exp += to_string(tmp);
            exp.push_back('-');
            solve(ans, exp, i-1, num, target+val, 0, 0);
            exp.resize(oldsz);

            exp += to_string(tmp);
            exp.push_back('*');
            solve(ans, exp, i-1, num, target, 1, val);
            exp.resize(oldsz);
        }
    }

}

int isnum(char c){
    return c>='0' && c<='9';
}
vector<string> addOperators(string num, int target) {
    vector<string> intermediate;
    int n = num.length();
    string exp;
    solve(intermediate, exp, n-1, num, target, 0, 0);
    vector<string> ans;
    for(int i = 0; i < intermediate.size(); i ++) {
        exp.resize(0);
        int j = intermediate[i].length() - 1;
        int lastop = j+1;
        while(j >= 0) {
            while(j >= 0 && isnum(intermediate[i][j])) j--;
                exp += intermediate[i].substr(j+1,lastop-j-1);
                if(j>0) {
                    exp += intermediate[i][j];
                }
                lastop = j;
                j--;
        }
        ans.push_back(exp);
    }

    return ans;
}



int main() {
	srand(time(NULL));

    string a;
    int b;
    while(cin>>a>>b) {
        vector<string> ans = addOperators(a, b);
        printVector(ans);
    }




    return 0;
}
