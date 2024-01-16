#include <stdio.h>

#define WIDTH   80
#define LEFT    0
#define CENTER  1
#define RIGHT   2

void fillchar(FILE *fp, char c, int m);
void flushline(FILE *fp, char *bp, int l, int m);

int main(int argc, char *argv[])
{
        FILE *fpi, *fpo;
        int meta = 0;
        int mode = LEFT;
        int ch;

        if(argc != 3) {
                fprintf(stderr, "Illegal number of argument.\n");
                return(-1);
        }

        if((fpi=fopen(argv[1], "r" ))==NULL) {
                fprintf(stderr, "Can't open input file <%s>.\n", argv[1]);
                return(-1);
        }
        
        if((fpo=fopen(argv[2], "w"))==NULL) {
                fprintf(stderr, "Can't open output file <%s>.\n", argv[2]);
                return(-1);
        }
        

        while((ch=fgetc(fpi))!=EOF) {
                if(meta==1) {
                        switch(ch) {
                                case 'c': mode=CENTER; break;
                                case 'r': mode=RIGHT;  break;
                                case 'l': mode=LEFT; break;
                                default:  fillchar(fpo,'/', mode);
                                                  fillchar(fpo,ch, mode);
                                                  break;
                        }
                        meta=0;
                } else if( ch == '/' ) {
                        meta=1;
                } else {
                        fillchar(fpo,ch, mode);
                }
        }
        fillchar(fpo, '\n', mode);
        fclose(fpi);
        fclose(fpo);
        return (0);
}

void fillchar(FILE *fp, char c, int m) 
{
        static int length=0;
        static char buf[WIDTH+1];

        if((length==WIDTH) && ( c!='\n')) {
                flushline(fp, buf, length, m);
                length=0;
        }
        if(c == '\n') {
                flushline(fp, buf, length, m);
                length=0;
        } else {
                buf[length++]=c;
        }
}

void flushline(FILE *fp, char *bp, int l, int m)
{
        *(bp+l)  ='\0';
        fprintf(fp, "%*s%s\n", m*(WIDTH-l)/2, "", bp);
}
