#include"mytest.cpp"


using namespace std;

/*
1.spaces at sides
2.integers
3.decimals
4.hex
5.negative
6.exp
*/


bool ishex(char c) {
    if(isdigit(c) || (c>='a' && c<='f')) return true;
    return false;
}

bool beginsWithInteger(const string& s, int hexflag) {
    if(s.length() == 0) return false;
    int spaceflag = 0;
    for(int i = 0; i < s.length(); i ++) {
        if(spaceflag == 0 && !isdigit(s[i]) && !(hexflag && ishex(s[i]))) {
            if(s[i] == ' ')
                spaceflag = 1;
            else
                return false;
        }
        else if(spaceflag) {
            if(s[i] != ' ')
                return false;
        }
    }
    return true;
}


bool isNumber(string s) {
    int i, negflag = 0;
    for(i = 0; i < s.length(); i ++) {
        if(!isspace(s[i]) && !isdigit(s[i]) && s[i] != '-') return false;
        if(s[i] == '-') {
            negflag = 1;
            i++;
        }
        if(isdigit(s[i])){
            i++;
            break;
        }
        if(negflag) return false;
    }
    if(negflag && !isdigit(s[i]) && s[i] != 'x') return false;

    int hexflag = 0;
    if(s[i-1] == '0' && s[i] == 'x') {
        i ++;       //hex
        hexflag = 1;
    }
    if(hexflag && !isdigit(s[i]) && !ishex(s[i])) return false;

    for(i = i; i < s.length(); i ++) {
        if(isdigit(s[i]) || (hexflag && ishex(s[i]))) continue;
        if(s[i] == '.') return beginsWithInteger(s.substr(i+1, s.length()-i), hexflag);      //validate right part: must be integer.
        else if(s[i] == 'e') return isNumber(s.substr(i+1, s.length()-i));      //validate right part:must be another num.
        else {
            for(; i < s.length(); i ++) {
                if(s[i] != ' ') return false;
            }
            return true;
        }
    }

    return true;
}

int main() {
	srand(time(NULL));

    char str[30];
    while(fgets(str, 30, stdin)) {
        str[strlen(str)-1] = '\0';
        string s(str);
        cout<<isNumber(s)<<endl;
    }



    return 0;
}
