#include "wish/wish.h"

#include <cstdio>
#include <cstdlib>

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <sys/wait.h>

// void fork_test() {
//   printf("hello world (pid:%d)\n", (int)getpid());
//   int rc = fork();
//   int fd = open("lorem.txt", O_RDWR, O_APPEND);
//   if (rc < 0) {
//     fprintf(stderr, "fork failed\n");
//     exit(1);
//   } else if (rc != 0) {
//     printf("hello, I am child (pid:%d)\n", (int)getpid());
// 	int wc = 1'00;
// 	int pid = (int) getpid();
// 	while (wc-- > 0) {
// 		char buffer[] = "From parent\n";
// 		write(fd, &buffer, sizeof(buffer));
// 	}
//   } else {
//     // int rc_wait = wait(NULL);
//     printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
// 	int wc = 2'00;
// 	while (wc-- > 1'00) {
// 		int pid = (int) getpid();
// 		char buffer[] = "From child\n";
// 		write(fd, &buffer, sizeof(buffer));
// 	}
//   }
// }
//
// void exec_test() {
//   printf("hello world (pid:%d)\n", (int)getpid());
//   int rc = fork();
//   if (rc < 0) {
//     fprintf(stderr, "fork failed\n");
//     exit(1);
//   } else if (rc == 0) {
//     printf("hello, I am child (pid:%d)\n", (int)getpid());
//     char *myargs[3];
//     myargs[0] = strdup("wc");
//     myargs[1] = strdup("lorem.txt");
//     myargs[2] = NULL;
//     if (execvp(myargs[0], myargs) == -1) {
//       printf("this should not print out\n");
//     }
//   } else {
//     int rc_wait = wait(NULL);
//     printf("Hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait,
//            (int)getpid());
//   }
// }

int main(int argc, char **argv) {
  Wish wish;
  while (true) {
    wish.Run();
  }
  return 0;
}
