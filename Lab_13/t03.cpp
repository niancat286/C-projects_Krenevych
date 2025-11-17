#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string case1(const string &s){
    string res = "";
    for (size_t i = 0; i < s.length(); ++i){
        if (isspace(s[i])){
            res += s[i];
        }
        else{
            size_t j = i;
            while (j < s.length() && !isspace(s[j])){
                j++;
            }

            size_t lenWord = j - i;

            if (lenWord > 0){
                res.append(s, i, lenWord - 1);
            }

            i = j - 1;
        }
    }
    return res;
}

void case2(string &s){
    for (size_t i = 0; i < s.length(); ++i){
        if (!isspace(s[i])){
            size_t j = i;
            while (j < s.length() && !isspace(s[j])){
                j++;
            }
            if (j > i){
                s.erase(j - 1, 1);
            }

            i = j - 2;
        }
    }
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