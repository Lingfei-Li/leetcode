#include"mytest.cpp"


using namespace std;

//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
string simplifyPath(string path) {
    string ans;
    deque<string> st;
    string tmp;
    for(int i = 0; i < path.length(); i ++) {
        if(path[i] == '/' || i == path.length()-1) {
            if(i == path.length() - 1 && path[i] != '/') tmp.push_back(path[i]);
            if(!tmp.empty()) {
                if(tmp.compare(".") == 0) {
                    //just ignore..
                }
                else if(tmp.compare("..") == 0) {
                    if(!st.empty()) st.pop_back();
                }
                else {
                    st.push_back(tmp);
                }
            }
            tmp.clear();
        }
        else {
            tmp.push_back(path[i]);
        }
    }
    if(st.empty()) {
        ans.push_back('/');
        return ans;
    }
    while(!st.empty()) {
        ans.push_back('/');
        ans.append((st.front()).begin(), (st.front()).end());
        st.pop_front();
    }
    return ans;
}



int main() {
	srand(time(NULL));

    string s;
    while(cin>>s) {
        cout<<simplifyPath(s)<<endl;
    }
    return 0;
}
