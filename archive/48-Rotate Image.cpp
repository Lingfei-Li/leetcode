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



void exchange(vector<vector<int> >& matrix, int x, int y) {
    int n = matrix.size();
    int tmp = matrix[x][y];
    for(int i = 0; i < 4; i ++) {
//        printf("x:%d y:%d\n", x, y);
        int a = y, b = n-1-x;
        swap(tmp, matrix[a][b]);
        x = a;
        y = b;
    }
}

void rotate(vector<vector<int> >& matrix) {
    //In-place
    if(matrix.size() == 0) return;
    int n = matrix.size();
    for(int i = 0; i < (n+1)/2; i ++) {
        for(int j = 0; j < (n)/2; j ++) {
            exchange(matrix, i, j);
        }
    }
}



int main() {
	srand(time(NULL));

    const int n = 5;
    vector<vector<int> > m;
    m.resize(n);
    for(int i = 0; i < n; i ++) m[i].resize(n);

    for(int i = 0; i < n; i ++)
    for(int j = 0; j < n; j ++) {
        m[i][j] = i+j;
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++) {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }

    rotate(m);

    cout<<endl;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++) {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }

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
