#include <utf8.h>
#include <stdio.h>
#include <string.h>


// Custom function to extract a substring from a UTF-8 string
void utf8_substr(const char *src, size_t start, size_t length, char *dest, size_t dest_size) {
  const char *s = src;
  size_t i = 0;

  // Skip to the start position
  while (i < start && *s) {
    s += utf8codepointsize(*s);
    i++;
  }

  // Extract the substring
  char *d = dest;
  size_t extracted = 0;
  while (extracted < length && *s && (d - dest) < (dest_size - 1)) {
    size_t char_size = utf8codepointsize(*s);
    if ((d - dest) + char_size >= dest_size) {
      break;
    }
    memcpy(d, s, char_size);
    d += char_size;
    s += char_size;
    extracted++;
  }

  // Null-terminate the destination string
  *d = '\0';
}


int main() {
  const char *text = "Hello, 世界!";
  char buffer[16];

  utf8_substr(text, 7, 2, buffer, sizeof(buffer));
  printf("Substring: %s\n", buffer);

  return 0;
}
