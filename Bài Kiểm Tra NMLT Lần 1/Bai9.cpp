#include <stdio.h>

int isDuplicate(int a[], int b[], int n);
void doiTien(int a[], int b[], int n, int x);

int main() {
    int N = 9;
    int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int d = 0;
    int t = 2;
    
    // test 1
    int x1 = 2833;
    doiTien(a, b, N, x1);
    int c1[] = {1, 1, 0, 1, 1, 0, 1, 1, 5};
    if(isDuplicate(b, c1, N)) d++;
    
    // test 2
    int x2 = 88750;
    doiTien(a, b, N, x2);
    int c2[] = {50,100,100,100,100,100,100,100,100};
    if(isDuplicate(b, c2, N)) d++;

    printf("You pass %d / %d test.\n", d, t);
    
    return 0;
}

/* 
* Hàm này th?c hi?n vi?c d?i ti?n cho s? ti?n x. 
* B?n c?n thay d?i m?ng b[0..n-1] d? nó ch?a s? t? ti?n ?ng v?i m?i lo?i m?nh giá t? m?ng a[0..n-1].
*/
void doiTien(int a[], int b[], int n, int x) {
    // write your code here
    int m=0;
	
	for(int i=n-1;i>=0;i--){
		if(x>a[i]*100){
			x-=a[i]*100;
			b[m++]=100;
		}
		else{
			int soto = x/a[i];
			b[m++]=soto;
			x%=a[i];
		}
	}
}

/* 
* Hàm này ki?m tra xem m?ng a[0..n-1] và m?ng b[0..n-1] có trùng nhau hay không?
*/
int isDuplicate(int a[], int b[], int n) {
    // write your code here
	int d=0;
    for(int i=0;i<n;i++)
		if(a[i]==b[n-1-i]) d++;
	if(d==n) return 1;
    return 0;
}