#include <utf8.h>
#include <stdio.h>


int main() {
  const char *text = "Hello, 世界!";
  size_t length = utf8len(text);

  printf("The UTF-8 string \"%s\" has %zu characters.\n", text, length);

  return 0;
}
