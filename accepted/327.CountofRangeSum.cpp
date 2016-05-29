// Learned a lot.
// merge during counting, count during merge
// the definition and usage of prefix array
// the choice of start position of two pointers
// the update rule of two pointers
// what's the meaning of left and right boundary?

#include"mytest.h"

int mergeSort(vector<long long>& prefix, int l, int r, int lower, int upper) {
    //note: why return when <= 1?
    //what's the meaning of l and r?
    if(r - l <= 1) return 0;

    int m = (l+r)/2;
    int lcnt = mergeSort(prefix, l, m, lower, upper);
    int rcnt = mergeSort(prefix, m, r, lower, upper);

    int ans = 0;

    //note: start from m, not l
    int j = m, k = m, t = m;
    vector<long long> tmp;
    for(int i = l; i < m; i ++) {
        //note: increment of j and k
        while(j < r && prefix[j]-prefix[i] < lower) j ++;
        while(k < r && prefix[k]-prefix[i] <= upper) k ++;
        ans += k-j;

        //note: merge during counting
        while(t < r && prefix[t] < prefix[i]) tmp.push_back(prefix[t++]);
        tmp.push_back(prefix[i]);

    }

    for(int i = 0; i < tmp.size(); i ++) prefix[l+i] = tmp[i]; 

    return ans + lcnt + rcnt;

}


int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();

    vector<long long> prefix;
    //note: n+1
    //the definition of prefix array
    prefix.resize(n+1);
    for(int i = 0; i < n; i ++){
        prefix[i+1] = prefix[i] + nums[i];
    }

    //note: n+1
    return mergeSort(prefix, 0, n+1, lower, upper);
}



int main() {
	srand(time(NULL));

    int l, u;
    cin>>l>>u;
    vector<int> v;
    read(v);
    cout<<countRangeSum(v, l, u)<<endl;



    return 0;
}
