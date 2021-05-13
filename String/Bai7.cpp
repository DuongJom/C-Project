#include<cctype>
#include<iostream>
#include<string>

using namespace std;

string PrintSortedWords(string s);

int main() {
    string s = "introduction to programming";

    string t = PrintSortedWords(s);
    cout << t << endl;
    
    cout << s;
    return 0;
}


string PrintSortedWords(string s) {
    // write your code here
    string a[100];
    int n = 0;
    string word="";
    for (auto x : s)
    {
        if (x == ' ')
        {
            a[n++] = word;
            word = "";
        }
        else {
            word = word + x;
        }
    }
    a[n++] = word;
    char* b[100];
    for (int i = 0; i < n; i++) {
        b[i] = const_cast<char*>(a[i].c_str());
    }
    for (int i = 0; i < n-1; i++) {
        if (strcmp(b[i], b[i+1])>0) {
            char* tmp = b[i];
            b[i] = b[i+1];
            b[i+1] = tmp;
        }
    }

    s = "";
    for (int i = 0; i < n; i++) {
        s += b[i];
        s += " ";
    }
    return s;
}
