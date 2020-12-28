#include <stdlib.h>
#include "bookList.h"

#define FILE_PATH "books.txt"

int main()
{
	BookListNode * bookListHeadPtr = NULL;

	bookListHeadPtr = scanBookListFromFile(FILE_PATH);
	deleteBookListNode(&bookListHeadPtr, evalCondition);
	traverseBookList(bookListHeadPtr, printBookListNodeAuthor);

	return 0;
}