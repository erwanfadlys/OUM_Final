#include <stdio.h>
#include <string.h>
 

struct student {
   char  studentName[50];
   char  studentID[50];
   float   CGPA;
};

/* function declaration */
void displayInformation( struct student *studentNum );
int main( ) {

   struct student Book1;        /* Declare Book1 of type Book */
   struct student Book2;        /* Declare Book2 of type Book */
 
   /* book 1 specification */
   strcpy( Book1.studentName, "C Programming");
   strcpy( Book1.studentID, "Nuha Ali"); 
   Book1.CGPA = 3.22;

   /* book 2 specification */
   strcpy( Book2.studentName, "Telecom Billing");
   strcpy( Book2.studentID, "Zara Ali");
   Book2.CGPA = 3.65;
 
   /* print Book1 info by passing address of Book1 */
   displayInformation( &Book1 );

   /* print Book2 info by passing address of Book2 */
   displayInformation( &Book2 );

   return 0;
}

void displayInformation( struct student *studentNum ) 
{
   printf( "Student Name: %s\n", studentNum->studentName );
   printf( "Student ID : %s\n", studentNum->studentID);
   printf( "Student CGPA : %.2f\n", studentNum->CGPA);
}