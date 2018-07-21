#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_FILE_NAME 20

/************/
/*  2015 q2 */
/************/

int getNumber(char *a);
int isGrowingSeries(char **strings, int size);
int isFileAGrowingSeries(char *fileName);

int getNumberOfLines(FILE *fp);

int main(){
    char *strings[] = {
            "a3 @ 67xx0b",
            "a3 @ 68xx0b",
            "a6 @ 27xx0b"};
    char fileName[20];

    printf("The series is%s growing\n",isGrowingSeries(strings, 3) ? "" : " not");

    printf("Enter file name:\n");
    fgets(fileName,MAX_FILE_NAME,stdin);
    fileName[strcspn(fileName,"\n")] = '\0';

    printf("The line in %s are%s growing\n", fileName, isFileAGrowingSeries(fileName) ? "" : " not");
    return 0;
}

/*  input: string
 *  output: number created by taking digits only from string
 * */
int getNumber(char *a) {
    int num = 0;
    int i;
    int len;

    len = (int) strlen(a);

    for (i=0; i<len; i++){
        if (isdigit(a[i])){
            num *= 10;
            num += a[i]-'0';
        }
    }

    return num;
}

/*  input: array of string & it's size
 *  output: 1 if number in strings[i] < strings[i+1] for each 0 < i < size-1. 0 otherwise
 * */
int isGrowingSeries(char **strings, int size) {
    /*  if there is only one string left    */
    if (size == 1){
        return 1;
    }

    printf("comparing %d with %d\n",getNumber(strings[0]),getNumber(strings[1]));

    /*  if current first and second place are ok, than continue checking.   */
    if (getNumber(strings[0]) < getNumber(strings[1])){
        return isGrowingSeries(strings+1, size-1);
    }

    return 0;
}


/*  input: filename
 *  output: 1 if lines in file represent a growing series
 *  as defined in "isGrowingSeries" function. 0 otherwise.
 * */
int isFileAGrowingSeries(char *fileName) {
    FILE* fp;
    char **lines = NULL;
    char *line = NULL;
    int numberOfLines, i ,isGrowing;
    size_t len = 0;

    fp = fopen(fileName, "r");

    if (!fp){
        printf("ERROR: couldn't open file\n");
        exit(1);
    }

    numberOfLines = getNumberOfLines(fp);
    /*  allocate space for array holding the strings    */
    lines = (char**) malloc (numberOfLines* sizeof(char*));

    /*  read lined from file to string array    */
    for (i=0; i<numberOfLines; i++){
        getline(&line, &len, fp);
        lines[i] = line;
        line = NULL;
    }

    /*  check if series is growing  */
    isGrowing = isGrowingSeries(lines,numberOfLines);

    /*  free heap memory    */
    for (i=0; i<numberOfLines; i++){
        free(lines[i]);
    }
    free(lines);

    return isGrowing;
}

/*  input: file pointer
 *  output: number of lines in file
 * */
int getNumberOfLines(FILE *fp) {
    char *line;
    size_t len;
    int numberOfLines = 0;

    while (getline(&line, &len, fp) != -1){
        numberOfLines++;
    }
    rewind(fp);
    return numberOfLines;
}
