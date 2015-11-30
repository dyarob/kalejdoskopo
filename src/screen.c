#include "libkalejdoskopo.h"
#include "stdlib.h"	/*atexit*/

void	screeninit(void) {
	screen = (char *)malloc(100);
	atexit(screenexit);
}

void	screenexit(void) {
	free(screen);
}
