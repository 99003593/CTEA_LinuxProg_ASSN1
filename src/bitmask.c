#include "bitmask.h"

size_t bit_set(size_t data, uint8_t offset)
{
    return data | (1ul << offset);
}

size_t bit_reset(size_t data, uint8_t offset)
{
    return data & ~(1ul << offset);
}

size_t bit_flip(size_t data, uint8_t offset)
{
    return data ^ (1ul << offset);
}

bool bit_query(size_t data, uint8_t offset)
{
    return data >> offset & 1;
}
