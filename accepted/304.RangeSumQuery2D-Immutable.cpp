// 77.21% okay
// square dynamic programming

#include"mytest.h"

class NumMatrix {
public:
    vector<vector<int> > cnt;
	vector<int> tmp;
    NumMatrix(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        if(m == 0) return;

        cnt.resize(n);
        tmp.resize(m);
        for(int i = 0; i < n; i ++) {
            cnt[i].resize(m);
            for(int j = 0; j < m; j ++) {

                tmp[j] = matrix[i][j];
                if(j) tmp[j] += tmp[j-1];

                cnt[i][j] = tmp[j];
                if(i) cnt[i][j] += cnt[i-1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = 0;
        if(row1 != 0) {
            a = cnt[row1-1][col2];
        }
        int b = 0;
        if(col1 != 0) {
            b = cnt[row2][col1-1];
        }
        int c = 0;
        if(row1&&col1) {
            c = cnt[row1-1][col1-1];
        }
        return cnt[row2][col2]-a-b+c;
    }
};




int main() {
	srand(time(NULL));

    vector<vector<int> > board;
    readBoard(board);
    printBoard(board);

    NumMatrix m = NumMatrix(board);
    int a, b, c, d;
    while(cin>>a>>b>>c>>d) cout<<m.sumRegion(a,b,c,d)<<endl;



    return 0;
}
