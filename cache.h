#ifndef CACHE_H
#define CACHE_H

#define CACHE_SIZE 20 
void init_cache();
int get_from_cache(int number);
void add_to_cache(int number, int steps);
float get_cache_hit_percentage();

#endif 
