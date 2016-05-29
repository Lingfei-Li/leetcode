#include"mytest.cpp"


using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > ans;
    if(nums.size() < 4) return ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i ++) {
        if( i && nums[i] == nums[i-1]) continue;
//        if(nums[i] > target) break;
        for(int j = i+1; j < nums.size(); j ++) {
            if( j != i+1 && nums[j] == nums[j-1]) continue;
//            if(nums[i] + nums[j] > target) break;
            int left = j+1, right = nums.size()-1;
            while(left<right) {
                int a = nums[left];
                int b = nums[right];
                if(left != j+1 && a == nums[left-1]) {
                    left ++;
                    continue;
                }
                else if(right != nums.size()-1 && b == nums[right+1]) {
                    right --;
                    continue;
                }
                else {
                    if(a + b == target - nums[i] - nums[j]) {
                        vector<int> quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(a);
                        quad.push_back(b);
                        ans.push_back(quad);
                        right --;
                        left ++;
                    }
                    else {
                        if(a+b > target - nums[i] - nums[j]) {
                            right --;
                            continue;
                        }
                        else {
                            left ++;
                            continue;
                        }
                    }
                }
            }

//            for(int k = j+1; k < nums.size(); k ++) {
//                if( nums[k] == nums[k-1]) continue;
//                if(nums[i] + nums[j] + nums[k] > target) break;
//                int tmp = target - (nums[i] + nums[j] + nums[k]);
//                vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), tmp);
//                int pos = it-nums.begin();
//                if(pos > k && nums[pos] == tmp) {
//                    vector<int> quad;
//                    quad.push_back(nums[i]);
//                    quad.push_back(nums[j]);
//                    quad.push_back(nums[k]);
//                    quad.push_back(tmp);
//                    ans.push_back(quad);
//                }
//            }

        }
    }


    return ans;
}

int main() {
	srand(time(NULL));

    vector<int> vec;
//    genVector(vec, 10);

    int n;
    cin>>n;
    vec.resize(n);
    while(n--) scanf("%d", &vec[n]);
    sort(vec.begin(), vec.end());
    printVector(vec);

    int target;
    while(cin>>target) {
        vector<vector<int> > ans = fourSum(vec, target);
        for(int i = 0; i < ans.size(); i ++) {
            for(int j = 0; j < ans[i].size(); j ++) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
        printVector(vec);
    }




    return 0;
}
