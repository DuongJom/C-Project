#include<iostream>
#include<string>

using namespace std;

int CountConsonants(string s);

int main() {
    string s = "   introduction     to     programming    ";
    int d;

    d = CountConsonants(s);
    cout << d << endl;

    return 0;
}


int CountConsonants(string s) {
    // write your code here
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U' && s[i]!=' ')
            count++;
    }
    return count;
}