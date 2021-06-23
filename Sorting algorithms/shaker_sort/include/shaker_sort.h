#pragma once

#include <sort_common_definitions.h>
#include <stddef.h>

void shr_sort(void *first, size_t number, size_t size, comparef_t comparator);