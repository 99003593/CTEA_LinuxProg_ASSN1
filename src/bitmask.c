#include "bitmask.h"

size_t set(size_t data, uint8_t offset)
{
    return data | (1ul << offset);
}

size_t reset(size_t data, uint8_t offset)
{
    return data & ~(1ul << offset);
}

size_t flip(size_t data, uint8_t offset)
{
    return data ^ (1ul << offset);
}

bool query(size_t data, uint8_t offset)
{
    return data >> offset & 1;
}
