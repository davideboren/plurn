#include <rng.h>

#include <random>

namespace rng{
    int rand(int min, int max){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(min, max);

        return distr(gen);
    }
}
