#include"mytest.cpp"


using namespace std;

struct Node{
    int flag;
    Node* children[30];
};

class WordDictionary {
private:
    Node* head = NULL;
    Node* newNode() {
        Node* u = (Node*)malloc(sizeof(Node));
        u->flag = 0;
        for(int i = 0; i < 30; i ++) u->children[i] = NULL;
        return u;
    }
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        if(head == NULL) head = newNode();
        Node* u = head;
        int p = 0;
        while(p < word.size()) {
            int c = word[p]-'a';
            if(u->children[c] == NULL) u->children[c] = newNode();
            u = u->children[c];
            p++;
        }
        u->flag = 1;
    }

    bool searchNext(string& word, int p, Node* u) {
        if(p == word.size()) return u->flag;
        if(word[p] == '.') {
            for(int i = 0; i < 30; i ++)
                if(u->children[i])
                    if(searchNext(word, p+1, u->children[i])) return true;
            return false;
        }
        else {
            int c = word[p]-'a';
            if(u->children[c] == NULL)
                return false;
            return searchNext(word, p+1, u->children[c]);
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(!head) return false;
        return searchNext(word, 0, head);
    }
};

int main() {
	srand(time(NULL));


    WordDictionary dict;
    string s;
    while(cin>>s && s.compare("quit")) dict.addWord(s);
    while(cin>>s && s.compare("quit")) cout<<(dict.search(s)?"true":"false")<<endl;



    return 0;
}
