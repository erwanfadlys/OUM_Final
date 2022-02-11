#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
    char name [50];
    char studentID [50];
    float cgpa;
};
//void sortStudentID( char studentID [50]);//aaargghhhhhhhhhhhh


int main()
{
    struct student *ptr;
    struct student temp;
    int i, j, n, result;
    float sum; 
   
    printf("Enter the number of student: ");
    scanf("%d", &n);

    // allocating memory for n numbers of struct student
    ptr = (struct student*) malloc(n * sizeof(struct student));

    for(i = 0; i < n; ++i) //this will loop the numbers of student entered as the i is less than n
    {
        //this is where the input requested by programme
        printf("\nStudent %d :", i+1);
        printf("\nEnter name : ");
        scanf("%s", (ptr+i)->name); //(ptr+i) used to allocate memory dynamically
        printf("Enter ID number : ");
        scanf("%s", (ptr+i)->studentID);
        printf("Enter CGPA : ");
        scanf("%f", &(ptr+i)->cgpa);//& used to point the float into cgpa struct, why? wallahualam..
    }

    //sortStudentID();
    //intsort (&ptr);//need to pass what here................................................................

    //this is where the information displayed.
    printf("\n\nDisplaying Information:\n\n");
    printf("No\t Name\t  ID\t CGPA\n");
    for(i = 0; i < n; ++i){
        printf("%d\t %s\t  %s\t %.2f\t\n",i+1, (ptr+i)->name, (ptr+i)->studentID, (ptr+i)->cgpa);
    }

    //calculating the average cgpa for total student
    for (i = 0; i < n; ++i){ 
        sum += (ptr+i)->cgpa; //summation of struct student.cgpa
    }
    printf("\nAverage CGPA = %.2f\n\n", sum/n);//display the average value of cgpa
    return 0;
}

/*function for int sort*/


/*
void sortStudentID( char studentID [50])
{
    struct student temp;
    int i, j;
    char name[50];
    for(i = 0; i < 3-1; i++) {
        for (j = i+1; j <3; j++){
            if (strcmp(name[i],[name[j])>0){

                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);

            }
        }
    }
}*/
            