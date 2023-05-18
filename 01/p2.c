#import <stdio.h>
#import <stdlib.h>
#import <string.h>

int first = 0, second = 0, third = 0;

void updateMax(int val) {
  if (val > first) {
    third = second;
    second = first;
    first = val;
  } else if (val > second) {
    third = second;
    second = val;
  } else if (val > third) {
    third = val;
  }
}


int main() {
  FILE *fp;
  int bufferlength = 255;
  char line[bufferlength];

  fp = fopen("input.txt", "r");

  int rolling_max = 0;

  while(fgets(line, bufferlength, fp) != NULL) {
    if (line[0] == '\n') {
      updateMax(rolling_max);
      rolling_max = 0;
      continue;
    }

    rolling_max += atoi(line);
  }

  updateMax(rolling_max);

  fclose(fp);

  printf("Top three:\n%d\n%d\n%d\n\n", first, second, third);
  printf("Total:\n%d\n", first + second + third);

  return 1;
}
