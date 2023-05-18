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

int GetDuplicatePriority(char line1[], char line2[], char line3[]) {
  int H[52];

  for (int i=0; i < 52; i++) {
    H[i] = 0;
  }

  for (int i = 0; line1[i] != '\0'; i++) {
    int p = GetPriority(line1[i]);
    H[p] = 1;
  }

  for (int i = 0; line2[i] != '\0'; i++) {
    int p = GetPriority(line2[i]);

    if (H[p] == 1) {
      H[p] = 2;
    }
  }

  for (int i = 0; line3[i] != '\0'; i++) {
    int p = GetPriority(line3[i]);
    if (H[p] == 2) {
      return p + 1;
    }
  }

  printf("FATAL, no common item %s %s %s", line1, line2, line3);
  return -1;
}

int main() {
  FILE *fp;
  char line1[BUFFER_LENGTH];
  char line2[BUFFER_LENGTH];
  char line3[BUFFER_LENGTH];

  fp = fopen("input.txt", "r");

  int total_priority = 0;

  while (fscanf(fp, "%[^\n]%*c%[^\n]%*c%[^\n]%*c", line1, line2, line3) == 3) {
    total_priority += GetDuplicatePriority(line1, line2, line3);
  }

  printf("Total priority: %d\n", total_priority);

  fclose(fp);

  return 1;
}
