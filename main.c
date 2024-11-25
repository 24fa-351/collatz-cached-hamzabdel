#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cache.h"
#include "collatz.h"

int main(int argc, char* argv[])
{

    int N = atoi(argv[1]);
    int MIN = atoi(argv[2]);
    int MAX = atoi(argv[3]);

    init_cache();
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        int number = MIN + rand() % (MAX - MIN + 1);

        int cached_steps = get_from_cache(number);
        int steps;

        if (cached_steps != -1) {
            steps = cached_steps;
            printf("Number: %d, Steps: %d (Cache Hit)\n", number, steps);
        } else {
            steps = collatz(number);
            add_to_cache(number, steps);
            printf("Number: %d, Steps: %d\n", number, steps);
        }
    }

    float hit_percentage = get_cache_hit_percentage();
    printf("Cache Hit Percentage: %.2f%%\n", hit_percentage);

    return 0;
}
