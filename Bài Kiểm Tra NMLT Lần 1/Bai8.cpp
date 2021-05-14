#include <stdio.h>

int tong(int a[], int n);

int main() {
    int d = 0;
    int n = 2;
    
    // test 1
    int a1[] = {1, 2, 5, 7, 29, 31, 100};
    int m1 = 137;
    if(tong(a1, 7) == m1) d++;
    
    // test 2
    int a2[] = {-2, 5, 4, 7, 9, 13, 50, 150};
    int m2 = 216;
    if(tong(a2, 8) == m2) d++;

    printf("You pass %d / %d test.\n", d, n);
    
    return 0;
}

int tong(int a[], int n) {
    // write your code here
    int s=0;
	for(int i=0;i<n;i++)
	{
		int tmp=0;
		for(int j=0;j<i;j++)
			tmp+=a[j];
		if(a[i]>=tmp)
			s+=a[i];
	}
    return s;
}