#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
    char name [50];
    char studentID [6];
    float cgpa;
};

void sortByStr(struct student s[], int n);

int main()
{
    struct student *ptr;
    int i, j, n, result;
    float sum; 
   
    printf("Enter the number of student: ");
    scanf("%d", &n);

    // allocating memory for n numbers of struct student
    ptr = (struct student*) malloc(n * sizeof(struct student));

    for(i = 0; i < n; ++i) //this will loop the numbers of student entered as the i is less than n
    {
        //this is where the data accepted
        printf("\nStudent %d :", i+1);
        printf("\nEnter name : ");
        scanf("%s", (ptr+i)->name); //(ptr+i) used to allocate memory dynamically
        printf("Enter ID number : ");
        scanf("%s", (ptr+i)->studentID);
        printf("Enter CGPA : ");
        scanf("%f", &(ptr+i)->cgpa);//& used to point the float into cgpa struct, why? wallahualam.
    }

    

    sortByFloat(ptr, n);
    
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

/*function for chart sort*/



void sortByStr(struct student s[], int n){ //
    int i, j;
    struct student temp;// create temporary struct, copy student struct and initialise with temp
    
    //loop
    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) { //i+1 means next value of that array
            //if (s[i].cgpa>s[j].cgpa){ //compare the value
            if(strcmp(s[i].name,s[j].name) > 0 ){
                temp=s[i]; 
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}