#include<stdio.h>
#include<stdlib.h>
#include<string.h>



char** concat(char *arr1[], int n1, char *arr2[], int n2)
{
  char *result = (char *)malloc(2*sizeof(char *));

  for(int i=0; i<2; i++)
  {
    result[i] = (char *)malloc(100 * sizeof(char));
  }

  int k=0;

  for(int i=0; i<n1; i++)
  {
    strcat(result[0], arr1[i]);
    if(i!=n1-1)
      strcat(result[0], " ");

  }

  for(int i=0; i<n2; i++)
  {
    strcat(result[1], arr2[i]);
    
    if(i!=n2-1)
      strcat(result[1], " ");

  }

  return result;

}

int main()
{
  char *arr3[] = {"I", "LOVE", "CODING"}, *arr4[] = {"THIS", "IS", "SPARTA"};
  char **result1 = concat(arr3, 3, arr4, 3);
  printf("%s, %s\n", result1[0], result1[1]);

  return 0;

}