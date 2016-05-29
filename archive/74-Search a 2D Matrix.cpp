#include"mytest.cpp"


using namespace std;


bool searchMatrix(vector<vector<int> >& matrix, int target) {

    for(int i = 0; i < matrix.size(); i ++) {
        if(matrix[i][0] <= target && matrix[i][matrix[i].size()-1] >= target) {
            vector<int>::iterator it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if(*it== target) return true;
        }
        if(matrix[i][0] > target) return false;
    }

    return false;
}



int main() {
	srand(time(NULL));


    int x;
    while(cin>>x) {
        int m = 4, n = 4;
        vector<vector<int> > matrix;
        for(int i = 0; i < m; i ++) {
            vector<int> vec;
            genVector(vec, n);
            sort(vec.begin(), vec.end());
            matrix.push_back(vec);
            printVector(vec);
        }
        cout<<endl;


        cout<<searchMatrix(matrix, x)<<endl;
    }



    return 0;
}
