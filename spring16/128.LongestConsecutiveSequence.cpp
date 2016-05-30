#include"mytest.h"


using namespace std;


int longestConsecutive(vector<int>& nums) {


    unordered_set<int> s;
    int n = nums.size(), ans = 0;
    if(n<=1) return n;

    for(int i = 0; i < n; i ++) {
        s.insert(nums[i]);
    }
    
    for(int i = 0; i < n; i ++) {
        int a = nums[i];
        if(!s.count(a)) continue;

        s.erase(a);
        int cnt = 1;
        int j = 1;
        while(s.count(a-j)) {
            cnt ++;
            s.erase(a-j);
            j++;
        }

        j = 1;
        while(s.count(a+j)) {
            cnt ++;
            s.erase(a+j);
            j++;
        }
    
        ans = max(ans, cnt);
    }

        
    return ans;
}



int main() {
	srand(time(NULL));


    vector<int> v;
    while(1){
        readVectorInt(v);
        printVector(v);
        cout<<longestConsecutive(v)<<endl;
        v.clear();
    }
    return 0;
    genVector(v, 5);
    printVector(v);
    cout<<longestConsecutive(v)<<endl;


    return 0;
}
