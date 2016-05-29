#include"mytest.cpp"


using namespace std;


int minPathSum(vector<vector<int> >& grid) {
    const int INF = 1<<30;
    int n = grid.size(), m = grid[0].size();

    for(int i = n-1; i >= 0; i --) {
        for(int j = m-1; j >= 0; j --) {
            if(i == n-1 && j == m-1) continue;
            int sum1 = INF, sum2 = INF;
            if(i+1 < n) sum1 = grid[i][j] + grid[i+1][j];
            if(j+1 < m) sum2 = grid[i][j] + grid[i][j+1];
            grid[i][j] = min(sum1, sum2);
        }
    }
    return grid[0][0];
}


int main() {
	srand(time(NULL));

	vector<vector<int> > v;
	vector<int> tmp;
	tmp.push_back(1);
//	tmp.push_back(23);
	v.push_back(tmp);
//	v.push_back(tmp);
//	v.push_back(tmp);
	for(int i = 0; i < v.size(); i ++) {
        for(int j = 0; j < v[i].size(); j ++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
	}
    cout<<minPathSum(v)<<endl;

//    int a, b;
//    while(cin>>a>>b) {
//        cout<<uniquePathsWithObstacles(a, b)<<endl;
//    }



    return 0;
}
