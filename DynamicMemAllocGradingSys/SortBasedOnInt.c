#include <stdio.h>


int i, j, temp;

void sort (int quiz[10]);

int main (){
    int quiz[10];
    for (i=0; i<4; i++){
        printf("Enter quiz marks %d:", i+1);
        scanf("%d", &quiz[i]);
    
    }

    sort(quiz);
    printf("\n\nSorted quiz marks\n================\n");
    for (i=0; i<4; i++){
        printf("Quiz number %d: ", i+1);
        printf("%d \n", quiz[i]);
    }
}

void sort( int quiz [10]){
    for (i=0; i<4; i++){
        for (j=0; j<4; j++){ 
            if (quiz[i]> quiz[j]){/* To change from low to highest, go for less than. Otherwise */
                temp=quiz[i];
                quiz[i]=quiz[j];
                quiz[j]=temp;
            }
        }
    }
}