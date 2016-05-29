#define UVa  "44-Wildcard Matching.cpp"     //

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



bool isMatch(string s, string p) {
    int a1 = 0, a2 = 0;
    while(a1 < s.length() && a2 < p.length()) {
        char c1 = s[a1], c2 = p[a2];
        if(c2 != '*' && (c1 == c2 || c2 == '?')) {      //c2 should not be * in this case.
            a1++;
            a2++;
        }
        else if(c2 == '*'){
            if(a2 == p.length()-1) return true;
            a2++;
            for(int i = 0; a1+i < s.length(); i ++) {
                if(isMatch(s.substr(a1+i, s.length()-(a1+i)), p.substr(a2, p.length()-a2))) return true;
            }
        }
        else return false;  //current characters don't match in any case
    }
    if(a1 == s.length() && a2 == p.length()) return true;   //both come to the end
    else if(a1 == s.length() && p[a2] == '*') {             //wildcard can match empty strings
        a2 ++;
        return isMatch(s.substr(a1, s.length()-a1), p.substr(a2, p.length()-a2));
    }
    return false;
}


int main() {
    #define DEBUG 1
    #ifdef DEBUG
    char fileIn[30] = UVa, fileOut[30] = UVa;
    strncpy(&fileIn[strlen(fileIn) - 4], ".in\0", 5); strncpy(&fileOut[strlen(fileOut) - 4], ".out\0", 5);
    freopen(fileIn,"r",stdin);
//    freopen(fileOut,"w",stdout);
    #endif


	srand(time(NULL));

    string s1, s2;
    while(cin>>s1>>s2) {
        if(isMatch(s1, s2)) cout<<"Match"<<endl;
        else cout<<"Fail"<<endl;
//        cout<<s1.substr(3, 3);
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
