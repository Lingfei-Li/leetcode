#include"mytest.cpp"


using namespace std;


string justifyLine(int l, int r, vector<string>& words, int L) {
    int n = r-l;        //number of intervals.
    int len = 0;        //number of chars
    for(int i = l; i <= r; i ++) len += words[i].length();
    int m = L-len;      //number of spaces.
    string ans;
    for(int i = 0; i < n+1; i ++) {     //all words in range [l, r]
        for(int j = 0; j < words[l+i].length(); j ++) {
            ans.push_back(words[l+i][j]);                 //push the word into ans
        }
        if(i!=n) {
            for(int k = 0; k < m/n; k ++)
                ans.push_back(' ');
            if(i < m%n) ans.push_back(' ');
        }
        if(l == r)
            for(int k = words[l].length() + 1; k <= L; k ++)
                ans.push_back(' ');
    }

    return ans;
}



vector<string> fullJustify(vector<string>& words, int maxWidth) {
    //basic function: split the words into several lines.
    vector<string> ans;
    int len = 0, l = 0, r = 0;
    for(int i = 0; i < words.size(); i ++) {

        len += words[i].length()+1;     //+1 for white space
//        cout<<words[i]<<endl;
//        cout<<l<<" "<<len<<endl;
        if(len > maxWidth+1) {          //+1 for space.
            ans.push_back(justifyLine(l, i-1, words, maxWidth));
            l = i;
            len = words[i].length()+1;
        }
    }
    //push the remaining words.
    string lastline;
    for(int i = l; i < words.size(); i ++) {        //push the remaining words.
        for(int j = 0; j < words[i].length(); j ++) {
            lastline.push_back(words[i][j]);
        }
        if(i != words.size()-1) lastline.push_back(' ');
    }
    for(int i = lastline.length(); i < maxWidth; i ++) {
        lastline.push_back(' ');
    }
    ans.push_back(lastline);

    return ans;
}


int main() {
	srand(time(NULL));

    vector<string> vec;
    vec.push_back("This");
    vec.push_back("is");
    vec.push_back("an");
    vec.push_back("example");
    vec.push_back("of");
    vec.push_back("text");
    vec.push_back("justification.");
    vec.push_back("sbb");
    vec.push_back("sbb");
    vector<string> ans = fullJustify(vec, 16);
    for(int i = 0; i < ans.size(); i ++) {
        cout<<ans[i]<<endl;
    }
//    cout<<justifyLine(0, vec.size()-1, vec, 7);



    return 0;
}
