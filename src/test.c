#include <stdio.h>
#include "allocator.h"
#include <string.h>

#define HEAP_SIZE 4096

char heap[HEAP_SIZE];

Heap_Data heap_data = {&heap, HEAP_SIZE, 0, NULL, NULL};

/*
Heap_Data* create_heap(size_t heap_size) {
  char heap[heap_size];
  Heap_Data new_heap;
  new_heap.heap_size = heap_size;
  new_heap.pbrk = 0;
  new_heap.heap = heap;
  new_heap.first = NULL;
  new_heap.last = NULL;
  return &new_heap;
}
*/

int main() {
  void* chunk = alloc(&heap_data, 8);
  int* number = (int*) alloc(&heap_data, sizeof(int));
  *number = 7;
  char* phrase = (char*) alloc(&heap_data, sizeof(char) * 30);
  strncpy(phrase, "Buenos días caballero", 30);

  printf("Number: %i, Phrase: %s ;", *number, phrase);

  return 0;
}
