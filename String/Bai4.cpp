#include<cctype>
#include<iostream>
#include<string>

using namespace std;

string PrintNormalizedString(string s);

int main() {
    string s = "   introduction     to     programming    ";

    cout<<PrintNormalizedString(s);

    return 0;
}

string PrintNormalizedString(string s) {
    // write your code here
    int n = s.length() - 1;

    while (n > 0) {
        if (s.at(n) == ' ' && s.at(n - 1) == ' ') {
            s.erase(n, 1);
        }
        n--;
    }
    s.erase(0, 1);
    s.erase(s.length() - 1, 1);

    s.at(0) -= 32;
    for (int i = 1; i < s.length()-1; i++) {
        if (s.at(i) != ' ' && s.at(i - 1) == ' ')
            s.at(i) -= 32;
    }
    return s;
}
