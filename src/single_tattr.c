#include <termios.h>
#include <stdlib.h>
#include <string.h>

#define TERMIOSSIZE	sizeof(struct termios)

struct termios *	tattr_init(void);
void	tattr_set(struct termios * src);
struct termios *	tattr_get(void);
void	tattr_free(void);


struct termios *	tattr_init(void) {
	struct termios *	tattr = (struct termios *)malloc(TERMIOSSIZE);
	atexit(tattr_free);
	tcgetattr(0/*STDIN_FILENO*/, tattr);
	return tattr;
}

void	tattr_set(struct termios * src) {
	memcpy(tattr_get(), src, TERMIOSSIZE);
}

struct termios *	tattr_get(void) {
	static struct termios *	tattr = NULL;
	if (tattr == NULL)
		tattr = tattr_init();
	return tattr;
}

void	tattr_free(void) {
	free(tattr_get());
}
