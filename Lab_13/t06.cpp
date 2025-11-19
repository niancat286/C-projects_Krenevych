#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string task_a_case1(const string &s){
    stringstream ss(s);
    string word;
    string shortWord = "";
    size_t minLen = -1;
    while (ss >> word){
        if (shortWord == "" || word.length() < minLen){
            minLen = word.length();
            shortWord = word;
        }
    }
    return shortWord;
}

void task_a_case2(const string &s, string &res){
    stringstream ss(s);
    string word;
    size_t minLen = -1;
    res = "";
    while (ss >> word){
        if (res == "" || word.length() < minLen){
            minLen = word.length();
            res = word;
        }
    }
}
string findLastV1(const string &s){
    stringstream ss(s);
    string word;
    string shortWord = "";
    size_t minLen = -1;

    while (ss >> word){
        if (shortWord == "" || word.length() <= minLen){
            minLen = word.length();
            shortWord = word;
        }
    }
    return shortWord;
}

void findLastV2(const string &s, string &res){
    stringstream ss(s);
    string word;
    size_t minLen = -1;
    res = "";

    while (ss >> word){
        if (res == "" || word.length() <= minLen){
            minLen = word.length();
            res = word;
        }
    }
}

string findAllV1(const string &s){
    stringstream ss(s);
    string word;
    string res = "";
    size_t minLen = -1;

    while (ss >> word){
        if (res.empty() || word.length() < minLen){
            minLen = word.length();
            res = word;
        }
        else if (word.length() == minLen){
            res += " " + word;
        }
    }
    return res;
}

void findAllV2(const string &s, string &res){
    stringstream ss(s);
    string word;
    size_t minLen = -1;
    res.clear();

    while (ss >> word){
        if (res.empty() || word.length() < minLen){
            minLen = word.length();
            res = word;
        }
        else if (word.length() == minLen){
            res += " " + word;
        }
    }
}

int main(){
    string Inp;
    cout << "Enter a sentence: ";
    getline(cin, Inp);

    cout << "\nTask (a): Find first shortest" << endl;
    cout << "v1 res: '" << task_a_case1(Inp) << "'" << endl;

    string res_v2_a;
    task_a_case2(Inp, res_v2_a);
    cout << "v2 res: '" << res_v2_a << "'" << endl;

    cout << "\nTask (b): Find last shortest" << endl;
    cout << "v1 res: '" << findLastV1(Inp) << "'" << endl;

    string res_v2_b;
    findLastV2(Inp, res_v2_b);
    cout << "v2 res: '" << res_v2_b << "'" << endl;

    cout << "\nTask (c): Find all shortest" << endl;
    string res_v1_c = findAllV1(Inp);
    cout << "v1 res: '" << res_v1_c << "'" << endl;

    string res_v2_c;
    findAllV2(Inp, res_v2_c);
    cout << "v2 res: '" << res_v2_c << "'" << endl;
    return 0;
}