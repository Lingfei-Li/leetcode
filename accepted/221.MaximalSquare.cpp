// 3.8%..........................................
// be warned of index out of boundary

#include"mytest.h"


int maximalSquare(vector<vector<char> >& matrix) {
    vector<vector<int> > ht;
    ht.resize(matrix.size());
    for(int i = 0; i < matrix.size(); i ++) {
        ht[i].resize(matrix[i].size());
        for(int j = 0; j < matrix[i].size(); j ++) {
            if(!i) {
                ht[i][j] = matrix[i][j]-'0';
            }
            else {
                if(matrix[i][j] == '0') {
                    ht[i][j] = 0;
                }
                else {
                    ht[i][j] = ht[i-1][j] + 1;
                }
            }
        }
    }
    printBoard(ht);

    int ans = 0;
    for(int i = 0; i < matrix.size(); i ++) {
        for(int j = 0; j < matrix[i].size(); j ++) {
            int h = ht[i][j];
            int minh = h;
            for(int k = 0; k < h && k<minh && j+k<matrix[i].size(); k ++) {
                minh = min(minh, ht[i][j+k]);
                if(ht[i][j+k] > k) {
                    ans = max(ans, k+1);
                    if(k +1 == 3) {
                        printf("%d %d\n", i, j);
                    }
                }
                else {
                    break;
                }
            }
        }
    }

    return ans*ans;
}



int main() {
	srand(time(NULL));

    vector<vector<char> > b;
    readBoard(b);
    printBoard(b);
    cout<<maximalSquare(b)<<endl;



    return 0;
}
