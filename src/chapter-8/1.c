#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void die(char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  fprintf(stderr, "error: ");

  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
  exit(1);
}

void filecopy(int ifd, int ofd) {
  int n;
  char buf[BUFSIZ];

  while ((n = read(ifd, buf, BUFSIZ)) > 0)
    if (write(ofd, buf, n) != n) {
      perror("cat: write error");
    }
}

int cat(int argc, char *argv[]) {
  int fd;

  if (argc == 1) {
    filecopy(STDIN_FILENO, STDOUT_FILENO);
    return 0;
  }

  while (--argc > 0) {
    if ((fd = open(*++argv, O_RDONLY)) == -1) {
      die("cat:can't open %s", *argv);
    } else {
      filecopy(fd, STDOUT_FILENO);
      close(fd);
    }
  }

  return 0;
}
