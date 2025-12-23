#include <utf8.h>
#include <stdio.h>


int main() {
  char text[] = "Hello, 世界!";
  utf8upr(text);

  printf("Uppercase UTF-8 string: %s\n", text);

  return 0;
}
