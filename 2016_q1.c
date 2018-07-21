#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 20

/************/
/*  2016 q1 */
/************/

void encrypt(char *s, char **t);
void decrypt(char *t);
void encryptFile(FILE *fp);

int main(){
    char s[] = "abccccdmmxyyy";
    char *t = NULL;
    char fileName[MAX_FILE_NAME_LEN];
    FILE* fp;

    encrypt(s, &t);
    printf("%s\n", t);

    decrypt(t);

    printf("Enter file name:\n");
    fgets(fileName,MAX_FILE_NAME_LEN,stdin);
    fileName[strcspn(fileName,"\n")] = '\0';

    fp = fopen(fileName, "r");
    if (!fp){
        printf("ERROR: couldn't open file\n");
        exit(1);
    }

    encryptFile(fp);
    free(t);
    return 0;
}

/*  input: pointer to ascii file
 *  output: none;
 *
 *  functions creates new file and fills it as following:
 *  each line from original file is encrypted as described
 *  in function "encrypt" and then writte to output file
 * */
void encryptFile(FILE *fp) {
    char *line = NULL;
    char *t;
    size_t len = 0;
    FILE* outputFile;

    outputFile = fopen("encrypted.txt","w");
    if (!outputFile){
        printf("ERROR: couldn't open file");
        exit(1);
    }

    while (getline(&line,&len,fp) != -1){
        /*  remove enter    */
        line[strcspn(line,"\n")] = '\0';
        /*  encrypt line from input file    */
        encrypt(line, &t);
        /*  write encrypted line to output file */
        fprintf(outputFile, "%s\n", t);
        /*  free allocated space from heap  */
        free(t);
        free(line);
        /*  line = NULL is crucial for getline function to allocate space automatically */
        line = NULL;
    }
}

/*  input: string t containing numbers and letters
 *  output: none
 *
 *  function prints to screen string t as following:
 *  if t[i] is a digit, print the t[i] to the screen
 *  number of times as the number in t[i]
 * */
void decrypt(char *t) {
    int i, j, len;
    len = (int) strlen(t);

    for (i=0; i<len; i++){
        if (isdigit(t[i])){
            for (j=0; j < t[i]-'0'; j++){
                printf("%c",t[i+1]);
            }
        } else {
            printf("%c", t[i]);
        }
    }
    putchar('\n');
}

/*  input: string s, and uninitialized string t
 *  output: none
 *
 *  function creates new string and puts it in string as following:
 *  if a letter appears more than once in s, write the number of times
 *  it appears, followed by the letter.
 *  for example:
 *  if s is equal "abccccdmmxyyy", than t will equal ab4cd2mx3y
 * */
void encrypt(char *s, char **t){
    int i, len;
    int letterCounter;
    char *newS;
    int locInNewS = 0;

    len = (int) strlen(s);
    newS = (char*) malloc ((len+1)* sizeof(char));

    for (i=0, letterCounter = 1; i<len; i++, letterCounter = 1){
        /*  count number of times current letter appears    */
        while (s[i] == s[i+1]){
            letterCounter++;
            i++;
        }
        /*  add number before letter if it appears more than once   */
        if (letterCounter > 1){
            newS[locInNewS++] = (char) ('0' + letterCounter);
        }
        /*  write letter    */
        newS[locInNewS++] = s[i];

    }
    /*  allocate correct amount of space for t  */
    *t = (char*) malloc((strlen(newS)+1)* sizeof(char));
    strcpy(*t, newS);

    /*  free heap memory*/
    free(newS);
}