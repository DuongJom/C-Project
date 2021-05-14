#include <stdio.h>

int ktTrungNhau(int a[], int n);

int main() {
    int d = 0;
    int n = 2;
    
    // test 1
    int a1[] = {1, 2, 5, 7, 2, 3, 6};
    int m1 = 1;
    if(ktTrungNhau(a1, 7) == m1) d++;
    
    // test 2
    int a2[] = {-2, 5, 4, 7, 9, 13, 3, 2};
    int m2 = 0;
    if(ktTrungNhau(a2, 8) == m2) d++;

    printf("You pass %d / %d test.\n", d, n);
    
    return 0;
}

int ktTrungNhau(int a[], int n) {
    // write your code here
    int flag=0; //khong trung lap
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
			if(a[i]==a[j]){
				flag=1; //phat hien trung lap
				break;
			}
	}
	if(flag==1) return 1;
    return 0;
}