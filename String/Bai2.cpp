#include<cctype>
#include<iostream>
#include<string>

using namespace std;

int WordCounter(string s);

int main() {
    string s = "introduction to programming";
    int d;

    d = WordCounter(s);
    cout << d << endl;

    return 0;
}


int WordCounter(string s) {
    // write your code here
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == ' ') count++;
    }
    return count+1;
}