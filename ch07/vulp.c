#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char *fn = "/tmp/XYZ";
	char buffer[60];
	FILE *fp;

	scanf("%50s", buffer);

	if (access(fn, W_OK) == 0) {
		fp = fopen(fn, "a+");
		fwrite("\n", sizeof(char), 1, fp);
		fwrite(buffer, sizeof(char), strlen(buffer), fp);
		fclose(fp);
	} else printf("No Permission\n");

	return 0;
}

