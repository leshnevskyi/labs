#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_SIZE 128
#define FIELD_LEN (DEF_SIZE / 2)

typedef struct book
{
	char author[DEF_SIZE];
	char title[DEF_SIZE * 2];
	int year;
	int pageCount;
	float price;
} book;

int compareAuthorNames(const void * firstBook, const void * secondBook);
int compareYears(const void * firstBook, const void * secondBook);
void printNewestBooks(book * pFirstBook, int bookCount);

int main()
{
	book books[DEF_SIZE];
	FILE * pFile;
	char buff[DEF_SIZE * 2] = "\0";
	int ch;
	int buffIdx = 0;
	int bookIdx = -1;
	char currField[FIELD_LEN];
	const char fields[][FIELD_LEN] = {"Author", "Title", "Year", "Pages", "Price"};
	const int fieldCount = sizeof fields / FIELD_LEN;
	char value[DEF_SIZE * 2];
	int isValue = 0;

	pFile = fopen("books.txt", "r");

	if (pFile == NULL)
	{
		perror("Error opening the file");

		exit(EXIT_FAILURE);
	}

	while ((ch = getc(pFile)) != EOF)
	{
		if (!isValue)
		{
			for (int i = 0; i < fieldCount; i++)
			{
				if (strcmp(buff, fields[i])) continue;

				strcpy(currField, buff);
				memset(buff, 0, strlen(buff));
				buffIdx = 0;
			}
		}

		if (ch == ';')
		{
			strcpy(value, buff);

			for (int i = 0; i < strlen(value) - 2; i++)
			{
				value[i] = value[i + 2];
			}

			value[strlen(value) - 2] = '\0';

			if (!strcmp(currField, "Author"))
			{
				bookIdx++;
				strcpy(books[bookIdx].author, value);
			}

			if (!strcmp(currField, "Title"))
			{
				strcpy(books[bookIdx].title, value);
			}

			if (!strcmp(currField, "Year"))
			{
				books[bookIdx].year = atoi(value);
			}

			if (!strcmp(currField, "Pages"))
			{
				books[bookIdx].pageCount = atoi(value);
			}

			if (!strcmp(currField, "Price"))
			{
				books[bookIdx].price = (float)atof(value);
			}

			memset(value, 0, strlen(value));
		}

		if (ch == '\n')
		{
			memset(buff, 0, strlen(buff));
			buffIdx = 0;
			isValue = 0;

			continue;
		}

		if (ch == ':') isValue = 1;

		buff[buffIdx] = ch;
		buffIdx++;
	}

	fclose(pFile);

	qsort(books, bookIdx + 1, sizeof * books, compareAuthorNames);

	puts("Books sorted by author name in descending order: ");

	for (int i = 0; i <= bookIdx; i++)
	{
		puts(books[i].author);
	}

	puts("\n5 newest books: ");
	printNewestBooks(books, 5);

	return 0;
}

int compareAuthorNames(const void * firstBook, const void * secondBook)
{
	int res = strcmp(
		(* (book *)firstBook).author, 
		(* (book *)secondBook).author
	);

	return -res;
}

int compareYears(const void * firstBook, const void * secondBook)
{
	return -((* (book *)firstBook).year - (* (book *)secondBook).year);
}

void printNewestBooks(book * books, int bookCount)
{
	size_t booksSize = bookCount * sizeof(book);
	book * booksCpy = malloc(booksSize);
	
	memcpy(booksCpy, books, booksSize);
	qsort(booksCpy, bookCount, sizeof(book), compareYears);

	for (int i = 0; i < bookCount; i++)
	{
		printf("%s (%d) \n", booksCpy[i].title, booksCpy[i].year);
	}

	free(booksCpy);
}