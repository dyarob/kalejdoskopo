#include "libkalejdoskopo.h"
#include <unistd.h>

int	main(void) {
	terminit();
	
	write(1, "hello", 5);
	sleep(2);

	return 0;
}
