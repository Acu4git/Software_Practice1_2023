// Q2
#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fpi, *fpo;

  if(argc != 3) {
    fprintf(stderr, "Illegal number of argument.\n");
    return -1;
  }

  if((fpi = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open input file <%s>.\n", argv[1]);
    return -1;
  }

  if((fpo = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Can't open output file <%s>.\n", argv[2]);
    return -1;
  }
}