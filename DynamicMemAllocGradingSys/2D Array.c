#include <stdio.h>

int main()
{
  int marks[10][2], r, c;  
  int studentNum;
  printf("Student Number: ");
  scanf("%d", &studentNum);
  printf("%d", r);
  for(r=0; r<studentNum; r++)
      {
      printf("Student %d\n----------\n", r+1);
      for(c=0; c<2; c++)
      {
      if(c==0){
      printf("Enter Mark for Quiz 1: ");
      }         
        else
        {
        printf("Enter Mark for Quiz 2: ");
        }
        
      scanf("%d", &marks[r][c]);
  }
  }
  printf("\nReport on Marks\n");
  printf("---------------\n");
  printf("              Q1    Q2\n");
  for(r=0; r<studentNum; r++)
  {
  printf("Student %d: ", r+1);
  for(c=0; c<2; c++)
  {
        printf("   %d ", marks[r][c]);
  }
  printf("\n");

  }

}
