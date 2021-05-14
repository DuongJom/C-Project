#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countSpecialCharacters(char * s);

int main() {
    int d = 0;
    int n = 2;
    
    // test 1
    char * s1 =  "Python 101 @ ute.";
    int d1 = 5;
    if(countSpecialCharacters(s1) == d1) d++;
    
    // test 2
    char * s2 = "This course is \"P4da\".";
	printf("s2 = %s\n",s2);
    int d2 = 6;
    if(countSpecialCharacters(s2) == d2) d++;

    printf("You pass %d / %d test.\n", d, n);
    
    return 0;
}

int countSpecialCharacters(char * s) {
    // write your code here
    int count=0;
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(!(s[i]>='a' && s[i]<='z') && !(s[i]>='A' && s[i]<='Z') && !(s[i]>='0' && s[i]<='9')){
			count++;
		}
	}
    return count;
}