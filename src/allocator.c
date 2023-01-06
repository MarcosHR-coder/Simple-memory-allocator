#include "allocator.h"
#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

static void linked_list_add(Heap_Data* data, Chunk_Header* el) {
  if (data->first == NULL) {
    data->first = el;
    data->last = el;
    return;
  }
  data->last->next = el;
  data->last = el;
}

static void linked_list_remove_last(Heap_Data* data, Chunk_Header* el) {
  if (el == data->first) {
    data->first = NULL;
    data->last = NULL;
    return;
  }
  Chunk_Header* ptr = data->first;
  while (ptr->next != data->last && ptr->next) {
    ptr = ptr->next;
  }
  ptr->next = NULL;
  data->last = ptr;
}

Heap_Data* create_heap(size_t heap_size) {
  char heap[heap_size];
  Heap_Data new_heap;
  new_heap.heap_size = heap_size;
  new_heap.pbrk = 0;
  new_heap.heap = heap;
  return &new_heap;
}

static Chunk_Header* search_free_block(Heap_Data* heap_data, size_t required_size) {
  if (heap_data->first == NULL) {
    return NULL;
  }
  Chunk_Header* ptr = heap_data->first;
  while (ptr->next) {
    if (ptr->is_free == TRUE && ptr->size >= required_size) {
      return ptr;
    }
    ptr = ptr->next;
  }
  return NULL;
}

void* alloc(Heap_Data* heap_data, size_t size) {
  if (heap_data == NULL) {
    printf("Must provide a defined heap given by create_heap");
    assert(0);
    return NULL;
  }
  Chunk_Header* free_chunk = search_free_block(heap_data, size);
  if (free_chunk) {
    free_chunk->is_free = FALSE;
    return (void*)(free_chunk + 1);
  }
  assert(heap_data->pbrk + size <= heap_data->heap_size);
  Chunk_Header* result = (Chunk_Header*)(heap_data->heap + heap_data->pbrk);
  result->size = size;
  result->next = NULL;
  result->is_free = FALSE;
  heap_data->pbrk += size + sizeof(Chunk_Header);
  linked_list_add(heap_data, result);
  return (void*)(result + 1);
}

void dealloc(Heap_Data* heap_data, void* adress) {

}
