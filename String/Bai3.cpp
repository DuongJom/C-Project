#include<cctype>
#include<iostream>
#include<string>

using namespace std;

float AverageNumberOfLetters(string s);

int main() {
    string s = "introduction to programming";
    float d;

    d = AverageNumberOfLetters(s);
    cout << d << endl;

    return 0;
}


float AverageNumberOfLetters(string s) {
    // write your code here
    int numOfWord = 0;
    int numOfChar = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == ' ') numOfWord++;
        if (s.at(i) != ' ') numOfChar++;
    }
    return numOfChar*1.0/(numOfWord+1);
}

