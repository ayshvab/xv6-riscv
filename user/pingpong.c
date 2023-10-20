#include "kernel/types.h"
#include "user/user.h"

void
panic(char *s)
{
  fprintf(2, "%s\n", s);
  exit(1);
}

int
main(int argc, char *argv[])
{
  int p0[2];
  int p1[2];

  unsigned char *buf0[1] = {0};
  unsigned char *buf1[1] = {0};

  pipe(p0);
  pipe(p1);

  if (fork() == 0) { // child process
    if (read(p0[0], buf0, 1) != 1) {
        panic("Failed to read ping\n");
        exit(1);
    }
    fprintf(1, "%d: received ping\n", getpid());
    write(p1[1], " ", 1);
    exit(0);
  } else {
    write(p0[1], " ", 1);
    if (read(p1[0], buf1, 1) != 1) {
        panic("Failed to read pong\n");
        exit(1);
    }
    fprintf(1, "%d: received pong\n", getpid());
    exit(0);
  }
}
