#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define SHMEM_SZ 1024
char *shmem_name;

enum {
      DUTCH,
      GERMAN,
      FRENCH,
      SPANISH,
      STOP
};

struct t {
  int val;
};

void getflag(void) { printf("You got the flag!!\n"); }

int main(int argc, char **argv) {
  int fd;
  struct t *m;

  if(argc < 2) {
    fprintf(stderr, "%s <shmem_name>\n", argv[0] == NULL ? "./challenge" : argv[0]);
    exit(1);
  }

  shmem_name = argv[1];

  if(strlen(shmem_name) <= 1) {
    fprintf(stderr, "shmem_name is invalid.\n");
    exit(1);
  }

  if(shmem_name[0] != '/') {
    fprintf(stderr, "shmem_name must start with a '/'\n");
    exit(1);
  }

  umask(0);

  fd = shm_open(shmem_name, O_RDWR | O_CREAT | O_TRUNC | O_EXCL,
               S_IRWXU | S_IRWXG | S_IRWXO);
  if (fd < 0) {
    perror("shm_open");
    exit(1);
  }

  if(ftruncate(fd, SHMEM_SZ) != 0) {
    perror("ftruncate");
    exit(1);
  }

  m = mmap(NULL, SHMEM_SZ, PROT_READ | PROT_EXEC, MAP_SHARED, fd, 0);
  if (m == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  usleep(10000);

  close(fd);
  shm_unlink(argv[1]);

  while (1) {
    switch (m->val) {
    case DUTCH:
      printf("Hallo Wereld\n");
      break;
    case GERMAN:
      printf("Hallo Welt\n");
      break;
    case FRENCH:
      printf("Bonjour le monde\n");
      break;
    case SPANISH:
      printf("Hola Mundo\n");
      break;
    case STOP:
      goto done;
    default:
      printf("Unknown value.\n");
      break;
    }
  }

done:
  printf("exiting...\n");

  return 0;
}
