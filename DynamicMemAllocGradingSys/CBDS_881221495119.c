#include <stdio.h>
#include <stdlib.h> 
#include <string.h> //used for string functions lib


struct student //node
{
    char name [50]; //linked list of names
    char studentID [6]; //linked list of students ID
    float cgpa; //linked list of cgpa
};

void sortByName(struct student sortName[], int n); //function prototype for sortName
void sortByCgpa(struct student sortCgpa[], int n); //function prototype for sortCGPA
void displayInformation(struct student output[], int n);

int i, j, n; //declared as global due to repetitiveness of variable. This however will not impede the function and main script as those explicitly locally used.

int main()
{
    struct student *ptr; //node pointer initialised to ptr
    int sortMethod; //enriching the UI of the program
    float sum, highest; //to provide analysis of results of the program
    char topStudent [10];
    
    ptr = (struct student*) malloc(n * sizeof(struct student)); // allocating memory for n numbers of node

    printf("\nEnter the number of student: ");
    if (scanf("%d", &n) == 1){//to check the input. Scanf conversion return 1 upos success.
    }
    else{
        printf("\nPlease enter an integer.\nProgram will now terminate.\n\n");
        exit(EXIT_FAILURE);//can use exit(1) here.
    }

    for(i = 0; i < n; ++i) //this will loop the numbers of student entered as the i is less than n
    {
        //this is where the data accepted
        printf("\nEnter name : ");
        scanf("%s", ptr[i].name); //(ptr+i) used to access menory and place a data
        printf("Enter ID number : ");
        scanf("%s", ptr[i].studentID);
        if (strlen(ptr[i].studentID) < 6 || strlen(ptr[i].studentID) > 6){
            printf("\n*WARNING*\nPlease enter school ID number which consist of 6 character. EXAMPLE : AAXXXX\nProgram will now terminate.\n\n"); 
            exit(EXIT_FAILURE);
        }

        printf("Enter CGPA : ");
        scanf("%f", &ptr[i].cgpa);
        if (ptr[i].cgpa > 4){
            printf("\nPlease enter a valid CGPA value. EXAMPLE : Less than or equal to 4.00.\n\nProgram will now terminate.\n\n");
            exit(EXIT_FAILURE);
        }
    }
    
    printf("\nChoose sorting method\n=====================\n(1) for Name and (2) for CGPA: ");
    scanf("%d", &sortMethod);
    
    switch (sortMethod)
    {
    case 1: 
        sortByName(ptr, n);
        printf("\n\nNAME ASCENDING");
        displayInformation(ptr, n);
        break;
    
    case 2: 
        sortByCgpa(ptr, n);
        printf("\n\nCGPA DESCENDING");
        displayInformation(ptr, n);
        break;

    default:
        printf("\n!* No key provided were detected *!\nProceed displaying average cgpa for %d student.\n\n", n);
        displayInformation(ptr, n);
        break;
    }

    //calculating the average cgpa for total student
    for (i = 0; i < n; ++i){ 
        sum += ptr[i].cgpa;//summation of struct student.cgpa
        if (ptr[i].cgpa>highest){
            highest = ptr[i].cgpa;
            strcpy(topStudent, ptr[i].name);
        }
    }

    printf("\nAverage CGPA = %.2f", sum/n);//display the average value of cgpa
    printf("\n\nThe highest CGPA goes to %s which scored %.2f.\n", topStudent, highest);

    char rerun;

    printf("\nRerun program? 'y' for Yes or 'n' for No : ");
    scanf("%s", &rerun);
    
    if (rerun == 'y'){
        free(ptr);
        return main();
    }
    else{
        printf("\n\nEnd of program.\n\n");
        printf("********************************\nerwanfadlys@oum.edu.my - 881221495119001\n\n");
    }
    return 0;
}


void sortByCgpa(struct student sortCgpa[], int n){
    struct student temp;// Initialise struct student as temp as this function will pass argument from int main()
    
    for (i=0; i<n-1; i++) { //SIZE - 1 SO WE COMPARE THE OTHER ONE NOT THE SAME ONE
        for (j=i+1; j<n; j++) { //i+1 means next value of that array as sebelah i
            if (sortCgpa[i].cgpa<sortCgpa[j].cgpa){ //compare the value //compare 1st value greater than 2nd value
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
