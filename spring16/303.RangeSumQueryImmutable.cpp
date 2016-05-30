// 98.7%
// prefix array

#include"mytest.h"

/*
class NumArray {
private:
    vector<vector<int> > dp;
public:
    NumArray(vector<int> &v) {
        int n = v.size();
        dp.resize(n+5);
        for(int i = 0; i < n; i ++) {
            dp[i].resize(n+5);
        }
        for(int k = 0; k < n; k ++) {
            for(int i = 0; i+k < n; i ++) {
                if(k == 0) {
                    dp[i][i] = v[i];
                }
                else {
                    dp[i][i+k] = dp[i][i+k-1] + v[i+k];
                }
            }
        }
    }

    int sumRange(int i, int j) {
        return dp[i][j];
    }
};
*/


class NumArray {
private:
    vector<long long> prefix;
public:
    NumArray(vector<int> &v) {
        int n = v.size();
        prefix.resize(n+5);
        for(int i = 0; i < n; i ++) {
            prefix[i] = (i)?prefix[i-1]+v[i] : v[i];
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) return prefix[j];
        return prefix[j]-prefix[i-1];
    }
};

int main() {
	srand(time(NULL));

    vector<int> v;
    genVector(v, 10);
    printVector(v);
    NumArray a = NumArray(v);
    int n, m;
    while(cin>>n>>m) {
        cout<<a.sumRange(n, m)<<endl;
    }



    return 0;
}
