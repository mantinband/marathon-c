#include <stdio.h>
#define N 20

typedef struct{
    char name[20];
    int grades[N];
    int size;
} Student;

int getMean(Student *s);
Student *getStudentWithHighestGrade(Student *students, int numberOfStudents);

int main(){
    Student s1 = {
            "avi",
            {80,60,90,70,110},
            5
    };
    Student s2 = {
            "yossi",
            {80,100,100,70,110},
            5
    };

    Student s3 = {
            "dani",
            {80,40,90,30,110},
            5
    };

    Student s4 = {
            "haim",
            {80,90,90,70,110},
            5
    };
    Student students[] = {s1,s2,s3,s4};

    printf("The student with the highest grade is %s\n", getStudentWithHighestGrade(students, 4)->name);
    return 0;
}

/*  input: array of students
 *  output: pointer to student with highest grades mean
 * */
Student *getStudentWithHighestGrade(Student *students, int numberOfStudents) {
    int i=0;
    int highestGrade = 0;
    int currentMean = 0;
    Student *highestGradeStudent = NULL;

    for (i=0; i<numberOfStudents; i++){
        /*  get current student's mean  */
        currentMean = getMean(&students[i]);
        /*  check if it's the highest until now. if yes, remember him & the grade */
        if (currentMean > highestGrade){
            highestGrade = currentMean;
            highestGradeStudent = &students[i];
        }
    }
    return highestGradeStudent;
}

/*  input: pointer to student
 *  output: mean of grades
 * */
int getMean(Student *s){
    int i;
    int sumGrades = 0;

    for (i=0; i<s->size; i++){
        sumGrades += s->grades[i];
    }

    return sumGrades/s->size;
}