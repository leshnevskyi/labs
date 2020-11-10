#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1024

unsigned countWords(char * str);
char ** substractWords(char * str);
char * filterStr(char * str, char * substr);

int main()
{
  char str[MAX_STR_LEN], substr[MAX_STR_LEN];
  char * filteredStr;

  puts("Enter a string: ");
  fgets(str, MAX_STR_LEN, stdin);

  puts("\nEnter a substring: ");
  scanf("%s", substr);

  filteredStr = filterStr(str, substr);

  printf("\nOriginal string: \n%s \n", str);
  printf("Filtered string: \n%s \n", filteredStr);

  return 0;
}

unsigned countWords(char * str)
{
  unsigned wordCount = 0;
  unsigned short isInWord = 0;
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

char ** substractWords(char * str)
{
  char * strCpy;
  char ** words, * tok;
  const char * delim = "  ";
  unsigned wordCount;
  unsigned short wordLen;

  strCpy = malloc(strlen(str) * sizeof(char));

  if (strCpy == NULL) exit(1);

  strcpy(strCpy, str);
  wordCount = countWords(strCpy);
  words = malloc(wordCount * sizeof(char *));
  tok = strtok(strCpy, delim);

  for (short i = 0; tok != NULL; i++)
  {
    wordLen = (unsigned)strlen(tok);
    words[i] = malloc(wordLen * sizeof(char));

    if (words[i] == NULL) exit(1);

    strcpy(words[i], tok);
    tok = strtok(NULL, delim);
  }

  return words;
}

char * filterStr(char * str, char * substr)
{
  char * filteredStr;
  char ** words;
  unsigned wordCount;

  filteredStr = malloc(strlen(str) * sizeof(char));
  * filteredStr = '\0';

  if (filteredStr == NULL) exit(1);

  words = substractWords(str);
  wordCount = countWords(str);

  for (int i = 0; i < wordCount; i++)
  {
    if (strstr(words[i], substr) == NULL)
    {
      strcat(filteredStr, strcat(words[i], " "));
    }
  }

  return filteredStr;
}
