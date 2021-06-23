
#pragma once

#include <sort_common_definitions.h>
#include <stddef.h>

void nv_qsort(void *first, size_t number, size_t size, comparef_t comparator);