// 11.06% slow
// counting inversions (upgraded)
// mergesort

#include"mytest.h"

struct node {
    int val;
    int cnt;
    int index;
    node(int a, int b, int c):val(a), cnt(b), index(c){}
};

void print(vector<node>& v){
    for(int i = 0; i < v.size(); i ++) {
        printf("%d %d %d\n", v[i].val, v[i].cnt, v[i].index);
    }
    cout<<endl;
}

static bool cmpVal(const node& a, const node& b) {
    return a.val< b.val;
}

static bool cmpIndex(const node& a, const node& b) {
    return a.index < b.index;
}
void mergeSort(vector<node>& v, int l, int r) {
    if(l == r) return;
    int m = (l+r)/2;
    mergeSort(v, l, m);
    mergeSort(v, m+1, r);

    int i = l, j = m+1;
    vector<node> tmp;
    int cnt = 0;
    while(i <= m && j <= r) {
        if(v[i].val <= v[j].val) {
            v[i].cnt += cnt;
            tmp.push_back(v[i]);
            i ++;
        }
        else {
            cnt ++;
            tmp.push_back(v[j]);
            j ++;
        }
    }
    while(i <= m) {
        v[i].cnt += cnt;
        tmp.push_back(v[i]);
        i ++;
    }
    while(j <= r) {
        tmp.push_back(v[j]);
        j ++;
    }

    for(int i = l, j = 0; i <= r ; i ++, j ++) {
        v[i] = tmp[j];
    }
}


vector<int> countSmaller(vector<int>& nums) {
    vector<int> ans;
    if(nums.size() == 0) return ans;
    vector<node> v;
    for(int i = 0; i < nums.size(); i ++) {
        v.push_back(node(nums[i], 0, i));
    }
    mergeSort(v, 0, nums.size()-1);

    sort(v.begin(), v.end(), cmpIndex);

    for(int i = 0; i < v.size(); i ++) ans.push_back(v[i].cnt);
    return ans;


                
}



int main() {
	srand(time(NULL));
    vector<int> v;
    genVector(v,100);
//    read(v);
    print(v);
    print(countSmaller(v));




    return 0;
}
