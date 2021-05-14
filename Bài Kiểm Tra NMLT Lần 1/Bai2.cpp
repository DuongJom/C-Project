#include <stdio.h>

double bmi(double w, double h);
const char* bmiType(double w, double h);

int main() {
    double ws[] = {40, 45, 70, 80, 90};
    double hs[] = {1.6, 1.67, 1.7, 1.65, 1.65};
    char * types[] = {"Suy dinh duong", "Thieu can", "Ly tuong", "Thua can", "Beo phi"};
    int d = 0;
    int n = sizeof(ws)/sizeof(ws[0]);
    int i;
    for(i = 0; i < n; i++) {
        if(bmiType(ws[i], hs[i]) == types[i]) {
            d++;
        } else {
            printf("TEST_FAILED: bmiType(%.2f, %.2f).\n", ws[i], hs[i]);
        }
    }

    printf("You pass %d / %d test.\n", d, n);
    
    return 0;
}

double bmi(double w, double h) {
    return w / h / h;
}

const char* bmiType(double w, double h) {
    char * type = NULL;
    // write your code here
    double x = bmi(w,h);
	if(x<16)
		type = (char*)"Suy dinh duong";
	else if(x>=16 && x<18.5)
		type = (char*)"Thieu can";
	else if(x>=18.5 && x<25)
		type = (char*)"Ly tuong";
	else if(x>=25 && x<30)
		type = (char*)"Thua can";
	else type = (char*)"Beo phi";
    
    return type;
}