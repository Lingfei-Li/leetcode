#include"mytest.h"


using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n == 0) return;

    vector<int> v;
    for(int i = 0, j = 0; i < m || j < n;) {
        if(i >= m || (j < n && nums1[i] > nums2[j])) {
            v.push_back(nums2[j++]);
        }
        else {
            v.push_back(nums1[i++]);
        }
    }

    for(int i = 0; i < v.size(); i ++) {
        nums1[i] = v[i];
    }
    

}


int main() {
	srand(time(NULL));

    vector<int> u, v;
    genVector(u, 5);
    genVector(v,5);
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    printVector(u);
    printVector(v);
    u.resize(10);

    merge(u, 5, v,5);
    printVector(u);


    return 0;
}
