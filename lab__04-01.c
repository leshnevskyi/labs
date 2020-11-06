#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1024

unsigned countWords(char * str);

int main()
{
  char str[MAX_STR_LEN];
  char * substr = "do";
  char filteredStr[MAX_STR_LEN];

  fgets(str, MAX_STR_LEN, stdin);
  
  unsigned count = countWords(str);
  
  const char * delim = " ";
  char words[10][10];
  char * tok = strtok(str, delim);
  
  for (int i = 0; tok != NULL; i++)
  {
    strcpy(words[i], tok);
    tok = strtok(NULL, delim);
  }
  
  for (int i = 0; i < 10; i++)
  {
    if (strstr(words[i], substr) == NULL)
    {
      strcat(filteredStr, strcat(words[i], " "));
    }
  }
  
  printf("%s\n", filteredStr);

  return 0;
}

unsigned countWords(char * str)
{
  unsigned wordCount = 0;
  unsigned isInWord = 0;
  char tok;
  
  while (* str)
  {
    tok = * str;
    
    if (isspace(tok)) isInWord = 0;
    else if (!isInWord)
    {
      wordCount++;
      isInWord = 1;
    }
    
    str++;
  }
  
  return wordCount;
}
