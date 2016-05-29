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


int validateSquare(vector<vector<char> >&board, int row, int col) {
    int vis[10];
    memset(vis, 0, sizeof(vis));
     int l = 3*row, r = 3*row+3, u = 3*col, d = 3*col+3;
     for(int i = l; i < r; i ++) {
        for(int j = u; j < d; j ++) {
            if(board[i][j]=='.') continue;
            int a = board[i][j]-'0';
            if(vis[a]) return 0;
            vis[a] = 1;
        }
     }
     return 1;
}
int validateRow(vector<vector<char> >& board, int row) {
    int vis[10];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < 9; i ++) {
        if(board[row][i]=='.') continue;
        int a = board[row][i]-'0';
        if(vis[a]) return 0;
        vis[a] = 1;
    }
    return 1;
}
int validateCol(vector<vector<char> >& board, int col) {
    int vis[10];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < 9; i ++) {
        if(board[i][col]=='.') continue;
        int a = board[i][col]-'0';
        if(vis[a]) return 0;
        vis[a] = 1;
    }
    return 1;
}


bool isValidSudoku(vector<vector<char> >& board) {
    for(int i = 0; i < 9; i ++) {
        if(!validateRow(board, i)) return false;
        if(!validateCol(board, i)) return false;
    }
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            if(!validateSquare(board, i, j)) return false;
        }
    }
    return true;
}


int main() {
	srand(time(NULL));

	#define DEBUG 1
    #ifdef DEBUG
    freopen("36-Valid Sudoku.in","r",stdin);
//    freopen(fileOut,"w",stdout);
    #endif



    vector<vector<char> > v(9, vector<char>());
    char ch;
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            do{ cin>>ch; } while(isspace(ch));
//            do{scanf("%c", &ch);}while(isspace(ch));
            v[i].push_back(ch);
        }
    }

    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            printf("%c ", v[i][j]);
        }
        printf("\n");
    }

    cout<<isValidSudoku(v);


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
    sort(v.begin(), v.end());
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
