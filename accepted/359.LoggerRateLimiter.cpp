#include"mytest.h"



class Logger {
public:

    queue<pair<int,string> > q;
    unordered_set<string> st;

    Logger() {

    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        while(!q.empty() && q.front().first <= timestamp-10){
            st.erase(q.front().second);
            q.pop();
        }
        if(st.count(message)) return false;
        else {
            q.push(pair<int,string>(timestamp, message));
            st.insert(message);
        }
        return true;
    }
};


int main() {
	srand(time(NULL));


    Logger log = Logger();

    int time;
    string msg;
    while(cin>>time>>msg){
        cout<<log.shouldPrintMessage(time, msg)<<endl;
    }



    return 0;
}
