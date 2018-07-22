#include <stdio.h>
#include <ctype.h>

void skipNotDigits(char *s, int *loc);

int getNumber(char *s, int *loc);

int isGood(char *s);

int main(){
    printf("is%s same length\n", isGood("ssdfaasdf fdas 123   345") ? "" : " not");

    return 0;
}

int isSameLength(int a, int b){
    if (!a && !b){
        return 1;
    }
    if (!a || !b){
        return 0;
    }

    return isSameLength(a/10, b/10);
}

int isGood(char *s){
    int loc = 0;
    int n1=0, n2=0;

    skipNotDigits(s,&loc);

    n1 = getNumber(s,&loc);

    skipNotDigits(s,&loc);

    n2 = getNumber(s,&loc);

    printf("%d %d\n",n1, n2);

    return isSameLength(n1,n2);
}

int getNumber(char *s, int *loc) {
    int n = 0;

    while (isdigit(s[*loc])){
        n *= 10;
        n += s[*loc] - '0';
        (*loc)++;
    }
    return n;
}

void skipNotDigits(char *s, int *loc) {
    while (!isdigit(s[*loc])){
        (*loc)++;
    }
}
