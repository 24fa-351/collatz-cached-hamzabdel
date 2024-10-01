#include <stdio.h>
#include <stdlib.h>
#include "cache.h"

typedef struct {
    int number;
    int steps;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cache_count = 0;
int cache_hits = 0;
int cache_misses = 0;

void init_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) 
    {
        cache[i].number = -1; 
    }
}

int get_from_cache(int number) {
    for (int i = 0; i < cache_count; i++) 
    {
        if (cache[i].number == number) 
        {
            cache_hits++; 
            return cache[i].steps;
        }
    }

    cache_misses++; 
    return -1; 
}

void add_to_cache(int number, int steps) 
{
    if (cache_count < CACHE_SIZE) 
    {
        cache[cache_count].number = number;
        cache[cache_count].steps = steps;
        cache_count++;
    } 
    else {
        cache[0].number = number;
        cache[0].steps = steps;
    }
}

float get_cache_hit_percentage() 
{
    if (cache_hits + cache_misses == 0) return 0; 
    return (float)cache_hits / (cache_hits + cache_misses) * 100; 
}
