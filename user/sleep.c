#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if (argc != 2) {
    fprintf(2, "usage: sleep number_of_ticks\n");
    exit(1);
  }

  uint ticks = atoi(argv[1]);
  // fprintf(1, "[DEBUG]: sleep ticks: %d\n", ticks);

  sleep(ticks);

  exit(0);
}
