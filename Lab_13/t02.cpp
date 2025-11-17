#include <iostream>
#include <string>
using namespace std;

string case1(const string &s){
    size_t pos_first = s.find('.');
    size_t pos_last = s.rfind('.');
    if (pos_first == string::npos){
        size_t char_first = s.find_first_not_of(" \t");

        if (char_first == string::npos){
            return "";
        }
        return s.substr(char_first);
    }

    if (pos_first == pos_last){
        return s.substr(pos_first);
    }

    string pt1 = s.substr(0, pos_first + 1);
    string pt2 = s.substr(pos_last);
    return pt1 + pt2;
}

void case2(string &s){
    size_t pos_first = s.find('.');
    size_t pos_last = s.rfind('.');
    if (pos_first == string::npos){
        size_t char_first = s.find_first_not_of(" \t");
        if (char_first == string::npos){
            s.clear(); // s = ""
        }
        else{
            s = s.substr(char_first);
        }
        return;
    }
    if (pos_first == pos_last){
        s = s.substr(pos_first);
        return;
    }
    size_t start_pos = pos_first + 1;
    size_t count = pos_last - start_pos;
    s.erase(start_pos, count);
}

int main(){
    string str1;
    cout << "Enter string: ";
    getline(cin, str1);

    cout << "\n #1 (res new string)" << endl;
    string s1 = str1;
    string res1 = case1(s1);
    cout << "before '" << s1 << "'" << endl;
    cout << "after '" << res1 << "'" << endl;

    cout << "\n#2 (modifies)" << endl;
    string s2 = str1;
    cout << "before: '" << s2 << "'" << endl;
    case2(s2);
    cout << "after: '" << s2 << "'" << endl;
    return 0;
}

