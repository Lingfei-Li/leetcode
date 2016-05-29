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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printVector(vector<int>& v);
void printArray(int* A, int n);
void printListkedList(ListNode *u);
void genVector(vector<int>& v, int n);
void genArray(int* A, int n);
ListNode* genLinkedList(int n);

static const int maxn = 50;

int valid(vector<vector<int> >& matrix, int r, int c, int vis[][maxn]) {
    if(r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size())
        if(!vis[r][c])
            return 1;
    return 0;
}

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> ans;
    if(matrix.empty() || matrix[0].empty()) return ans;
    static int step[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int vis[maxn][maxn];
    memset(vis, 0, sizeof(vis));
    int r = 0, c = 0;
    int d = 0, moved = 0;

    int n = matrix.size();
    int m = matrix[0].size();
    if(n == 1 && m == 1) {
        ans.push_back(matrix[0][0]);
        return ans;
    }
    while(1) {
        int vr = r + step[d][0], vc = c + step[d][1];
        if(!valid(matrix, vr, vc, vis)) {
            if(moved == 2) break;
            moved ++;
            d = (d+1)%4;
            continue;
        }
        ans.push_back(matrix[r][c]);
        vis[r][c] = 1;
        moved = 0;
        r = vr, c = vc;
    }
    ans.push_back(matrix[r][c]);
    return ans;
}



int main() {
	srand(time(NULL));
    vector<vector<int> > v;
    int n = 5, m = 5;
    v.resize(n);
    for(int i = 0; i < n; i ++) {
        genVector(v[i], m);
        printVector(v[i]);
    }
    vector<int> ans;
    ans = spiralOrder(v);
    printVector(ans);



    return 0;
}
void printVector(vector<int>& v) {
    for(int i = 0; i < v.size(); i ++) printf("%d ", v[i]);
    printf("\n");
}
void printArray(int* A, int n) {
	for(int i = 0; i < n; i ++) printf("%d ", A[i]);
    printf("\n");
}
void printListkedList(ListNode *u) {
    while(u) {
        printf("%d -> ", u->val);
        u = u->next;
    }
	printf("\n");
}
void genVector(vector<int>& v, int n) {
    for(int i = 0; i < n; i ++) v.push_back(rand()%20-10);
//    sort(v.begin(), v.end());
}
void genArray(int* A, int n) {
    for(int i = 0; i < n; i ++) A[i] = rand()%20-10;
    sort(A, A+n);
}

ListNode* genLinkedList(int n) {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* h = head;
    for(int i = 0; i < n; i ++) {
        h->val = i;
        if(i!=n-1)h->next = (ListNode*)malloc(sizeof(ListNode));
        else h->next = 0;
        h = h->next;
    }
    return head;
}
