#ifndef KALEJDOSKOPO
# define KALEJDOSKOPO

#include <termios.h>

#define TERMIOSSIZE	sizeof(struct termios)

int		myputc(int c);
void	terminit(void);
struct termios *	tattr_get(void);
char *	termbuf_get(void);

#endif
