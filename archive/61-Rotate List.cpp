#include"mytest.cpp"


using namespace std;
/*
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
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;
    int len = 1;
    ListNode* end = head;
    while(end->next) {
        end = end->next;
        len++;
    }
    cout<<len<<endl;
    k %= len;
    ListNode* newend = head;
    for(int i = 0; i < len-k-1; i ++) {
        newend = newend->next;
    }
    end->next = head;
    head = newend->next;
    newend->next = 0;
    return head;
}

int main() {
	srand(time(NULL));

    vector<int> vec;
    genVector(vec, 2);
//    for(int i = 0; i < vec.size(); i ++) cout<<vec[i]<<endl;


    ListNode* h = NULL;
    for(int i = 0; i < vec.size(); i ++) {
        ListNode* v = (ListNode*)malloc(sizeof(ListNode));
        v->val = vec[i];
        v->next = 0;
        if(!h)
            h = v;
        else {
            v->next = h;
            h = v;
        }
    }
    ListNode* u = h;
    while(u) {
        cout<<u->val<<" ";
        u = u->next;
    }
    cout<<endl;
    h = rotateRight(h, 101);
    while(h) {
        cout<<h->val<<" ";
        h = h->next;
    }




    return 0;
}
