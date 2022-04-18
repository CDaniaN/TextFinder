/*
Dania Nasereddin
4-7-21
This program prompts the reader to choose what to look for in the text file and
then prints the words for that key word chosen
*/
#include <stdio.h>
#include <string.h>
#define MAX 1000

int strindex(char s[], char t[]) //s input, t term
{
  int i, j, k;

  for(i = 0; s[i] != '\0'; i++) //search the array and keeps our place!
  {
    for(j = i, k = 0; t[k] !='\0' && s[j] == t[k]; j++ , k++)//j searches where we are starting with i in s, k searches t
    ; //search for a match!!!
    if( k > 0 && t[k] == '\0') //if we found a match
    {
      return i;
    }
  }
  return -1; //returns -1 if not found
}

int main()
{
  int choice;
  printf("Which Token would you like to search the file for?\n"); //prompts options to user
  printf("1. Food\n");
  printf("2. Colors\n");
  printf("3. People\n");
  scanf("%d", &choice); //stores their choice

  FILE * fpointer = fopen("sample2.txt", "r"); //opens text file
  char match[MAX];

  if(choice == 1) //if choice is food
  {
    char token[] = "Food"; //make search word food
    int length = strlen(token);
    printf("Displaying Food\n");
    while(fgets(match, MAX, fpointer) != NULL) //loops until its null
    {
      if(strindex(match,token) >= 0) //returns -1 if there is no match
      {
        for(int i = length + 1; i < strlen(match); i++) //go through the match
        {
          if(match[i] == ' ') //if empty space
          {
            printf("\n"); //new line
          }
          else
          {
            printf("%c", match[i]); //print word
          }
        }
      }
    }
  }

  else if(choice == 2) //if choice is colors
  {
    char token[] = "Colors"; //make search word colors
    int length = strlen(token);
    printf("Displaying Colors\n");
    while(fgets(match, MAX, fpointer) != NULL) //keep reading lines until empty line is entered
    {
      if(strindex(match,token) >= 0) //returns -1 if there is no match
      {
        for(int i = length + 1; i < strlen(match); i++) //go through the match
        {
          if(match[i] == ' ')//if empty space
          {
            printf("\n");//new line
          }
          else
          {
            printf("%c", match[i]);//print word
          }
        }
      }
    }
  }

  else if(choice == 3) //if choice is people
  {
    char token[] = "People"; //make search word people
    int length = strlen(token);
    printf("Displaying People\n");
    while(fgets(match, MAX, fpointer) != NULL) //keep reading lines until empty line is entered
    {
      if(strindex(match,token) >= 0) //returns -1 if there is no match
      {
        for(int i = length + 1; i < strlen(match); i++)//go through the match
        {
          if(match[i] == ' ')//if empty space
          {
            printf("\n");//new line
          }
          else
          {
            printf("%c", match[i]);//print word
          }
        }
      }
    }
  }

  fclose(fpointer); //close file

  return 0;

}
