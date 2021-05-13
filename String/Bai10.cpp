#include<iostream>
#include<string>

using namespace std;

void PrintDecimalAnalysis(string x);

int main() {
    string x = "256.37";
    PrintDecimalAnalysis(x);
    return 0;
}


void PrintDecimalAnalysis(string x) {
    // write your code here
    bool check = true;
    for (int i = 0; i < x.length(); i++) {
        if ((x[i] <= '0' || x[i] >= '9') && x[i] != '.')
        {
            check = false;
            break;
        }
    }
    if (check == true)
    {
        string a = "", b = "";
        int pos;
        for (int i = 0; i < x.length(); i++) {
            if (x[i] == '.')
                pos = i;
        }
        for (int j = 0; j < pos; j++) {
            a += x[j];
        }
        for (int j = pos + 1; j < x.length(); j++) {
            b += x[j];
        }
        int n = 0;
        int k = a.length() - 1;
        while (n <= a.length() - 1) {
            cout << a[n] << "*10^" << k << " + ";
            n++;
            k--;
        }
        n = 0;
        k = -1;
        while (n <= b.length() - 1) {
            if (n < b.length() - 1) {
                cout << b[n] << "*10^" << k << " + ";
            }
            else {
                cout << b[n] << "*10^" << k;
            }
            n++;
            k--;
        }
    }
    else {
        cout << "input khong hop le";
    }
    
}