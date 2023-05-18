#import <stdio.h>
#import <stdlib.h>
#import <string.h>

// ROCK BEATS SCISSORS
// PAPER BEATS ROCK
// SCISSORS BEAT PAPER
//
// ROCK - A, X
// PAPER - B, Y
// SCISSORS - C, Z
//
// POINTS:
// ROCK - 1, PAPER - 2, SCISSORS - 3
// WIN - 6, LOSS - 0, DRAW - 3
//

int CalcShapeScore(char opp, char mine) {
  if (mine == 'Y') {
    return opp - 64;
  }

  if (mine == 'X') { // LOSE
    if (opp == 'A') {
      return 3;
    }
    if (opp == 'B') {
      return 1;
    }
    if (opp == 'C') {
      return 2;
    }
  }

  if (mine == 'Z') {
    if (opp == 'A') {
      return 2;
    }
    if (opp == 'B') {
      return 3;
    }
    if (opp == 'C') {
      return 1;
    }
  }

  printf("Invalid %d", mine);
  return -1;
}

int CalcOutcomeScore(char mine) {
  if (mine == 'X') {
    return 0;
  }
  if (mine == 'Y') {
    return 3;
  }
  if (mine == 'Z') {
    return 6;
  };

  printf("Invalid %d", mine);
  return -1;
}

int CalcScore(char opp, char mine) {
  return CalcShapeScore(opp, mine) + CalcOutcomeScore(mine);
}

int main() {
  FILE *fp;
  int bufferlength = 4;
  int total = 0;

  char line[bufferlength];

  fp = fopen("input.txt", "r");

  while(fgets(line, bufferlength, fp) != NULL) {
    if (line[0] != '\n') {
      total += CalcScore(line[0], line[2]);
    }
  }

  fclose(fp);

  printf("Your score: %d\n", total);

  return 1;
}

