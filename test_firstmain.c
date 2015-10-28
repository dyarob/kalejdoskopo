#include <termios.h>
#include <unistd.h>	//sleep
#include <term.h>
#include <stdio.h>	//putchar
#include <stdlib.h>	//getenv
#include <string.h>	//memcpy

#define SIZETERMIOS	sizeof(struct termios)

struct termios	*tattrsave;

int	myputc(int c) {
	write(1, &c, 1);
	return 1;
}

void	myatexit(void) {
	tputs(tgetstr("ve", NULL), 1, myputc);
	tcsetattr(0, TCSANOW, tattrsave);
	fpurge(NULL);
}

int	main(void) {
	struct termios	*tattr = (struct termios *)malloc(SIZETERMIOS);
	char						termbuf[512];

	tgetent(termbuf, getenv("TERM"));

	tattrsave = (struct termios *)malloc(SIZETERMIOS);
	tcgetattr(0/*STDIN_FILENO*/, tattr);
	memcpy(tattrsave, tattr, SIZETERMIOS); 
	atexit(myatexit);

	tattr->c_lflag &= ~(ECHO|ICANON);
	tcsetattr(0, TCSANOW, tattr);

	tputs(tgetstr("cl", NULL), 1, myputc);
	tputs(tgetstr("vi", NULL), 1, myputc);

	write(1, "hello", 5);
	sleep(2);

	return 0;//EXIT_SUCCESS;
}
