#include<stdio.h>
#define fi "input.txt"
#define fo1 "output1.txt"
#define fo2 "output2.txt"

void hienThi(float* a, int n);
void chenViTriK(float* a, int& n, float& x, int& k);
void xoaPT(float* a, int& n, int pos);
void xoaAm(float* a, int &n);

int main() {
	float* a,x;
	int n,k;
	FILE* f = fopen(fi, "r");
	if (f == NULL) {
		printf("Loi doc file!\n");
	}
	fscanf(f, "%d", &n);
	a = new float[n];
	for (int i = 0; i < n; i++) {
		fscanf(f, "%f", &a[i]);
	}
	fclose(f);
	hienThi(a, n);
	chenViTriK(a, n, x, k);
	xoaAm(a, n);
	return 0;
}

void hienThi(float* a, int n) {
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		printf("%.2f ", a[i]);
	}
}

void chenViTriK(float* a, int& n, float &x, int &k) {
	printf("\nNhap x: ");
	scanf("%f", &x);
	do {
		printf("Nhap k: ");
		scanf("%d", &k);
	} while (k<0 || k>n);
	n++;
	for (int i = n - 1; i > k; i--)
		a[i] = a[i - 1];
	a[k] = x;
	FILE* f = fopen(fo1, "w");
	fprintf(f, "%d\n%d\n", k, n);
	for (int j = 0; j < n; j++) {
		fprintf(f, "%.2f ", a[j]);
	}
	fclose(f);
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
	FILE* f = fopen(fo2, "w");
	fprintf(f, "%d\n", n);
	for (int j = 0; j < m; j++) {
		fprintf(f, "%d ", b[j]);
	}
	fprintf(f, "\n");
	for (int k = 0; k < n; k++) {
		fprintf(f, "%.2f ", a[k]);
	}
	fclose(f);
}