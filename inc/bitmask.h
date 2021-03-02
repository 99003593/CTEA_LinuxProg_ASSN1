#ifndef __BITMASK_H_
#define __BITMASK_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

size_t set(size_t data, uint8_t offset);
size_t reset(size_t data, uint8_t offset);
size_t flip(size_t data, uint8_t offset);
bool query(size_t data, uint8_t offset);

#endif // __BITMASK_H_
