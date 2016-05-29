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


ListNode* swapPairs(ListNode* head) {
    if(!head) return 0;
    ListNode *p = head, *u = head, *v;
    if(v = u->next) {
        u->next = v->next;
        v->next = u;
        head = v;
        p = u;
        u = u->next;
    }
    else return head;
    while(u && (v = u->next)) {
        u->next = v->next;
        v->next = u;
        p->next = v;
        p = u;
        u = u->next;
    }

    return head;
}


int main() {
	srand(time(NULL));


    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* h = head;

    for(int i = 0; i < 1; i ++) {
        h->val = rand()%20-10;
        if(i!=1-1)h->next = (ListNode*)malloc(sizeof(ListNode));
        else h->next = 0;
        h = h->next;
    }
    h = head;
    while(h) {
        printf("%d -> ", h->val);
        h = h->next;
    }
    printf("\n");

    h = head;
    h = swapPairs(head);
    while(h) {
        printf("%d -> ", h->val);
        h = h->next;
    }



    return 0;
}
