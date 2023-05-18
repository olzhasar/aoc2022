#import <stdio.h>
#import <stdlib.h>
#import <string.h>

int all_max = 0;

void updateMax(int val) {
  if (val > all_max) {
    all_max = val;
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

  printf("All max: %d\n", all_max);

  return 1;
}
