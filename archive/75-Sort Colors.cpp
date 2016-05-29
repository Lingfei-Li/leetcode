#include"mytest.cpp"


using namespace std;


void sortColors(vector<int>& nums) {
    if(nums.size() <= 1) return;
    int cnt[3];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < nums.size(); i ++) cnt[nums[i]] ++;
    int tmp = 0;
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < cnt[i]; j ++) nums[tmp++] = i;
    }
}


int main() {
	srand(time(NULL));


    string s;
    while(cin>>s) {
        vector<int> vec;
        genVector(vec, 10);
        printVector(vec);
        sortColors(vec);
        cout<<endl;
        printVector(vec);
    }



    return 0;
}
