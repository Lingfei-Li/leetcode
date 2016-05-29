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

#define maxn 100000
#define hash_size 200000
int head[hash_size], next[maxn], cnt, st[maxn][2];

int hash_code(int a) {
    if(a<0) a = a+100000000;
    return a%hash_size;
}

int try_to_insert(int idx) {
    int hcode = hash_code(st[idx][0]+st[idx][1]), a = st[idx][0], b = st[idx][1];
    int h = head[hcode], u = h;
    while(u>0) {
        if(st[u][0] == a && st[u][1] == b) return 0;
        u = next[u];
    }
    next[idx] = head[hcode];
    head[hcode] = idx;
    return 1;
}

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > ans;
    if(nums.empty() || nums.size() < 4) return ans;

    memset(head, 0, sizeof(head));
    memset(next, 0, sizeof(next));
    cnt = 1;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size()-1; i ++) {
        if(i && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j < nums.size(); j ++) {
            if(j!=i+1 && nums[j] == nums[j-1]) continue;
            int a = nums[i], b = nums[j];
            st[cnt][0] = a, st[cnt][1] = b;
            if(try_to_insert(cnt)) cnt++;
        }
    }

    for(int i = 0; i < nums.size()-1; i ++) {
        if(i && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j < nums.size(); j ++) {
            if(j!=i+1 && nums[j] == nums[j-1]) continue;
            int a = nums[i], b = nums[j];
            int sum = target-(a+b);
            int hashcode = hash_code(sum);
            int h = head[hashcode];
            while(h) {          //search in hash table.
                if(st[h][0]+st[h][1] == sum) {
                    if(st[h][0] > b || st[h][0] == nums[j+1]){
                        vector<int> tmp;
                        tmp.push_back(a);
                        tmp.push_back(b);
                        tmp.push_back(st[h][0]);
                        tmp.push_back(st[h][1]);
                        ans.push_back(tmp);
                    }
                }
                h = next[h];
            }
        }
    }
    return ans;
}


int main() {

    srand(time(NULL));

    vector<int> v;
//    int rng = 20;
//    for(int i = 0; i < 100; i ++) v.push_back(rand()%rng-rng/2);
//    sort(v.begin(), v.end());
//    for(int i = 0; i < 100; i ++) cout<<v[i]<<" ";
//    cout<<endl;

    int target = 0;
    vector<vector<int> > ans = fourSum(v, target);
//    printf("target: %d\n", target);

    for(int i = 0; i < ans.size(); i ++) {
        for(int j = 0; j < ans[i].size();j ++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
