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

int lengthOfLastWord(string s) {
    int pos = -1;
    for(int i = s.length()-1; i >= 0; i --) {
        if(pos != -1 && s[i]==' ') {
            return pos - i;
        }
        if(pos == -1 && !isspace(s[i]))
            pos = i;
    }
    return pos+1;
}

int main() {
	srand(time(NULL));

    char s[300];
    string str;
    while(fgets(s, 300, stdin)) {
        str = string(s);
        cout<<lengthOfLastWord(s)<<endl;
    }
    return 0;
}
