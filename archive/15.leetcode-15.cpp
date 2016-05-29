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
const int maxn = 100000;


vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > ans;
    if(num.size() < 3) return ans;
    sort(num.begin(), num.end());
    for(int i = 0; i < num.size() - 2; i ++) {
        if(i && num[i] == num[i-1]) continue;

        int a = i + 1, b = num.size() - 1;
        if(num[i] + num[a] > 0) continue;
        if(num[i] > 0 && num[a] > 0) break;
        int sum = -num[i];
        while(a < b) {
            if(a != i + 1 && num[a] == num[a-1]) a ++;
            else if(b != num.size()-1 && num[b] == num[b+1]) b --;
            else if(num[a] + num[b] > sum) b--;
            else if(num[a] + num[b] < sum) a ++;
            else {
                vector<int> tmp;
                tmp.push_back(num[i]);
                tmp.push_back(num[a]);
                tmp.push_back(num[b]);
                ans.push_back(tmp);
                a ++;
                b --;
            }
        }
    }
    return ans;
}


vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > ans;
    if(num.size() < 3) return ans;
    sort(num.begin(), num.end());
    for(int i = 0; i < num.size()-2; i ++) {
        if(i && num[i] == num[i-1]) continue;
        for(int j = i+1; j < num.size()-1; j ++) {
            if(j != i+1 && num[j] == num[j-1]) continue;
            if(num[i] > 0 && num[j] > 0) break;

            int sum = -(num[i] + num[j]);
            int l = j+1, r = num.size();

            int m = 0;
            while(l < r) {      //binary search
                m = (l+r)/2;
                if(num[m] < sum) l = m+1;
                else if( num[m] > sum) r = m;
                else break;
            }
            if(num[m] == sum) {             //found sum.
                vector<int> tmp;
                tmp.push_back(num[i]);
                tmp.push_back(num[j]);
                tmp.push_back(sum);
                ans.push_back(tmp);
            }
        }
    }
    return ans;
}


int main() {

    srand(time(NULL));

    while(1) {
        vector<int> v;
        int x;
        while(cin>>x && x != 123) v.push_back(x);
        //    for(int i = 0; i < 20; i ++) v.push_back(rand()%20-10);
        //    for(int i = 0; i < v.size(); i ++) printf("%d ", v[i]);
        printf("\n");

        vector<vector<int> > ans = threeSum(v);

        for(int i = 0; i < ans.size(); i ++) {
        for(int j = 0; j < ans[i].size(); j ++) {
        printf("%d ", ans[i][j]);
        }
        printf("\n");
        }
    }




    return 0;
}
