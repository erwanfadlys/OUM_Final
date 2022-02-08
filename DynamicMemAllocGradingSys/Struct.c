#include <stdio.h>
#include <string.h>
 
int i,j;

struct student {
   char  studentName[50];
   char  studentID[50];
   float CGPA;
};

/* function declaration */
void displayInformation( struct student *studentNum );
int main( ) {

   struct student Book1;        /* Declare Book1 of type Book */
   struct student Book2;
   struct student Book3;         /* Declare Book2 of type Book */
 
   /* book 1 specification */
   strcpy( Book1.studentName, "Amani");
   strcpy( Book1.studentID, "AA1001"); 
   Book1.CGPA = 3.67;

   /* book 2 specification */
   strcpy( Book2.studentName, "Irfan");
   strcpy( Book2.studentID, "AA1002");
   Book2.CGPA = 3.29;
 
   /* Student 3 specification */
   strcpy( Book3.studentName, "Irfan");
   strcpy( Book3.studentID, "AA1002");
   Book3.CGPA = 3.78;
   /* print Book1 info by passing address of Book1 */
   displayInformation( &Book1 );

   /* print Book2 info by passing address of Book2 */
   displayInformation( &Book2 );

   displayInformation( &Book3 ); 

   for (i=0; i<3-1; i++)
{
   for (j=0; j<3; j++){
      
   }
}
   return 0;
}

void displayInformation( struct student *studentNum ) 
{
   printf( "\nStudent Name: %s\n", studentNum->studentName );
   printf( "Student ID : %s\n", studentNum->studentID);
   printf( "Student CGPA : %.2f\n\n", studentNum->CGPA);
}