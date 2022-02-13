#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
    char name [50];
    char studentID [50];
    float cgpa;
};

void sortByName(struct student sortName[], int n);
void sortByCgpa(struct student sortCgpa[], int n);
void displayInformation(struct student nameSort[], int n);

int i, j, n; //declared as global due to repetetive of var. This however will not impede the function and main script as those explicitly locally used.

int main()
{
    struct student *ptr;
    int result;
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
        scanf("%s", (ptr+i)->name); //(ptr+i) used to access menory and place a data
        printf("Enter ID number : ");
        scanf("%s", (ptr+i)->studentID);
        printf("Enter CGPA : ");
        scanf("%f", &(ptr+i)->cgpa);//& used to point the float into cgpa struct, why? wallahualam.
    }
    
    displayInformation(ptr, n);
    printf("\nChoose sorting method\n1 for Name and 2 for CGPA: ");
    scanf("%d", &result);

    if (result == 1){
        sortByName(ptr, n);
        printf("\n\nNAME ASCENDING");
        displayInformation(ptr, n);
    }
    else if(result == 2){
        sortByCgpa(ptr, n);
        printf("\n\nCGPA ASCENDING");
        displayInformation(ptr, n);
    }

    else{
        printf("\n!* No key given detected *!\nProceed displaying average cgpa for %d student.\n\n", n);
    }
    //calculating the average cgpa for total student
    for (i = 0; i < n; ++i){ 
        sum += (ptr+i)->cgpa; //summation of struct student.cgpa
    }

    printf("\nAverage CGPA = %.2f", sum/n);//display the average value of cgpa
    printf("\n\nEnd of program.\n\n");
    return 0;
}


void sortByCgpa(struct student sortCgpa[], int n){
    struct student temp;// create temporary struct, copy student struct and initialise with temp
    
    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) { //i+1 means next value of that array
            if (sortCgpa[i].cgpa>sortCgpa[j].cgpa){ //compare the value
                temp=sortCgpa[i]; 
                sortCgpa[i]=sortCgpa[j];
                sortCgpa[j]=temp;
            }
        }
    }
}

void sortByName(struct student sortName[], int n){ //
    struct student temp;// create temporary struct, copy student struct and initialise with temp

    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) { //i+1 means next value of that array
            //if (s[i].cgpa>s[j].cgpa){ //compare the value
            if(strcmp(sortName[i].name,sortName[j].name) > 0 ){//selection sort using string compare
                temp=sortName[i]; 
                sortName[i]=sortName[j];
                sortName[j]=temp;
            }
        }
    }
}

void displayInformation(struct student output[], int n){ 
    for (i = 0; i < n; i++){
        printf("\n\nDisplaying Information:\n\n");
        printf("No.\tName\t\tID\t\tCGPA\n");
        for(i = 0; i < n; ++i){
            printf("%d\t%s\t\t%s\t\t%.2f\n",i+1, (output+i)->name, (output+i)->studentID, (output+i)->cgpa);
        }
    }
}