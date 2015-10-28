#include <stdlib.h>
#include <term.h>
#include "kalejdoskopo.h"

void	terminit(void) {
	struct termios	*tattr = tattr_get();
	termbuf_get();

	tattr->c_lflag &= ~(ECHO|ICANON);
	tcsetattr(0, TCSANOW, tattr);

	tputs(tgetstr("cl", NULL), 1, myputc);
	tputs(tgetstr("vi", NULL), 1, myputc);
}
