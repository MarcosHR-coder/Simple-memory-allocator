#include <stdio.h>
#include "allocator.h"
#include <string.h>

int main() {
  Heap_Data* heap_data = create_heap(4096);
  void* chunk = alloc(heap_data, 8);
  int* number = (int*) alloc(heap_data, sizeof(int));
  *number = 7;
  char* phrase = (char*) alloc(heap_data, sizeof(char) * 30);
  strncpy(phrase, "Buenos días caballero", 30);

  printf("Number: %i, Phrase: %s ;", *number, phrase);

  return 0;
}
