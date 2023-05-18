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

int CalcShapeScore(int mine) {
  return mine - 87;
}

int CalcOutcomeScore(int opp, int mine) {
  opp -= 64;
  mine -= 87;

  if (opp == mine) {
    return 3;
  }

  if (mine == 1) {
    if (opp == 3) {
      return 6;
    }
    return 0;
  }

  if (mine == 2) {
    if (opp == 1) {
      return 6;
    }
    return 0;
  }

  if (mine == 3) {
    if (opp == 2) {
      return 6;
    }
    return 0;
  }

  printf("Invalid %d", mine);
  return -1;
}

int CalcScore(char opp, char mine) {
  int shape_score = CalcShapeScore(mine);
  int outcome_score = 3;

  return CalcShapeScore(mine) + CalcOutcomeScore(opp, mine);
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

