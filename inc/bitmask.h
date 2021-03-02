#ifndef __BITMASK_H_
#define __BITMASK_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

size_t bit_set(size_t data, uint8_t offset);
size_t bit_reset(size_t data, uint8_t offset);
size_t bit_flip(size_t data, uint8_t offset);
bool bit_query(size_t data, uint8_t offset);

#endif // __BITMASK_H_
