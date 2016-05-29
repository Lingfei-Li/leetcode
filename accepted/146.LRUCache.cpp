// 0.00%..........................
// slow (just a mark)
// LRU - update on get!
// linked list

#include"mytest.h"


using namespace std;

struct LL {
    int key, val;
    LL* next;
    LL(int key, int val):key(key), val(val), next(0){}
};


int cap, usage;
LL* head, *tail;    //head: sentinel. tail: last non-null node (include head)
// tail: Newest. head->next: Oldest

void LRUCache(int capacity) {
    cap = capacity;
    head = new LL(0, 0);    //sentinel
    tail = head;
    usage = 0;
}

//Note: returns target node's parent
LL* search(int key) {
    LL* u = head;
    while(u->next) {
        if(u->next->key == key) return u;
        u = u->next;
    }
    return 0;

}

void update_cache(LL* p) {
    LL* u = p->next;

    if(u == tail) return;

    LL* n = u->next;

    p->next = n;

    tail->next = u;
    u->next = 0;
    tail = u;
}

int get(int key) {
    int ans = -1;
    LL* p = search(key);
    if(p) {
        ans = p->next->val;
        update_cache(p);
    }
    return ans;
}

void set1(int key, int value) {
    LL* p = search(key);
    if(p) {
        p->next->val = value;
        update_cache(p);
    }
    else {
        if(usage >= cap) {
//            cout<<"swapping..\n";
            //swap LRU out...
            LL* v = head->next;
            LL* n = v->next;
            head->next = n;
            if(!n) {
                tail = head;
            }
            free(v);
            usage --;
        }
//        cout<<"inserting..\n";
        LL* u = new LL(key, value);
        tail->next = u;
        tail = u;
        usage ++;
    }
}


void printLL(LL* u) {
    while(u) {
        cout<<u->key<<"-"<<u->val<<" ";
        u = u->next;
    }
    cout<<" tail(MRU): "<<tail->key<<endl;
    cout<<endl;
}

int main() {
	srand(time(NULL));



    int tmp = 1;
    cin>>tmp;

    LRUCache(tmp);
    printLL(head);
    string s;
    while(cin>>s && s != "-") {
        if(s == "g" || s == "get") {
            cin>>tmp;
            cout<<"get "<<tmp<<endl;
            cout<<get(tmp)<<endl<<endl;
        }
        else if(s == "s" || s == "set") {
            cin>>tmp;
            int b;
            cin>>b;
            cout<<"set "<<tmp<<" "<<b<<endl;
            set1(tmp, b);
        }
        else if(s == "p") {
        }
        else {
            cout<<"invalid\n";
        }
            printLL(head);
    }





    return 0;
}
