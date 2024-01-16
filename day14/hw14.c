// Q2
#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fpi, *fpo;
  int meta = 0;
  int ch;

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

  while((ch = fgetc(fpi)) != EOF) {
    if(meta == 1) {
      switch(ch) {
        case '\\':
        case '#':
        case '$':
        case '%':
        case '&':
        case '_':
        case '{':
        case '}':
          fputc(ch, fpo);
          break;
      }
      meta = 0;
    } else if(meta == 2) {
      switch(ch) {
        case '\'':
          fputc('"', fpo);
          break;
        default:
          fputc('\'', fpo);
          fputc(ch, fpo);
          break;
      }
      meta = 0;
    } else if(ch == '\\') {
      meta = 1;
    } else if(ch == '\'') {
      meta = 2;
    } else {
      switch(ch) {
        case '\\':
        case '#':
        case '$':
        case '%':
        case '&':
        case '_':
        case '{':
        case '}':
        case '"':
          break;
        default:
          fputc(ch, fpo);
          break;
      }
    }
  }

  return 0;
}