#include "msgs.h"
#include <stdio.h>
#include <stdlib.h>

int signal_safe_strlen(char *input) {
  size_t len = 0;
  while (input[len] != '\0') {
    len++;
  }
  return len;
}
