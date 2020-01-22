#include <stdlib.h>

struct key_value {
    char* key;
    char* value;
};

struct hash_table {
    key_value** table;
    size_t size;
};