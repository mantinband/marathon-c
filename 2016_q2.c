#include <stdio.h>

/************/
/*  2016 q2 */
/************/

int getNumberOfOccurrences(int *s, int *e, int n);

int main(){
    int a[] = {1,2,5,3,2,1,6,5,3,2,1,2,3,3,4,5,6};

    printf("3 appears %d times\n", getNumberOfOccurrences(a,a+16,3));
    return 0;
}

/*  input: pointer to beginning of array of Integers, pointer to it's end and a number 'n'
 *  output: number of occurrences of n in array
 * */
int getNumberOfOccurrences(int *s, int *e, int n){
    if (s > e){
        return 0;
    }
        
    if (s == e){
        return (s[0] == n) + getNumberOfOccurrences(s+1,e-1,n);
    }

    return (s[0] == n) + (e[0] == n) + getNumberOfOccurrences(s+1,e-1,n);
}