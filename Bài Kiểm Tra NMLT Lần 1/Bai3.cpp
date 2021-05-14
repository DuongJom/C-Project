#include <stdio.h>

int findK(int n);
unsigned long giaiThua(unsigned long n);

int main() {
    int ns[] = {12, 24, 450000000, 2000000000};
    int ks[] = {4, 4, 12, 15};
    int d = 0;
    int n = sizeof(ns)/sizeof(ns[0]);
    int i;
    for(i = 0; i < n; i++) {
        if(findK(ns[i]) == ks[i]) {
            d++;
        } else {
            printf("TEST_FAILED: findK(%d).\n", ns[i]);
        }
    }

    printf("You pass %d / %d test.\n", d, n);
    return 0;
}

int findK(int n) {
    // write your code here
    int k=1;
	while(giaiThua(k)<n) k++;
    return k;
}

unsigned long giaiThua(unsigned long n){
	if(n==1) return 1;
	return n*giaiThua(n-1);
}