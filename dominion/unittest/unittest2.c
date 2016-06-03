#include "../dominion.h"
#include "../myassert.h"

int main() {
	int i;
	int* result = kingdomCards(1,2,3,4,5,6,7,8,9,10);
	for(i=0; i<10; i++){
		newassert(result[i] == i+1);
	}
	return 0;
}
