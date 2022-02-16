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
void displayInformation(struct student output[], int n);

int i, j, n; //declared as global due to repetitiveness of var. This however will not impede the function and main script as those explicitly local.

int main()
{
    struct student *ptr;
    int result;
    float sum, highest;
    char topStudent [10];
    
    printf("Enter the number of student: ");
    scanf("%d", &n);

    // allocating memory for n numbers of struct student
    ptr = (struct student*) malloc(n * sizeof(struct student));

    for(i = 0; i < n; ++i) //this will loop the numbers of student entered as the i is less than n
    {
        //this is where the data accepted
        printf("\nStudent %d :", i+1);
        printf("\nEnter name : ");
        scanf("%s", ptr[i].name); //(ptr+i) used to access menory and place a data
        printf("Enter ID number : ");
        scanf("%s", ptr[i].studentID);
        printf("Enter CGPA : ");
        scanf("%f", &ptr[i].cgpa);//& used to point the float into cgpa struct, why? wallahualam.
    }
    
    displayInformation(ptr, n);
    printf("\nChoose sorting method\n=====================\n(1) for Name and (2) for CGPA: ");
    scanf("%d", &result);
    
    switch (result)
    {
    case 1: 
        sortByName(ptr, n);
        printf("\n\nNAME ASCENDING");
        displayInformation(ptr, n);
        break;
    
    case 2: 
        sortByCgpa(ptr, n);
        printf("\n\nCGPA ASCENDING");
        displayInformation(ptr, n);
        break;

    default:
        printf("\n!* No key provided were detected *!\nProceed displaying average cgpa for %d student.\n\n", n);
        break;
    }

    //calculating the average cgpa for total student
    for (i = 0; i < n; ++i){ 
        sum += ptr[i].cgpa;//summation of struct student.cgpa
        if (ptr[i].cgpa>highest){
            highest = ptr[i].cgpa;
            strcpy(topStudent, ptr[i].name );
        }
    }

    printf("\nAverage CGPA = %.2f", sum/n);//display the average value of cgpa
    printf("\n\nThe highest CGPA goes to %s which scored %.2f.", topStudent, highest);//
    printf("\n\nEnd of program.\n\n");
    return 0;
}


void sortByCgpa(struct student sortCgpa[], int n){
    struct student temp;// Initialise struct student as temp as this function will pass argument from int main()
    
    for (i=0; i<n-1; i++) { //SIZE - 1 SO WE COMPARE THE OTHER ONE NOT THE SAME ONE
        for (j=i+1; j<n; j++) { //i+1 means next value of that array as sebelah i
            if (sortCgpa[i].cgpa>sortCgpa[j].cgpa){ //compare the value //compare 1st value greater than 2nd value
                temp=sortCgpa[i]; //use temp for tahanan sementara..supaya value tak hilang 
                sortCgpa[i]=sortCgpa[j]; //value kedua masuk value pertama
                sortCgpa[j]=temp; //temp masuk ke dalam value kedua
            } // so ni ulang2 check value if the 1st value greater than the 2nd value, it proceed the iteration swap each other.. kalau tak dia skip
        }
    }
}

void sortByName(struct student sortName[], int n){ //
    struct student temp;// create temporary struct, copy student struct and initialise with temp

    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) { //i+1 means next value of that array
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
            printf("%d\t%s\t\t%s\t\t%.2f\n",i+1, output[i].name, output[i].studentID, output[i].cgpa);
        }
    }
}
