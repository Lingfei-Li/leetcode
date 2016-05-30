#include"mytest.h"


bool isop(char c) {
    switch(c) {
        case'+': case '-': case '*':
            return true;
    }
    return false;
}
bool isnum(char c) {
    if(c >= '0' && c <= '9') return true;
    return false;
}


int calc(char op, int a, int b) {
    switch(op) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
    }
    return -1;
}

map<pair<int,int>, vector<int> > mp;


vector<int> solve(vector<int> nums, vector<char> ops, int l, int r) {
    pair<int,int> p = pair<int,int>(l,r);
    if(mp.count(p)) return mp[p];

    if(l == r) {
        vector<int> tmp;
        tmp.push_back(nums[l]);
        mp[p] = tmp;
        return tmp;
    }

    vector<int> ans;
    for(int k = l; k < r; k ++) {
        vector<int> a = solve(nums, ops, l, k);
        vector<int> b = solve(nums, ops, k+1, r);
        for(int i = 0; i < a.size(); i ++) {
            for(int j = 0; j < b.size(); j ++) {
                int c = calc(ops[k], a[i], b[j]);
                ans.push_back(c);
            }
        }
    }

    mp[p] = ans;
    return ans;
}

vector<int> diffWaysToCompute_1(string input) {
    int n = input.length();
    vector<int> nums;
    vector<char> ops;
    
    for(int i = 0; i < n; i ++) {
        char ch = input[i];
        if(isop(ch)) {
            ops.push_back(ch);
        }
        else {
            nums.push_back(atoi(input.c_str()+i));
            while(isnum(input[i]) && i < n) i++;
            i--;
        }
    }
    //note: n changed
    n = nums.size();

    vector<int> ans;
    ans = solve(nums, ops, 0, n-1);
    printVector(ans);


    return ans;
}


vector<int> diffWaysToCompute(string input) {
    int n = input.length();
    vector<int> nums;
    vector<char> ops;
    
    for(int i = 0; i < n; i ++) {
        char ch = input[i];
        if(isop(ch)) {
            ops.push_back(ch);
        }
        else {
            nums.push_back(atoi(input.c_str()+i));
            while(isnum(input[i]) && i < n) i++;
            i--;
        }
    }
    //note: n changed
    n = nums.size();

    vector<vector<vector<int> > > dp;
    dp.resize(n+5);
    for(int i = 0; i < n; i ++) {
        dp[i].resize(n+5);
    }

    for(int k = 0; k < n; k ++) {
        for(int i = 0; i+k < n; i ++) {
            if(k == 0) {
                vector<int> tmp;
                tmp.push_back(nums[i]);
                dp[i][i] = tmp;
            }
            else {
                for(int j = i; j < i+k; j ++) {
                    vector<int>& a = dp[i][j];
                    vector<int>& b = dp[j+1][i+k];
                    for(int ii = 0; ii < a.size(); ii ++) {
                        for(int jj = 0; jj < b.size(); jj ++) {
                            int c = calc(ops[j], a[ii], b[jj]);
                            dp[i][i+k].push_back(c);
                        }
                    }
                }
            }
        }
    }

    return dp[0][n-1];
}

int main() {
	srand(time(NULL));

    string s;
    while( cin>>s){
    vector<int> ans = diffWaysToCompute(s);
    printVector(ans);
    }




    return 0;
}
