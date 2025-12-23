#include <utf8.h>
#include <stdio.h>


int main() {
  const char *valid_utf8 = "Hello, 世界!";
  const char *invalid_utf8 = "Hello, \xFF\xFE!";

  if (utf8valid(valid_utf8)) {
    printf("Valid UTF-8: %s\n", valid_utf8);
  } else {
    printf("Invalid UTF-8: %s\n", valid_utf8);
  }

  if (utf8valid(invalid_utf8)) {
    printf("Valid UTF-8: %s\n", invalid_utf8);
  } else {
    printf("Invalid UTF-8: %s\n", invalid_utf8);
  }

  return 0;
}
