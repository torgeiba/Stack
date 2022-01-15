# Stack data structure

A dynamic array in about 100 lines of c++ with minimal use of templating etc, and only depends on C stdlib.h for malloc, free and realloc.
Does not construct or destruct elements

# ToDos:
- Tests (!)
- Support for initializer lists

# Maybe ToDo:
- round capacity up to next whole multiple of cache line size, typically 64 bytes.