#ifndef myassert
#include "stdio.h"
#include "dominion.h"

#define newassert(condition) \
{ \
	if(!(condition)) \
	{ \
		fprintf(stderr, "Assertion failed at %s inside %s: \n\tCondition: %s\n",\
		__FILE__, __FUNCTION__, (#condition)); \
	} \
}
#endif
