#include <stdio.h>
#include "allocator.h"
#include <string.h>

#define HEAP_SIZE 4096

char heap[HEAP_SIZE];

Heap_Data heap_data = {&heap, HEAP_SIZE, 0, NULL, NULL};

void print_memory_state(Heap_Data* heap_data) {
  printf("\n\tMemory state:\n");
  if (heap_data->first == NULL) {
    printf("| The memory is empty\n");
    printf("---------------------\n\n");
    return;
  }
  Chunk_Header* ptr = heap_data->first;
  int counter = 0;
  while (ptr) {
    counter++;
    fflush(stdout);
    fflush(stdin);
    printf("| Chunk %i:\n", counter);
    printf("|----------is_free: %i\n", ptr->is_free);
    printf("|-------------size: %zu\n\n", ptr->size);
    ptr = ptr->next;
  }
  printf("-------------------\n");
}

int main() {
  print_memory_state(&heap_data);
  void* chunk = alloc(&heap_data, 8);

  print_memory_state(&heap_data);
  int* number = (int*) alloc(&heap_data, sizeof(int));
  *number = 7;

  print_memory_state(&heap_data);
  char* phrase = (char*) alloc(&heap_data, sizeof(char) * 30);
  strncpy(phrase, "Buenos días caballero", 30);

  printf("\nNumber: %i, Phrase: %s\n", *number, phrase);

  print_memory_state(&heap_data);
  dealloc(&heap_data, chunk);

  print_memory_state(&heap_data);
  dealloc(&heap_data, phrase);

  print_memory_state(&heap_data);
  dealloc(&heap_data, number);
  print_memory_state(&heap_data);

  return 0;
}
