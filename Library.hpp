#ifndef _LIBRARY
#define _LIBRARY

#include "Book.hpp"


struct Library
{
	Book booklist[80];
	int listSize;
	int bookCount;

	void InitLibrary();


};

#endif