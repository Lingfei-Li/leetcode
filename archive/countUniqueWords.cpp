#include"mytest.cpp"


using namespace std;


struct Node {
    char val;
    int leaf;
    Node* children[36];
    Node(char c):val(c),leaf(1){
        for(int i = 0; i < 36; i ++) children[i] = NULL;
    }
};

Node* newNode(char c) {     //new dictionary tree node.
    Node* u = (Node*)malloc(sizeof(Node));
    for(int i = 0; i < 36; i ++) u->children[i] = NULL;
    u->leaf = 1;
    u->val = c;
    return u;
}

int countUniqueWords(char* s) {
    int ans = 0;
    Node* head = newNode('0');

    int newword = 0;
    Node* u = head;
    for(int i = 0; i < strlen(s); i ++) {
        if(isalnum(s[i])) {
            if(isdigit(s[i])) {
                if(u->children[26+s[i]-'0'] == NULL) {
                    newword = 1;
                    Node* v = newNode(s[i]);
                    u->children[26+s[i]-'0'] = v;
                    u = v;
                }
                else {
                    u = u->children[26+s[i]-'0'];
                }
            }
            else {
                if(u->children[s[i]-'a'] == NULL) {
                    newword = 1;
                    Node* v = newNode(s[i]);
                    u->children[s[i]-'a'] = v;
                    u = v;
                }
                else {
                    u = u->children[s[i]-'a'];
                }
            }

        }
        if(!isalnum(s[i])) {            //encounters non-alnum. count the word.
            if(newword) {
                ans++;
                newword = 0;
            }
            u = head;
        }
    }


    return ans;
}

int main() {
	srand(time(NULL));

//three ways to count unique words
//n is total # of words
//m is len of str
//1. dictionary tree O(m)
//2. sort O(mlogn)
//3. map O(mlogn)

    char s[1000];
    while(fgets(s, 1000, stdin)) {
        cout<<countUniqueWords(s)<<endl;

    }



    return 0;
}
