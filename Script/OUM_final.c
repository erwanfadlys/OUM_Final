#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num_students, num_courses, x, total, marks, course, student_evaluated; //x placed there for loop 
long int student_id; //to store numbers with 4 bytes
char filename, export; //this is where the data name is stored

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

void data(){ //will not be hardcoded instead. Allow for future changes.
    printf("Please enter file name: ");
    scanf("%s", &filename);
}

void export_file(){  
    printf("\nExport the file as text?: y / n : ");
    scanf("%s", &export);

    if(export == 'y'){
        printf("\nPlease wait for the file to be exported.\nProgram ended.\n");
        freopen("output.txt","w",stdout);
    }
    else{
        printf("\nProgram ended.\n");
    }
}

int main(){
    clock_t start = clock(); //checking runtime of the program starting here.
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
    
    while (student_evaluated != num_students){
        student_evaluated += 1; //to close the loop once condition achieved.
        //printf("Student Evaluated: %d\n", student_evaluated); //testing parameter =, uncomment this if troubleshoot again
        
        fscanf(fp, "%ld", &student_id); //to scan third line of the file
        printf("\nStudent ID: %ld\n", student_id);
        course = 0; // this to ensure that the course# output does not repeatedly change.

        for (x= 0; x < num_courses; x++) { //to iterate the scan based on how many course we have.
            course += 1;//aesthetic for course counter
            fscanf(fp, "%d", &marks);
            printf("\n\t\tCourse #%d : %d\t\n", course, marks);
            marking();
            total = marks+marks; //
            printf("%d", total); //
        }
        total = 0;

    } 
    fclose(fp);

    

    clock_t stop = clock(); //to check how efficient the code is, im using the time.h to monitor the code runtime.
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTime elapsed in ms: %f\n", elapsed);
}

