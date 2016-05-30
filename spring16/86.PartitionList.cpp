#include"mytest.h"


using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};


ListNode* partition(ListNode* head, int x) {
    ListNode* u = head;
    ListNode *s = 0, *l = 0;
    ListNode *st = 0, *lt = 0;
    while(u) {
        if(u->val < x) {
            if(!s){
                st = s = u;
            }
            else {
                st->next = u;
                st = u;
            }
        }
        else {
            if(!l) {
                lt = l = u;
            }
            else {
                lt->next = u;
                lt = u;
            }
        }
    
        u = u->next;
    }


    if(st)
        st->next = l;
    else
        return l;
    if(lt)
        lt->next = 0;


    return s;
                
}



int main() {
	srand(time(NULL));

    int a;
    ListNode* head = 0;
    ListNode* tail = 0;
    while(cin>>a) {
        ListNode* u = new ListNode(a);
        if(head == 0) {
            tail = head = u;
        }
        else {
            tail->next = u;
        }
        tail = u;
    }

    ListNode* u = head;
    while(u) {
        printf("%d->", u->val);
        u = u->next;
    }
    cout<<endl;
    u = partition(head, -1);
    while(u) {
        printf("%d->", u->val);
        u = u->next;
    }






    return 0;
}
