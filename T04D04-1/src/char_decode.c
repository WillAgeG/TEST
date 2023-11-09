#include <stdio.h>

void coding(void);
void decoding(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("n/a\n");
    return 0;
  }

  if (argv[1][0] == '0') {
    coding();
  }

  if (argv[1][0] == '1') {
    decoding();
  }

  return 0;
}

void coding(void) {
  int ch;
  while ((ch = getchar()) != '\n') {
    if (ch != ' ') {
      printf("%x", ch);
    } else {
      printf("n/a");
    }
  }
  return;
}

void decoding(void) {
  int ch;
  while (scanf("%x", &ch) == 1) {
    printf("%c", ch);
    if (getchar() == '\n')
      break;
    printf("n/a");
  }
  return;
}
