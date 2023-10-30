#include <stdio.h>

int main(void) {
  int trade, shortage, reward;
  char grade;

  printf("Input your month's takings: ");
  fflush(stdout);
  scanf("%d", &trade);

  if (trade < 0) {
    printf("Your input is not correct!\n");
    return (-1);
  }

  if (trade >= 20000000) {
    grade = 'P';
    reward = trade * 0.1;
  } else if (trade >= 10000000) {
    grade = 'G';
    reward = trade * 0.05;
    shortage = 20000000;
  } else if (trade >= 5000000) {
    grade = 'S';
    reward = trade * 0.02;
    shortage = 10000000;
  } else if (trade >= 2000000) {
    grade = 'C';
    reward = trade * 0.01;
    shortage = 5000000;
  } else {
    grade = 'N';
    shortage = 2000000;
  }

  printf(
      "\nYour grade is  \"%c\"!!(P:Platinum,G:Gold,S:Silver,C:Copper,N:No "
      "reward)\n",
      grade);

  switch (grade) {
    case 'P':
      printf(
          "Congratulations!!\nYou get the best grade and Your reward is %d "
          "yen.\n",
          reward);
      break;
    case 'N':
      printf("You can get the grade with %d yen more.\n", shortage);
      break;
    default:
      printf(
          "Your reward is %d yen.\nYou need more %d yen to go up the next "
          "grade.\n",
          reward, shortage);
      break;
  }

  return (0);
}