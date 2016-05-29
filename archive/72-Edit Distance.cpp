#include"mytest.cpp"


using namespace std;


int minDistance(string word1, string word2) {
    int INF = 1<<30;
    int m = word1.length(), n = word2.length();
    if(!m) return n;
    if(!n) return m;
    vector<vector<int> > d;
    d.resize(m+1);
    for(int i = 0; i < m+1; i ++) d[i].resize(n+1);

    d[m][n] = 0;
    d[m-1][n] = d[m][n-1] = 1;

    for(int i = m; i >= 0; i --) {
        for(int j = n; j >= 0; j --) {
            if(i == m && j == n) continue;
            int c_match = INF, c_delete = INF, c_insert = INF;

            //matching
            if(i < m && j < n) {
                if(word1[i] == word2[j]) c_match = 0;
                else c_match = 1;
                c_match += d[i+1][j+1];
            }
            if(i<m) c_insert = 1 + d[i+1][j];
            if(j<n) c_delete = 1 + d[i][j+1];

            d[i][j] = min(min(c_match, c_insert), c_delete);
        }
    }

    return d[0][0];
}



int main() {
	srand(time(NULL));

    string s1, s2;
    while(cin>>s1>>s2) {
        cout<<minDistance(s1,s2)<<endl;
    }
    return 0;
}
