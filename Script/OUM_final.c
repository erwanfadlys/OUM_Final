#include <stdio.h>
#include <stdlib.h>

int num_students, num_courses, x, marks, course; //x placed there for loop 
long int student_id; //to store numbers with 4 bytes
char filename; //this is where the data name is stored

void intro(){
    printf("SIMPLE GRADING SYSTEM V1.1\n\n");
}

void marking(){ //marking function seperated from main, flexibility in coding the main func.
    if (marks >=80 && marks <=100){ 
            printf("\t\t%s", "Grade: A\n\n");
        }
        else if (marks >= 70 && marks <= 79){ 
            printf("\t\t%s", "Grade: B\n\n");
        }
        else if (marks >=60 && marks <=69){ 
            printf("\t\t%s", "Grade: C\n\n");
        }
        else if (marks >=50 && marks <=59){
            printf("\t\t%s", "Grade: D\n\n");
        }
        else if (marks >=0 && marks <=49){
            printf("\t\t%s", "Grade: F\n\n");
        }
        else{
            printf("\t\tMARK IS NOT GRADEABLE\n\n");
        }
}

void data(){
    printf("Please enter file name: ");
    scanf("%s", &filename);
}

int main(){
    intro(); //title of the program
    data(); //having different filename give flexibility in accessing different class/department

    FILE*fp;
    fp = fopen(&filename, "r"); //incompatible integer to pointer conversion passing 'char' to parameter of type 'const char *'; take the address with &
    if(!fp){
        perror("UNABLE TO OPEN FILE: ---> ");//to show error type
        return 0;
    }

    fscanf(fp, "%d", &num_students); //to scan first line of the file
    printf("\nNo. of Student: %d\n", num_students);
    fscanf(fp, "%d", &num_courses); //to scan second line of the file
    printf("No. of Courses: %d\n", num_courses);
    fscanf(fp, "%ld", &student_id); //to scan third line of the file
    printf("\nStudent ID: %ld\n", student_id);
    for (x= 0; x < num_courses; x++) { //to iterate the scan based on how many course we have.
        course += 1;//aesthetic for course counter

        fscanf(fp, "%d", &marks);
        printf("\n\t\tCourse #%d : %d\t\n", course, marks);
        marking();
    }
    
    fclose(fp);
}

