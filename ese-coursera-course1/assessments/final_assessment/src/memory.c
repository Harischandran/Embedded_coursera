#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
    
    uint8_t *d = dst;
    uint8_t *s = src;

  
    if (d < s){
        while (length--){
            *d++= *s++;
        }
    }
    
    else{
        uint8_t *lasts = s + (length-1);    
        uint8_t *lastd = d + (length-1);    
        while (length--){
            *lastd-- = *lasts--;
        }
    }
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
    uint8_t *d = dst;
    uint8_t *s = src;
    while (length){
        length--;
        *d++ = *s++;
    }
    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
    uint8_t *s = src;
    while (length){
        length--;
        *s++ = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
    return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length){
    
    uint8_t *temp;
    temp = (uint8_t*)malloc(length*sizeof(uint8_t)); 
    if(! temp){
        printf("ERROR: allocating dynamic memory for my_reverse function call\n");
    }
    uint8_t *lastTemp = temp+length; 
    for(int i=0; i<length; i++){
        *(temp+i)=*(src+i);
    }
    
    while(length--){
        *(src+length)= *(lastTemp-length-1);
    }
    free(temp);
    return src;
}

int32_t * reserve_words(size_t length){
    return malloc(length*sizeof(length));
}

void free_words(uint32_t * src){
    return free(src);
}
