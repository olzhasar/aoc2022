#import <stdio.h>
#import <stdlib.h>
#import <string.h>

#define BUFFER_LENGTH 255

int GetPriority(char val) {
  if (val > 96) {
    return val - 97;
  }
  return val - 65 + 26;
}

int GetDuplicatePriority(char line[]) {
  int H[52];
  int l = strlen(line) - 1;

  for (int i=0; i < 52; i++) {
    H[i] = 0;
  }

  for (int i = 0; i < l / 2; i++) {
    int p = GetPriority(line[i]);
    H[p] = 1;
  }

  for (int i = l / 2; i < l; i++) {
    int p = GetPriority(line[i]);
    if (H[p] == 1) {
      return p + 1;
    }
  }

  printf("FATAL, no duplicate %s", line);
  return -1;
}

int main() {
  FILE *fp;
  char line[BUFFER_LENGTH];

  fp = fopen("input.txt", "r");

  int total_priority = 0;

  while(fgets(line, BUFFER_LENGTH, fp) != NULL) {
    total_priority += GetDuplicatePriority(line);
  }

  printf("Total priority: %d\n", total_priority);

  fclose(fp);

  return 1;
}
