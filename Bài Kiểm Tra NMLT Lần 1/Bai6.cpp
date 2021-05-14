#include <stdio.h>
#include <math.h>

int to_int(int a[], int n);

int main() {
    int d = 0;
    int n = 2;
    
    // test 1
    int a1[] = {1, 0, 1, 1, 1};
    int m1 = 23;
    if(to_int(a1, 5) == m1) d++;
    
    // test 2
    int a2[] = {1, 0, 1, 1, 1, 0, 0, 1};
    int m2 = 185;
    if(to_int(a2, 8) == m2) d++;

    printf("You pass %d / %d test.\n", d, n);
    
    return 0;
}

int to_int(int a[], int n) {
    // write your code here
	int kq=0,j=n-1;
    for(int i=0;i<n;i++){
		kq+=a[i]*pow(2,j);
		j--;
	}	
    return kq;
}