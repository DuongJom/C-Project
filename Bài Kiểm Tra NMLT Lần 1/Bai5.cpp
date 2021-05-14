#include <stdio.h>
#include <string.h>

char* transform(char* s);
char tmp[100];

int main() {
    int d = 0;
    int n = 2;

    // test 1
    char* s1 = (char*)"python";
    char* t1 = (char*)"qrkwbs";
    if (strcmp(transform(s1), t1) == 0) d++;
    // test 2
    char* s2 = (char*)"gray";
    char* t2 = (char*)"bduj";
    if (strcmp(transform(s2), t2) == 0) d++;
    printf("You pass %d / %d test.\n", d, n);
    printf("s2 = %s\nt2 = %s", transform(s2), t2);
	printf("\n%c --> %c",119,119+3);
    return 0;
}

char* transform(char* s) {
    // write your code here
    int n = strlen(s);
    for (int j = 0; j < n; j++) {
        tmp[j] = s[j];
    }
	tmp[n]='\0';
    for (int i = 0; i < n; i++) {
        if ((tmp[i] >= 'a' && tmp[i] <= 'w') || (tmp[i] >= 'A' && tmp[i] <= 'W'))
            tmp[i] += 3;
        else if ((tmp[i] >= 'x' && tmp[i] <= 'z') || (tmp[i] >= 'X' && tmp[i] <= 'Z'))
            tmp[i] -= 23;
    }
    strrev(tmp);
    return tmp;
}