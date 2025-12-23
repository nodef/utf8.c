#include <utf8.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Custom function to reverse a UTF-8 string
void utf8_reverse(char *str) {
  size_t len = strlen(str);
  char *buffer = (char*) malloc(len + 1);
  char *src  = str + len;
  char *dest = buffer;

  while (src > str) {
    size_t char_size = utf8codepointsize(*(src - 1));
    src -= char_size;
    memcpy(dest, src, char_size);
    dest += char_size;
  }

  *dest = '\0';
  strcpy(str, buffer);
  free(buffer);
}


int main() {
  char text[] = "Hello, 世界!";
  utf8_reverse(text);

  printf("Reversed UTF-8 string: %s\n", text);

  return 0;
}
