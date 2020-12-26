#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_SIZE 128
#define FIELD_LEN (DEF_SIZE / 2)
#define MAX_PAGE_COUNT 300

typedef struct BookListNode
{
	char author[DEF_SIZE];
	char title[DEF_SIZE * 2];
	int year;
	int pageCount;
	float price;
	struct BookListNode * next;
} BookListNode;

void swapBookListNodes(
	BookListNode * firstBookPtr, 
	BookListNode * secondBookPtr
);
void sortBookList(BookListNode * bookListHeadPtr);

int main()
{
	BookListNode * bookListHeadPtr = NULL;
	BookListNode * prevBookPtr = NULL;
	BookListNode * currBookPtr = NULL;
	FILE * filePtr;
	char buff[DEF_SIZE * 2] = "\0";
	int ch;
	int buffIdx = 0;
	char currField[FIELD_LEN];
	const char fields[][FIELD_LEN] = {
		"Author", "Title", "Year", "Pages", "Price"
	};
	const int fieldCount = sizeof fields / sizeof * fields;
	char value[DEF_SIZE * 2];
	int isValue = 0;

	filePtr = fopen("books.txt", "r");

	if (filePtr == NULL)
	{
		perror("Error opening the file");

		exit(EXIT_FAILURE);
	}

	currBookPtr = malloc(sizeof(BookListNode));

	while ((ch = getc(filePtr)) != EOF)
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
				strcpy(currBookPtr->author, value);
			}

			if (!strcmp(currField, "Title"))
			{
				strcpy(currBookPtr->title, value);
			}

			if (!strcmp(currField, "Year"))
			{
				currBookPtr->year = atoi(value);
			}

			if (!strcmp(currField, "Pages"))
			{
				currBookPtr->pageCount = atoi(value);
			}

			if (!strcmp(currField, "Price"))
			{
				currBookPtr->price = (float)atof(value);
				currBookPtr->next = NULL;

				if (bookListHeadPtr == NULL)
				{
					bookListHeadPtr = malloc(sizeof(BookListNode));
					prevBookPtr = malloc(sizeof(BookListNode));
					bookListHeadPtr = currBookPtr;
				}
				else prevBookPtr->next = currBookPtr;

				prevBookPtr = currBookPtr;
				currBookPtr = malloc(sizeof(BookListNode));
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

	currBookPtr = bookListHeadPtr;

	while (currBookPtr != NULL)
	{
		puts(currBookPtr->author);

		currBookPtr = currBookPtr->next;
	}

	puts("\n");
	currBookPtr = bookListHeadPtr;
	sortBookList(bookListHeadPtr);
	
	while (currBookPtr != NULL)
	{
		puts(currBookPtr->author);

		currBookPtr = currBookPtr->next;
	}

	fclose(filePtr);

	return 0;
}

void swapBookListNodes(
	BookListNode * firstBookPtr,
	BookListNode * secondBookPtr
)
{
	BookListNode * tmpBookPtr = NULL;

	tmpBookPtr = malloc(sizeof(BookListNode));
	tmpBookPtr = firstBookPtr;
	firstBookPtr = secondBookPtr;
	secondBookPtr = tmpBookPtr;
}

void sortBookList(BookListNode * bookListHeadPtr)
{
	BookListNode * currBookPtr = NULL;
	int res;

	currBookPtr = malloc(sizeof(BookListNode));
	currBookPtr = bookListHeadPtr;

	while (currBookPtr->next != NULL)
	{
		int res = strcmp(
			currBookPtr->author, 
			currBookPtr->next->author
		);
		
		if (res < 0)
		{
			swapBookListNodes(
				currBookPtr, 
				currBookPtr->next
			);
		}

		currBookPtr = currBookPtr->next;
	}
}