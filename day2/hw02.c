// Q2

#include <stdio.h>

int main() {
  int mov_bitrate, record_time;
  scanf("%d%d", &mov_bitrate, &record_time);

  double file_size =
      (double)(mov_bitrate * record_time * 60) / 8 / (1024 * 1024);
  printf("FILE SIZE... %0.2lf [MB]", file_size);

  return 0;
}