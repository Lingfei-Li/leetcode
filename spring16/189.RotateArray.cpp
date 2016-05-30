#include"mytest.h"

// v1. 20.55% 2nd group
void rotate_v1(vector<int>& nums, int k) {
    int n = nums.size();
    if(!n || k <= 0) return;
    vector<int> tmp;
    tmp.resize(n);

    for(int i = 0; i < n; i ++) {
        tmp[(i+k)%n] = nums[i];
    }

    for(int i = 0; i < n; i ++) {
        nums[i] = tmp[i];
    }

}

// v2. 20.55% 2nd group
void rotate_v2(vector<int>& nums, int k) {
    int n = nums.size();
    if(!n || k <= 0) return;
    vector<int> tmp;
    k %= n;
    tmp.insert(tmp.begin(), nums.begin(), nums.begin()+(n-k));
    tmp.insert(tmp.begin(), nums.begin()+(n-k), nums.end());
    printVector(tmp);
    nums = tmp;
}

// v3. same speed...
void rotate_v3(vector<int>& nums, int k) {
    int n = nums.size();
    if(!n || k <= 0) return;
    vector<int> tmp;
    k %= n;
    nums.insert(nums.end(), nums.begin(), nums.begin()+n-k);
    nums.erase(nums.begin(), nums.begin()+n-k);
}


// v4. TLE...........................
void rotate_v4(vector<int>& nums, int k) {
    int n = nums.size();
    for(int j = 0; j < k%n; j ++) {
        int tmp = nums[j];
        for(int i = 1; i <= n; i ++) {
            int p = (i+j)%n;
            swap(tmp, nums[p]);
        }
    }
}


// v5. comes from the book "programming pearls"
// use your hands to simulate this
void rotate(vector<int>& v, int k) {
    int n = v.size();

    k = k%n;
    int pivot = (k+1)/2;
    for(int i = 0; i < pivot; i ++) swap(v[i], v[pivot+1-i]);
    for(int i = 0; i < (n-1-pivot)/2; i ++) swap(v[i+pivot+2], v[n-1-i]);
//    for(int i = pivot; i < (n-pivot)/2; i ++) swap(v[i], v[n-1-(i-pivot)]);
    for(int i = 0; i < n/2; i ++) swap(v[i], v[n-1-i]);

}


int main() {
	srand(time(NULL));
    

    vector<int> v;
    for(int i = 0; i < 2; i ++) {
        v.push_back(i+1);
    }
    printVector(v);
    rotate(v,1);
    printVector(v);



    return 0;
}
