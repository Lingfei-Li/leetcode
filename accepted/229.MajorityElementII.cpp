// 29.17% 2nd group
// quickselect
// be careful about the parameters

#include"mytest.h"



//k-th smallest element
int quickselect(vector<int>& v, int l, int r, int k) {
    if(l == r) return v[l];

    int pivotIndex = (l+r)/2;
    int pivot = v[pivotIndex];
    int m = l, n = l, i = l;
    //v[m,n] is the elements == pivot
    swap(v[pivotIndex], v[i++]);
    while(i<=r) {
        if(v[i] == pivot) {
            swap(v[++n],v[i++]);
        }
        else if(v[i] < pivot) {
            swap(v[i], v[m++]);
            swap(v[i++], v[++n]);
        }
        else
            i++;
    }
    if(k < (n-l)) {
        return quickselect(v, l, n-1, k);
    }
    else if(k >= (n-l) && k <= m-l) {
        return pivot;
    }
    else {
        //mind the numbers!!!!!!
        return quickselect(v, m+1, r, k-(m+1-l));
    }
}


void solve(vector<int>& v, int l, int r, int len, vector<int>& ans) {
    if(l == r) {
        if(len == 1) ans.push_back(v[l]);
        return;
    }

    int pivIdx = (l+r)/2;
    int piv = v[pivIdx];
    int i, m, n;
    i = m = n = l;
    swap(v[pivIdx], v[i++]);
    while(i<=r) {
        if(v[i] < piv) {
            swap(v[i], v[m++]);
            swap(v[i++], v[++n]);
        }
        else if(v[i] == piv) {
            swap(v[i++],v[++n]);
        }
        else{
            i ++;
        }
    }

    if(n-m+1 >= len) {
        ans.push_back(piv);
    }
    if(m-l >= len) {
        solve(v, l, m-1, len, ans);
    }
    if(r-n >= len) {
        solve(v, n+1, r, len, ans);
    }
}



vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    if(nums.size() == 0) return ans;
    solve(nums, 0, nums.size()-1, nums.size()/3+1, ans);
    return ans;
}




int main() {
	srand(time(NULL));

    vector<int> v;
    readVector(v);
    printVector(v);
    vector<int> ans = majorityElement(v);
    printVector(ans);


    return 0;
}
