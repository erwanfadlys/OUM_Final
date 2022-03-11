#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void acceptData();
void sortData();
void displayData();
void freeLinkedList();

struct student{
    char studentId[10],studentName [10];
    float studentCgpa;
    struct student *next; 
};

struct student *head, *ptr, *display, *tempSort1, *tempSort2;

int i,studentNumber,  counter = 0;
float sum, tempFloat;
char tempStr[10], rerun [1];

int main(){

printf ("\nWelcome to Student Grade Database\n=================================\n\n");
printf ("Please enter number of students: ");

if (scanf("%d", &studentNumber) == 1){//to check the input. Scanf conversion return 1 upon success.
}
else{
       printf("\n*WARNING*\n\nPlease enter an integer.\nProgram will now terminate.\n\n");
       exit(EXIT_FAILURE);//can use exit(1) here.
}
for (i = 0; i < studentNumber; i++){ 
       /*Dynamically allocate memory for struct students */
       ptr = (struct student *) malloc (sizeof (struct student));
       acceptData();
       }      
       sortData();
       displayData();

       printf ("\nStudents total average of CGPA is %.2f\n", sum/studentNumber);
       printf ("\nDo you want to run again? Enter 'y' for yes and 'n' for no: ");
       scanf ("%s", rerun);
       if (strcmp (rerun, "y")== 0){
              freeLinkedList(head);
              sum = 0;
              return main();
       }
       else{
              printf("\n\nEnd of program.\n\n");
              printf("----------------------------------------\nerwanfadlys@oum.edu.my - 881221495119001\n\n");
       }
       return 0;
}

void acceptData(){
       printf("\nStudent %d : \nEnter student name: ",i+1);

       /*Accept data and stored in struct student member of studentID*/
       scanf("%s", ptr -> studentName);

       printf("Enter student ID Number: ");
       scanf("%s", ptr->studentId);
       if (strlen(ptr->studentId) < 6 || strlen(ptr->studentId) > 6){
            printf("\n*WARNING*\n\nPlease enter school ID number which consist of 6 character. EXAMPLE : AAXXXX\n\nYou have entered %lu character.\nProgram will now terminate.\n\n", strlen(ptr->studentId)); 
            exit(EXIT_FAILURE);
       } 
       
       printf("Enter student CGPA: ");
       if ((scanf("%f", &ptr->studentCgpa))== 0 || ptr->studentCgpa > 4 || ptr->studentCgpa < 0) {
              printf("\n*WARNING*\n\nPlease enter a valid CGPA value. EXAMPLE : Less than or equal to 4.00.\nProgram will now terminate.\n\n");
              exit(EXIT_FAILURE);
       };

       /*set the next node address to NULL indicating end of linked list*/
       ptr -> next = NULL;
       /*If the head  is equal to NULL, then save the data at first memory*/
       if (head == NULL){
              /*Copy ptr data into head data field*/
              head = ptr;
              }
       else {
              /*If its not, then point the next address and then copy data*/  
              ptr -> next = head;
              head = ptr;
              }
       }  


/*Sorting algo using bubble sort*/
void sortData(){
       /*Two temporary variable named tempSort1 and tempSort2 for data placeholder*/
       tempSort1 = head; tempSort2 = head; 
       while (tempSort1 != NULL){
              /*tempSort2 address pointing to next nodes address*/
              tempSort2 = tempSort1->next;
              while (tempSort2 != NULL){
                     /*if string comparison value between tempSort1 and tempSort2 value greater than 0*/
                     if (strcmp (tempSort1->studentName, tempSort2->studentName)>0){
                            /*Copy string value from tempSort1 name into temp node address*/
                            strcpy(tempStr, tempSort1->studentName);
                            strcpy(tempSort1->studentName, tempSort2->studentName);
                            strcpy(tempSort2->studentName, tempStr);

                            strcpy(tempStr , tempSort1->studentId);
                            strcpy(tempSort1->studentId , tempSort2->studentId);
                            strcpy(tempSort2->studentId , tempStr);

                            /*Copy float value from tempSort1 into temp node address */
                            tempFloat = tempSort1->studentCgpa;
                            tempSort1->studentCgpa = tempSort2->studentCgpa;
                            tempSort2->studentCgpa = tempFloat;
                     }
                     /*tempSort2 address pointing to next address to initiate next node*/
                     tempSort2 = tempSort2->next;
              }
              /*tempSort1 address pointing to next address to initiate next node*/
              tempSort1 = tempSort1 ->next;
       }
}
void freeLinkedList(){
       struct student * temp;
       while (head != NULL){
              temp = head;
              head = head->next;
              free(temp);
       }
}

void displayData(){
       /*Initialise ptr address to start of the linked list*/
       ptr = head;
       int counter = 1;
       printf("\n============================================\n\t   Displaying Information\n============================================\n");
       printf("\nNo\tName\t\tID\t\tCGPA\n");
       while (ptr != NULL){
       
              printf ("%d\t%s\t\t%s\t\t%.2f\n",counter++,ptr->studentName,ptr->studentId,ptr->studentCgpa);
              sum+= ptr->studentCgpa;
              /*Move to the next node*/
              ptr = ptr->next;
       }   
       printf("\n============================================\n");
}