#import <stdio.h>
#import <stdlib.h>
#import <string.h>


int main() {
  FILE *fp;
  int bufferlength = 255;
  char line[bufferlength];

  fp = fopen("input.txt", "r");
  int current;
  int all_max = 0;
  int rolling_max = 0;

  while(fgets(line, bufferlength, fp) != NULL) {
    if (strlen(line) <= 1) {
      rolling_max = 0;
      continue;
    }

    current = atoi(line);
    rolling_max += current;

    if (rolling_max > all_max) {
      all_max = rolling_max;
    }
  }

  fclose(fp);

  printf("All max: %d\n", all_max);

  return 1;
}
