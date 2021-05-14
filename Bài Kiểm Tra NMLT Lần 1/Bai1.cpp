#include <stdio.h>

int fun1(int start, int end, int step);
int fun2(int start, int end, int step);

int main() {
    int starts[] = {17, 21};
    int ends[] = {8, 10};
    int steps[] = {-2, -3};
    int i;
    int d = 0;
    int n = sizeof(starts)/sizeof(starts[0]);
    for(i = 0; i < n; i++) {        
        if(fun1(starts[i], ends[i], steps[i]) == fun2(starts[i], ends[i], steps[i])) {
            d++;
        } else {
            printf("TEST_FAILED: fun2(%d, %d, %d).\n", starts[i], ends[i], steps[i]);
        }
    }
    printf("You pass %d / %d test.\n", d, n);
    
    return 0;
}

int fun1(int start, int end, int step) { 
    int s = 0;
    int i;
    for(i = start; i >= end; i += step) {
        s = s + i;
    } 
    return s;
}

int fun2(int start, int end, int step) {
    int s = 0;
    int i=start;
    // write your code here
    while(i>=end){
		s+=i;
		i+=step;
	}
    return s;
}