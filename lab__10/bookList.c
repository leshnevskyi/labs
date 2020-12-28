#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookList.h"

int evalCondition(
	BookListNode * bookListNodePtr
)
{
	if (bookListNodePtr->pageCount < MAX_PAGE_COUNT)
	{
		return 1;
	}

	return 0;
}

int compareBookAuthorNames(
	BookListNode * firstBookPtr,
	BookListNode * secondBookPtr
)
{
	return strcmp(
		firstBookPtr->author,
		secondBookPtr->author
	);
}

void insertBookListNode(
	BookListNode ** bookListHeadPtr,
	BookListNode ** bookListNodePtr,
	int (* compare)(
		BookListNode * firstBookPtr,
		BookListNode * secondBookPtr
	)
)
{
	(* bookListNodePtr)->next = NULL;

	if (* bookListHeadPtr == NULL)
	{
		* bookListHeadPtr = malloc(sizeof(BookListNode));
		* bookListHeadPtr = * bookListNodePtr;
	}
	else if (compare(* bookListHeadPtr, * bookListNodePtr) < 0)
	{
		(* bookListNodePtr)->next = * bookListHeadPtr;
		* bookListHeadPtr = * bookListNodePtr;
	}
	else
	{
		BookListNode * currBookPtr = NULL;

		currBookPtr = malloc(sizeof(BookListNode));
		currBookPtr = * bookListHeadPtr;

		while (currBookPtr != NULL)
		{
			if (currBookPtr->next != NULL)
			{
				if (
					compare(currBookPtr, * bookListNodePtr) >= 0
					&& compare(currBookPtr->next, * bookListNodePtr) < 0
				)
				{
					(* bookListNodePtr)->next = currBookPtr->next;
					currBookPtr->next = * bookListNodePtr;

					break;
				}
			}
			else
			{
				currBookPtr->next = * bookListNodePtr;

				break;
			}

			currBookPtr = currBookPtr->next;
		}
	}
}

BookListNode * scanBookListFromFile(
	char filePath[DEF_SIZE]
)
{
	BookListNode * bookListHeadPtr = NULL;
	BookListNode * currBookPtr = NULL;
	FILE * filePtr = NULL;
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

	filePtr = fopen(filePath, "r");

	if (filePtr == NULL)
	{
		perror("Error opening the file");

		exit(EXIT_FAILURE);
	}

	currBookPtr = malloc(sizeof(BookListNode));

	if (currBookPtr == NULL)
	{
		perror("Error allocating current book pointer");

		exit(EXIT_FAILURE);
	}

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

			for (int i = 0; i < (int)strlen(value) - 2; i++)
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

				insertBookListNode(
					&bookListHeadPtr,
					&currBookPtr,
					compareBookAuthorNames
				);

				currBookPtr = malloc(sizeof(BookListNode));

				if (currBookPtr == NULL)
				{
					perror("Error allocating current book pointer");

					exit(EXIT_FAILURE);
				}
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

	free(currBookPtr);
	currBookPtr = NULL;

	fclose(filePtr);
	filePtr = NULL;

	return bookListHeadPtr;
}

void deleteBookListNode(
	BookListNode ** bookListHeadPtr,
	int (* evalCondition)(
		BookListNode * bookListNodePtr
	)
)
{
	BookListNode * prevBookPtr = NULL;
	BookListNode * currBookPtr = NULL;

	currBookPtr = malloc(sizeof(BookListNode));
	currBookPtr = * bookListHeadPtr;

	while (currBookPtr != NULL)
	{
		if (evalCondition(currBookPtr))
		{
			if (prevBookPtr == NULL)
			{
				* bookListHeadPtr = currBookPtr->next;

				currBookPtr = * bookListHeadPtr;
			}
			else
			{
				prevBookPtr->next = currBookPtr->next;
			}
		}

		if (prevBookPtr == NULL)
		{
			prevBookPtr = malloc(sizeof(BookListNode));
		}

		prevBookPtr = currBookPtr;
		currBookPtr = currBookPtr->next;
	}

	free(prevBookPtr);
	free(currBookPtr);
	prevBookPtr = NULL;
	currBookPtr = NULL;
}

void traverseBookList(
	BookListNode * bookListHeadPtr,
	void (* callback)(
		BookListNode * bookListNodePtr
	)
)
{
	BookListNode * currBookPtr = NULL;

	currBookPtr = malloc(sizeof(BookListNode));

	if (currBookPtr == NULL)
	{
		perror("Error allocating current book pointer");

		exit(EXIT_FAILURE);
	}

	currBookPtr = bookListHeadPtr;

	while (currBookPtr != NULL)
	{
		callback(currBookPtr);

		currBookPtr = currBookPtr->next;
	}

	free(currBookPtr);
	currBookPtr = NULL;
}

void printBookListNodeAuthor(
	BookListNode * bookListNodePtr
)
{
	puts(bookListNodePtr->author);
}