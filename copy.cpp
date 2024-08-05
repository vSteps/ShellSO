#include <fcntl.h>
#include <unistd.h>
#include "../../../../../msys64/ucrt64/include/sys/stat.h"


int main(int argc, char **argv){
	const char *sourcefn = argv[1];
	const char *targetfn = argv[2];

	int source = open(sourcefn, O_RDONLY);
	int target = open(targetfn, O_WRONLY | O_CREAT | S_IRUSR|S_IWUSR);

	char buf[1024];
	int s;
	while ((s = read(source, buf, 1024)) != 0)
		write(target, buf, s);
	close(target);
	close(source);

	return 0;
}