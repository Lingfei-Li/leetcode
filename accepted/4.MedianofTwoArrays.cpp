#include"mytest.h"

#define min(x,y) (x<y)?x:y


int findkth(int* v1, int sz1, int* v2, int sz2, int k){
    if(sz1 < sz2)
        return findkth(v2, sz2, v1, sz1, k);

//    assert(sz1 >= sz2);

    if(sz2 == 0) return v1[k-1];
    if(k == 1) return min(v1[0], v2[0]);

    int j = min(sz2, k/2);
    int i = k-j;

    if(v1[i-1] < v2[j-1])
        return findkth(v1+i, sz1-i, v2, sz2, k-i);
    return findkth(v1, sz1, v2+j, sz2-j, k-j);

}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums1Size + nums2Size;
    if(m==0) return 0;
    if(m%2) {
        return findkth(nums1, nums1Size, nums2, nums2Size, m/2+1);
    }
    return (findkth(nums1, nums1Size, nums2, nums2Size, m/2) + 
            findkth(nums1, nums1Size, nums2, nums2Size, m/2+1)) / 2.0;
}


int main() {
	srand(time(NULL));

    int n = 0, m = 4;
    int a[n], b[m];
    genArray(a, n);
    genArray(b, m);
    sort(a, a+n);
    sort(b, b+m);
    printArray(a, n);
    printArray(b, m);


    int c[n+m];
    int p = 0, p1 = 0, p2 = 0;
    while(p1 < n || p2 < m){
        if(p1 >= n || (p2 < m && b[p2] < a[p1]))
            c[p++] = b[p2++];
        else
            c[p++] = a[p1++];
    }
    printArray(c, n+m);
//    cout<<c[n]<<endl;

    cout<<findMedianSortedArrays(a, n, b, m)<<endl;



    return 0;
}
