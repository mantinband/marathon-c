#include <stdio.h>

/************/
/*  2014 q2 */
/************/


int isSorted(int *a, int size);
int isConcSorted(int a1[], int size1, int a2[], int size2);

int main(){
    int a[] = {1,2,3,4,5,6,7};
    int b[] = {1,1,3,4,5,6,7};

    printf("the array is%s sorted\n",isSorted(a,7) ? "" : " not");
    printf("the array is%s sorted\n",isSorted(b,7) ? "" : " not");

    return 0;
}

/*  input: 2 Integer arrays and their length
 *  output: 1 if last number in first array is smaller than first number in second array.
 *          0 otherwise
 * */
int isConcSorted(int a1[], int size1, int a2[], int size2){
    return a1[size1-1] < a2[0];
}


/*  input: Integer array and it's size
 *  output: 1 if the array is sorted. 0 otherwise
 * */
int isSorted(int *a, int size){
    int i;

    for (i=0; i<size-1; i++){
        if (!isConcSorted(a,i+1,a+i+1,size-i-1)){
            return 0;
        }
    }

    return 1;
}