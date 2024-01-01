// Q2
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if(argc < 2) {
    fprintf(stderr, "Error! Input more than two arguments.\n");
    fprintf(stderr, "Usage: <./sourcefile abc def hij>\n");
    exit(1);
  }

  for(int i = 1; i < argc; i++){
    if(argv[i][0] == '-') printf("%s\n", &argv[i][1]);
  }

  return 0;
}