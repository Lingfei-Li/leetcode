#include"mytest.cpp"


using namespace std;

void setZeroes(vector<vector<int> >& matrix) {
    int m = matrix.size();
    if(!m) return;
    int n = matrix[0].size();
    if(!n) return;

    set<int> z_row, z_col;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            if(!matrix[i][j]) {
                z_row.insert(i);
                z_col.insert(j);
            }
        }
    }
    for(set<int>::iterator it = z_row.begin(); it != z_row.end(); it++) {
        for(int i = 0; i < n; i ++) {
            matrix[*it][i] = 0;
        }
    }
    for(set<int>::iterator it = z_col.begin(); it != z_col.end(); it++) {
        for(int i = 0; i < m; i ++) {
            matrix[i][*it] = 0;
        }
    }

//    for(int i = 0; i < m; i ++) {
//        for(int j = 0; j < n; j ++) {
//            printf("%d ", matrix[i][j]);
//        }
//        printf("\n");
//    }

}


int main() {
	srand(time(NULL));

    string s1, s2;
    while(cin>>s1) {
        vector<vector<int> > matrix;
        for(int i = 0; i < 3; i ++) {
            vector<int> vec;
            genVector(vec, 5);
            matrix.push_back(vec);
        }
        for(int i = 0; i < 3; i ++) {
            for(int j = 0; j < 5; j ++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");

        }
        printf("\n");

        setZeroes(matrix);
    }
    return 0;
}
