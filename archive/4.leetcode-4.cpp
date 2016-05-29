#include<cstdio>
#include<cstring>
#include<algorithm>

#include<vector>

#include<queue>
#include<string>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<set>
#include<map>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;


//Global Variables.

////

#define min(x,y) (x<y)?x:y
int findkth(int* a, int n, int* b, int m, int k) {
    if(m>n) return findkth(b,m,a,n,k);
    if(m==0)return a[k-1];
    if(k==1) return min(a[0], b[0]);
    int j = min(m, k/2);
    int i = k-j;
    if(a[i-1] > b[j-1]) return findkth(a, n, b+j, m-j, k-j);
    return findkth(a+i, n-i, b, m, k-i);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums1Size+nums2Size;
    if((m)%2) {
        return findkth(nums1, nums1Size, nums2, nums2Size, m/2+1);
    }
    else {
        return (findkth(nums1, nums1Size, nums2, nums2Size, m/2) + findkth(nums1, nums1Size, nums2, nums2Size, m/2+1))/2.0;
    }
}

int main() {


    srand(time(NULL));

    int n = 10;
    int a[n], b[n];
    for(int i = 0; i < n; i ++) {
        a[i] = rand()%100;
        b[i] = rand()%100;
    }
    sort(a, a+n);
    sort(b, b+n);
    for(int i = 0; i < n; i ++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i ++) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    cout<<findMedianSortedArrays(a, n, b+1, n-1)<<endl;
    vector<int> v;
    for(int i = 0; i < n; i ++){
        v.push_back(a[i]);
        if(i<n-1) v.push_back(b[i+1]);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i ++) cout<<v[i]<<" ";
    cout<<endl;


    return 0;
}
