#include<fstream>
#include<iostream>
#define fi "input.txt"
#define fo1 "output1.txt"
#define fo2 "output2.txt"
using namespace std;

void hienThi(float* a, int n);
void chenViTriK(float* a, int& n, float& x, int& k);
void xoaPT(float* a, int& n, int pos);
void xoaAm(float* a, int &n);

int main() {
	float* a,x;
	int n,k;
	fstream in;
	in.open(fi, ios::in);
	in >> n;
	a = new float[n];
	for (int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
	hienThi(a, n);
	cout << endl;
	chenViTriK(a, n, x, k);
	hienThi(a, n);
	cout << endl;
	xoaAm(a, n);
	hienThi(a, n);
	return 0;
}

void hienThi(float* a, int n) {
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i]<<" ";
	}
}

void chenViTriK(float* a, int& n, float &x, int &k) {
	cout << "Nhap x: ";
	cin >> x;
	do {
		cout << "Nhap vi tri k: ";
		cin >> k;
	} while (k<0 || k>n);
	n++;
	for (int i = n - 1; i > k; i--)
		a[i] = a[i - 1];
	a[k] = x;
	fstream out;
	out.open(fo1,ios::out);
	out << k << endl<<n<<endl;
	for (int i = 0; i < n; i++) {
		out << a[i] << " ";
	}
	out.close();
}

void xoaPT(float* a, int& n, int pos) {
	if (n <= 0) {
		return;
	}
	if (pos < 0) {
		pos = 0;
	}
	else if (pos >= n) {
		pos = n - 1;
	}
	for (int i = pos; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	--n;
}
void xoaAm(float* a, int &n) {
	int b[100], m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			xoaPT(a, n, i);
			b[m++] = i;
		}
	}
	fstream out;
	out.open(fo2, ios::out);
	out << n<<endl;
	for (int i = 0; i < m; i++) {
		out << b[i]<<" ";
	}
	out << endl;
	for (int i = 0; i < n; i++) {
		out << a[i] << " ";
	}
	out.close();
}