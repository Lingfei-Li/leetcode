// Feature:
// Iteration on array

#include"mytest.h"


using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ans;
    if(!numRows) return ans;
    ans.resize(numRows);
    ans[0].push_back(1);
    for(int i = 0; i < numRows-1; i ++) {
        ans[i+1].push_back(1);
        for(int j = 0; j < ans[i].size()-1; j ++) {
            ans[i+1].push_back(ans[i][j]+ans[i][j+1]);
        }
        ans[i+1].push_back(1);
    }
    return ans;
                
}


int main() {
	srand(time(NULL));

    vector<vector<int> > v;
    v = generate(0);
    for(int i = 0; i < v.size(); i ++) {
        for(int j = 0; j < v[i].size();j ++) {
            cout<<v[i][j]<<" "; 
        }
        cout<<endl;
    }



    return 0;
}
