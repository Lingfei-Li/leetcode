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
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<iostream>
#include<fstream>
#include<sstream>
#include<assert.h>

#define RANDRNG 20

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//note: supported by leetcode directly
string to_string(int a) {
    return to_string((long long int)a);
}

vector<string> split(string& s, char delim) {
    istringstream iss(s);
    vector<string> ret;
    while(getline(iss, s, delim))
        ret.push_back(s);
    return ret;
}

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i ++) cout<<v[i]<<" ";
    cout<<endl;
}
void printVector(vector<char> v) {
    for(int i = 0; i < v.size(); i ++) cout<<v[i]<<" ";
    cout<<endl;
}
void printVector(vector<string> v) {
    for(int i = 0; i < v.size(); i ++) cout<<v[i]<<endl;
    cout<<endl;
}
void print(vector<int> v) { printVector(v); }
void print(vector<char> v) { printVector(v); }
void print(vector<string> v) { printVector(v); }

void readBoard(vector<vector<char> >& m) {
    int r, c;
    cin>>r>>c;
    m.clear();
    m.resize(r);
    char ch;
    for(int i = 0; i < r; i ++) {
        m[i].resize(c);
        for(int j = 0; j < c; j ++) {
            cin>>ch;
            m[i][j] = ch;
        }
    }
}

void readBoard(vector<vector<int> >& m) {
    int r, c;
    cin>>r>>c;
    m.clear();
    m.resize(r);
    int a;
    for(int i = 0; i < r; i ++) {
        m[i].resize(c);
        for(int j = 0; j < c; j ++) {
            cin>>a;
            m[i][j] = a;
        }
    }
}

void printBoard(vector<vector<int> > m) {
    for(int i = 0; i < m.size(); i ++) {
        for(int j = 0; j < m[0].size(); j ++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void printBoard(vector<vector<char> > m) {
    for(int i = 0; i < m.size(); i ++) {
        for(int j = 0; j < m[0].size(); j ++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print(vector<vector<int> > m) { printBoard(m); }
void print(vector<vector<char> > m) { printBoard(m); }

void printArray(int* A, int n) {
	for(int i = 0; i < n; i ++) printf("%d ", A[i]);
    printf("\n");
}
void printListkedList(ListNode *u) {
    while(u) {
        printf("%d ", u->val);
        u = u->next;
    }
	printf("\n");
}
void print(ListNode* u) { printListkedList(u); }

int readVector(vector<int>& v) {
    v.clear();
    string s;
    while(cin>>s && s != "-") {  //note: '-' indicates stop
        v.push_back(atoi(s.c_str()));
    }
    if(v.size()== 0) return 0;
    return 1;
}

int readVector(vector<string>& v) {
    v.clear();
    string a;
    while(cin>>a && a != "-") {  //note: '-' indicates stop
        v.push_back(a);
    }
    if(v.size()== 0) return 0;
    return 1;
}

int read(vector<int>& v) { readVector(v); }
int read(vector<string>& v) { readVector(v); }


//Generate a vector of length n, int range [0,rng) (default RANDRNG);
void genVector(vector<int>& v, int n, int rng) {
    for(int i = 0; i < n; i ++) v.push_back(rand()%rng+1);
}
void genVector(vector<int>& v, int n) {
    genVector(v, n, RANDRNG);
}

void gen(vector<int>& v, int n) {
    genVector(v, n);
}
void gen(vector<int>& v, int n, int rng) {
    genVector(v, n, rng);
}



void genArray(int* A, int n) {
    for(int i = 0; i < n; i ++) A[i] = rand()%RANDRNG;
   // sort(A, A+n);
}

ListNode* readIntLinkedList() {
    ListNode* head = 0, *tail = 0;
    int a;
    while(cin>>a) {
        ListNode* u = new ListNode(a);
        if(head == 0) {
            head = tail = u;
        }
        else {
            tail->next = u;
        }
        tail = u;
    }
    return head;
}


//Generate a linked list of length n, range [0,rng) (default RANDRNG);
ListNode* genLinkedList(int n, int rng) {
	ListNode* head = 0;
    ListNode* u, *v;
    for(int i = 0; i < n; i ++) {
//        v = new ListNode(rand()%rng);
        v = new ListNode(i+1);
        if(!head) head = u = v;
        else {
            u->next = v;
            u = v;
        }
    }
    return head;
}

ListNode* genLinkedList(int n) {
    return genLinkedList(n, RANDRNG);
}



TreeNode* readTree() {
    int a;
    TreeNode* head;

    queue<TreeNode*> q;
    cin>>a;
    head = new TreeNode(a);
    q.push(head);
    int hold = 0;
    TreeNode* u = NULL;
    while(cin>>a) {
        if(!hold) {
            u = q.front();
            q.pop();
        }
        TreeNode* v = NULL;
        if(a!=-1) {
            v = new TreeNode(a);  //Note: -1 stands for NULL node
            q.push(v);
        }
        if(!hold) {
            hold = 1;
            u->left = v;
        }
        else {
            hold = 0;
            u->right = v;
        }
    }
    return head;
}

void printTree(TreeNode* r) {
    queue<TreeNode*> q;
    q.push(r);
    while(!q.empty()) {
        TreeNode* u = q.front();
        q.pop();
        if(!u) {
            cout<<"# ";
            continue;
        }
        else {
            cout<<u->val<<" ";
            q.push(u->left);
            q.push(u->right);
        }
    }
    cout<<endl;
}


/* Keywords:
 * unordered_map
 * unordered_set
 *
 *
 */
