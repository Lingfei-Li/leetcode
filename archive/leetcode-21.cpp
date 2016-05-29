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


//Global Variables.

////


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void update(ListNode* n, ListNode* h) {
    if(n==NULL) {
        n = h;
    }
    else {
        n->next = h;
        n = n->next;
    }
    h = h->next;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode *v = NULL, *n = NULL;
    if(l1->val < l2->val) n = l1, l1 = l1->next;
    else n = l2, l2 = l2->next;
    v = n;
    while(l1!=NULL || l2!=NULL) {
        if(l2==NULL || (l1!=NULL && l1->val < l2->val)) v->next = l1, v = v->next, l1 = l1->next;
        else v->next = l2, v = v->next, l2 = l2->next;
    }
    return n;
}


int main() {
	srand(time(NULL));

	vector<int> v;
    for(int i = 0; i < 30; i ++) v.push_back(rand()%100);
    sort(v.begin(), v.end());
    int cnt = 0;


    ListNode* h1, *h2;
    h1 = (ListNode*)malloc(sizeof(ListNode));
    h1->val = v[cnt++];
    h2 = (ListNode*)malloc(sizeof(ListNode));
    h2->val = v[cnt++];
    ListNode* u1 = h1, *u2 = h2;


    for(int i = 0; i < 10; i ++) {
        ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
        tmp->val = v[cnt++];
        tmp->next = NULL;
        u1->next = tmp;
        u1 = u1->next;

        ListNode* tmp2 = (ListNode*)malloc(sizeof(ListNode));
        tmp2->val = v[cnt++];
        tmp2->next = NULL;
        u2->next = tmp2;
        u2 = u2->next;
    }
    u1 = h1, u2 = h2;
    while(u1!= NULL) {
        printf("%d -> ", u1->val);
        u1 = u1->next;
    }
    printf("\n");
    while(u2!= NULL) {
        printf("%d -> ", u2->val);
        u2 = u2->next;
    }
    printf("\n");

    ListNode* u = mergeTwoLists(h1, h2);
    while(u!=NULL){
        printf("%d -> ", u->val);
        u = u->next;
    }

    return 0;
}
