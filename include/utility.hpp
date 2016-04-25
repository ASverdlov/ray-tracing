#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <cstdlib>

typedef uint32_t ui32;

#define STRINGIFY2(X) #X
#define STRINGIFY(X) STRINGIFY2(X)

#ifndef TEST_FRIENDS
#define TEST_FRIENDS
#endif

#ifndef TEST_FRIENDS_DEFINITIONS
#define TEST_FRIENDS_DEFINITIONS
#endif

#endif
