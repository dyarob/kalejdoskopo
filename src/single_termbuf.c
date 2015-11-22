#include <stdlib.h>
#include <term.h>
#include <string.h>

#define TERMBUFSIZE 512

char *	termbuf_init(void);
void		termbuf_set(char * src);
char *	termbuf_get(void);
void		termbuf_free(void);


char *	termbuf_init(void) {
	char *	termbuf = (char *)malloc(TERMBUFSIZE);
	atexit(termbuf_free);
	tgetent(termbuf, getenv("TERM"));
	return termbuf;
}

void		termbuf_set(char * src) {
	memcpy(termbuf_get(), src, TERMBUFSIZE);
}

char *	termbuf_get(void) {
	static char *	termbuf = NULL;
	if (termbuf == NULL)
		termbuf = termbuf_init();
	return termbuf;
}

void		termbuf_free(void) {
	free(termbuf_get());
}
