#include<cctype>
#include<iostream>
#include<string>

using namespace std;

int StrongPasswordVerifier(string s);

int main() {
    string s = "Passw0rd";
    int d;
    d = StrongPasswordVerifier(s);
    cout << d << endl;
    return 0;
}


int StrongPasswordVerifier(string s) {
    // write your code here
    int n = s.length()-1;
    while (n >= 0) {
        if (s[n] == ' ') s.erase(n, 1);
        n--;
    }
    int numOfUp = 0, numOfLower = 0, numOfDigit = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') numOfUp++;
        if (s[i] >= 'a' && s[i] <= 'z') numOfLower++;
        if (s[i] >= '0' && s[i] <= '9') numOfDigit++;
    }
    if (s.length() >= 8 && numOfUp > 0 && numOfLower > 0 && numOfDigit > 0)
        return 1;
    else return 0;
}