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
void printArray(int* A, int n);
void genArray(int* A, int n);
ListNode* genLinkedList();



int match(string s1, string s2) {
    for(int i = 0; i < s2.length(); i ++) {
        if(i >= s1.length()) return 0;
        if(s1[i] != s2[i]) return 0;
    }
    return 1;
}


int strStr(string haystack, string needle) {
    if(needle.length() == 0) return 0;
    else if(haystack.length() < needle.length()) return -1;
    for(int i = 0; i < haystack.length()-needle.length()+1; i ++) if(match(&haystack[i], needle)) return i;
    return -1;
}



int main() {
	srand(time(NULL));


    string s1, s2;
    while(cin>>s1>>s2) {
        cout<<strStr(s1, s2)<<endl;
    }




    return 0;
}

void printArray(int* A, int n) {
	for(int i = 0; i < n; i ++) printf("%d ", A[i]);
    printf("\n");
}

void genArray(int* A, int n) {
    for(int i = 0; i < n; i ++) A[i] = rand()%20-10;
    sort(A, A+n);
}

ListNode* genLinkedList() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* h = head;
    int n = 1;
    for(int i = 0; i < n; i ++) {
        h->val = i;
        if(i!=n-1)h->next = (ListNode*)malloc(sizeof(ListNode));
        else h->next = 0;
        h = h->next;
    }
    return head;
}
