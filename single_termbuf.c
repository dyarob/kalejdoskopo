#include <stdlib.h>
#include <term.h>

char *	termbuf_init(void) {
	char *	termbuf = (char *)malloc(512);
	atexit(termbuf_free);
	tgetent(termbuf, getenv("TERM"));
	return termbuf;
}

void		termbuf_set(char * src) {
	char *	termbuf = termbuf_get();
	if (!termbuf)
		tembuf_init();
	else
		memcpy(
}

char *	termbuf_get(void) {
	static char *	termbuf = NULL;
	return termbuf;
}

void		termbuf_free(void) {
	free(termbuf_get());
}
