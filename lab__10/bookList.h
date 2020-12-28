#pragma once

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

BookListNode * scanBookListFromFile(
	char filePath[DEF_SIZE]
);

int evalCondition(
	BookListNode * bookListNodePtr
);

int compareBookAuthorNames(
	BookListNode * firstBookPtr,
	BookListNode * secondBookPtr
);

void insertBookListNode(
	BookListNode ** bookListHeadPtr,
	BookListNode ** bookListNodePtr,
	int (* compare)(
		BookListNode * firstBookPtr,
		BookListNode * secondBookPtr
	)
);

void deleteBookListNode(
	BookListNode ** bookListHeadPtr,
	int (* evalCondition)(
		BookListNode * bookListNodePtr
	)
);

void traverseBookList(
	BookListNode * bookListHeadPtr,
	void (* callback)(
		BookListNode * bookListNodePtr
	)
);

void printBookListNodeAuthor(
	BookListNode * bookListNodePtr
);