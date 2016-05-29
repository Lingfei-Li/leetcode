// 63% med
// interesting algorithms. worth further notice.
// merging
// max subarray according to some criteria

#include"mytest.h"

vector<int> singleMaxNum(vector<int>& v, int k){
    assert(k <= v.size());
    vector<int> ans;
    if(!k) return ans;
    ans.resize(k);
    int i = 0, j = 0;
    for(i = 0; i < v.size(); i ++) {
        while(j > 0 && v[i] > ans[j-1] && j-1+(v.size()-i) >= k) {
            j --;
        }
        if(j < k) ans[j++] = v[i];
    }
    return ans;
}

int gt(vector<int>& v1, int i, vector<int>& v2, int j){
    while(i < v1.size() && j < v2.size() && v1[i] == v2[j]) {
        i ++;
        j++;
    }
    return j == v2.size() || (i < v1.size() && v1[i] > v2[j]);
}


vector<int> merge(vector<int>& v1, vector<int>& v2) {
    int p1 = 0, p2 = 0;
    int n = v1.size(), m = v2.size();
    vector<int> ans;
    while(p1 < n || p2 < m) {
//        if(p1 >= n || (p2 < m && v1[p1] < v2[p2])) {
        if(p1 >= n || (p2 < m && gt(v2, p2, v1, p1))) {
            ans.push_back(v2[p2++]);
        }
        else{
            ans.push_back(v1[p1++]);
        }
    }
    return ans;
}

vector<int> maxNumber(vector<int>& v1, vector<int>& v2, int k) {
    int n = v1.size(), m = v2.size();
    vector<int> ans;
    for(int i = 0; i <= k; i ++) {
        if(i <= n && (k-i) <= m){
            vector<int> tmp1 = singleMaxNum(v1, i);
            vector<int> tmp2 = singleMaxNum(v2, k-i);
            vector<int> res = merge(tmp1, tmp2);
//            print(res);
            if(ans.size() == 0 || ans < res) ans = res;
        }
    }
    return ans;
}


int main() {
	srand(time(NULL));


    vector<int> v1, v2;
    read(v1);
    read(v2);
    print(v1);
    print(v2);
    int k;
    cin>>k;
    print(maxNumber(v1, v2, k));




    return 0;
}
