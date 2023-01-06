#ifndef allocator_h
#define allocator_h

#include <stdio.h>

struct chunk_header {
  size_t size;
  unsigned int is_free;
  struct chunk_header* next;
};

struct heap_data {
  char* heap;
  size_t heap_size;
  size_t pbrk;
  struct chunk_header* first;
  struct chunk_header* last;
};

typedef struct chunk_header Chunk_Header;
typedef struct heap_data Heap_Data;

Heap_Data* create_heap(size_t heap_size);
void* alloc(Heap_Data* heap, size_t size);
void dealloc(Heap_Data* heap, void* adress);

#endif
