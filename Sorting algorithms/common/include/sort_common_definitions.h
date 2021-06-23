#pragma once

#include <stddef.h>

typedef int (*comparef_t)(const void *, const void *);
typedef void (*sortf_t)(void *, size_t, size_t, comparef_t);
