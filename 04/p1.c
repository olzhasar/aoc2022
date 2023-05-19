#import <stdio.h>
#import <stdlib.h>
#import <string.h>

#define BUFF_SIZE 255


int main() {
  FILE *fp;
  char line[BUFF_SIZE];

  fp = fopen("input.txt", "r");

  int count = 0;

  while (fgets(line, BUFF_SIZE, fp) != NULL) {
    int a_start, a_end, b_start, b_end;

    sscanf(line, "%i-%i,%i-%i", &a_start, &a_end, &b_start, &b_end);

    if ((a_start >= b_start & a_end <= b_end) | (b_start >= a_start & b_end <= a_end) ) {
      count++;
    }

  }

  fclose(fp);

  return 1;
}
