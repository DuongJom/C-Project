#include<cctype>
#include<iostream>
#include<string>

using namespace std;

string ReverseString(string str);

int main() {
    string s = "programming";

    string t = ReverseString(s);

    cout << t << endl;

    return 0;
}


string ReverseString(string s) {
    // write your code here
    for (int i = s.length()-1; i >= 0; i--) {
        cout << s.at(i);
    }
    cout << endl;
    return s;
}