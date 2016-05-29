// Feature:
// O(k) space
// Iteration on array

#include"mytest.h"


using namespace std;

vector<int> getRow(int rowIndex) {
    rowIndex ++;
    vector<int> ans[2];
    if(!rowIndex) return ans[0];
    ans[0].resize(rowIndex);
    ans[1].resize(rowIndex);

    int t = 0;
    ans[t][0] = 1;

    for(int i = 0; i < rowIndex-1; i ++) {
        t ^= 1;
        ans[t][0] = ans[t][i+1] = 1;
        for(int j = 0; j < ans[t^1].size()-1; j ++) 
            ans[t][j+1] = ans[t^1][j]+ans[t^1][j+1];
    }
    return ans[t];
}


int main() {
	srand(time(NULL));

    vector<int> v;
    v = getRow(5);
    for(int i = 0; i < v.size(); i ++) {
        cout<<v[i]<<" "; 
    }



    return 0;
}
