#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void printWordsWithDoubling(char * word, ...);

int main()
{
	puts("The words with double letters:");
	printWordsWithDoubling("This", "code", "seems", "to", "be", "cool", NULL);

	return 0;
}

void printWordsWithDoubling(char * word, ...)
{
	va_list ap;
	va_start(ap, word);

	while (word != NULL)
	{
		int isDoubled = 0;

		for (int i = 1; i < strlen(word); i++)
		{
			if (word[i] == word[i - 1])
			{
				isDoubled = 1;

				break;
			}
		}

		if (isDoubled) puts(word);

		word = va_arg(ap, char *);
	}

	va_end(ap);
}