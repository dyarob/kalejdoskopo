#include "kalejdoskopo.h"
#include <stdlib.h>

struct termios *	tattr_init(void) {
	struct termios *	tattr = (struct termios *)malloc(TERMIOSSIZE);
	tcgetattr(0/*STDIN_FILENO*/, tattr);
	return tattr;
}

struct termios *	tattr_get(void) {
	static struct termios *	tattr = NULL;
	return tattr;
}

void	tattr_free(void) {
	free(tattr_get());
}
