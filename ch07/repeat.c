#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	struct stat stat1, stat2, stat3;
	int fd1, fd2, fd3;

	if (access("/tmp/XYZ", O_RDWR)) {
		fprintf(stderr, "Permission denied\n");
		return -1;
	} else 
		fd1 = open("/tmp/XYZ", O_RDWR);

	if (access("/tmp/XYZ", O_RDWR)) {
		fprintf(stderr, "Permission denied\n");
		return -1;
	} else 
		fd2 = open("/tmp/XYZ", O_RDWR);

	if (access("/tmp/XYZ", O_RDWR)) {
		fprintf(stderr, "Permission denied\n");
		return -1;
	} else 
		fd3 = open("/tmp/XYZ", O_RDWR);

	fstat(fd1, &stat1);
	fstat(fd2, &stat2);
	fstat(fd3, &stat3);

	if (stat1.st_ino == stat2.st_ino && stat2.st_ino == stat3.st_ino) {
		//write_to_file(fd1);
		write(fd1, "1234567890", 10);
	} else {
		fprintf(stderr, "Race condition detected\n");
		return -1;
	}

	return 0;
}


