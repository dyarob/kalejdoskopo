#include <unistd.h>

int	myputc(int c) {
	write(1, &c, 1);
	return 1;
}
