#include<fstream>
#include<iostream>
#include<string.h>
#define questions "QUESTIONS.txt"
using namespace std;

struct QUESTION {
	char question[100];
	char option[5][100];
};

struct TOPIC {
	QUESTION quesTion;
	char ans;
	float diem;
};

void docFile(TOPIC a[], int& n) {
	fstream in;
	in.open(questions, ios::in);
	in >> n;
	for (int i = 0; i < n; i++) {
		in.getline(a[i].quesTion.question, 100);
		for (int j = 0; j < 5; j++) {
			in.getline(a[i].quesTion.option[j], 100);
		}
		in >> a[i].ans;
		in >> a[i].diem;
	}
	in.close();
}
int main() {
	TOPIC a[100];
	int n;
	char yourAns;
	float yourMark=0;
	int correctAns = 0;
	docFile(a, n);
	for (int i = 0; i < n; i++) {
		cout << "\nQuestion " << i + 1 << ": " << a[i].quesTion.question << endl;
		for (int j = 0; j < 5; j++) {
			cout << a[i].quesTion.option[j] << endl;
		}
		//cout << "Answer: " << a[i].ans<<endl;
		cout << "Your answer: ";
		cin >> yourAns;
		if (yourAns == a[i].ans) {
			yourMark += a[i].diem;
			correctAns++;
		}
	}
	cout << "You answered the " << correctAns << "/" << n << " correct!" << endl;
	cout << "Your mark: " << yourMark << endl;
	return 0;
}