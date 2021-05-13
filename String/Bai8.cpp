#include<cctype>
#include<iostream>
#include<string>

using namespace std;

string MostFrequentCharacter(string s);

int main() {
    string s = "introduction to programming";

    string t = MostFrequentCharacter(s);
    cout << t << endl;
    return 0;
}


string MostFrequentCharacter(string s) {
    // write your code here
    string result;
    int i, len;
    int max = -1;

    int freq[256] = { 0 };

    len = s.length();

    for (i = 0; i < len; i++)
    {
        freq[s[i]]++;
    }

    for (i = 0; i < len; i++)
    {
        if (max < freq[s[i]])
        {
            max = freq[s[i]];
            result = s[i];
        }
    }
    return result;
}