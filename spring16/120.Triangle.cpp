// Feature:
// dynamic programming
// O(n) space

#include"mytest.h"



using namespace std;

int minimumTotal(vector<vector<int> >& triangle) {

    vector<int> ans[2];
    int r = triangle.size();
    if(!r) return 0;
    if(r == 1) return triangle[0][0];

    int c = triangle[r-1].size();
    ans[0].resize(c+5);
    ans[1].resize(c+5);

    int t = 0;
    ans[t][0] = triangle[0][0];
    for(int i = 1; i < r; i ++) {
        t^=1;
//        for(int k = 0; k < c; k ++) ans[t][k] = 0;
        for(int j = 0; j < triangle[i].size(); j ++) {
            ans[t][j] = triangle[i][j];
            cout<<ans[t][j]<<" ";
            //ignore boundary: already left empty space
            if(j == 0) {
                ans[t][j] += ans[t^1][j];
                cout<<ans[t^1][j]<<" : ";
            }
            else if(j == triangle[i].size() - 1) 
                ans[t][j] += ans[t^1][j-1];
            else 
                ans[t][j] += min(ans[t^1][j-1], ans[t^1][j]);
            cout<<ans[t][j]<<" ";
        }
        cout<<endl;

    }
    int res = (1<<31)-1;
    for(int k = 0; k < c; k ++) {
        res = min(res, ans[t][k]);
    }
    return res;
}


int main() {
	srand(time(NULL));

    vector<vector<int> > b;

    vector<int> a;
    a.push_back(-1);
    b.push_back(a);

    a.resize(0);
    a.push_back(2);
    a.push_back(3);
    b.push_back(a);

    a.resize(0);
    a.push_back(1);
    a.push_back(-1);
    a.push_back(-1);
    b.push_back(a);




    cout<<minimumTotal(b)<<endl;
    return 0;




    for(int i = 1; i < 3; i ++) {
        vector<int> a;
        genVector(a,i);
        printVector(a);
        b.push_back(a);
    }

    cout<<minimumTotal(b)<<endl;




    return 0;
}
