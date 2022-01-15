#pragma once

#include "utils.h"

#ifndef STACK_DEFAULT_SIZE
	#define STACK_DEFAULT_SIZE 32
#endif

template<typename T>
struct Stack
{
	Stack() : count(0), capacity(STACK_DEFAULT_SIZE), memory((T*)malloc(32 * sizeof(T))) {}
	Stack(i32 initial_capacity) : count(0), capacity(initial_capacity), memory((T*)malloc(initial_capacity * sizeof(T))) {	}
	Stack(const Stack<T>& source) // copy constructor
	{
		count = source.get_count();
		capacity = source.get_capacity();
		memory = (T*)malloc(capacity * sizeof(T));
		assert(memory);
		for (i32 i = 0; i < source.count; i++) memory[i] = source[i];
	}

	Stack(Stack<T>&& source) noexcept : // move constructor
		count(source.count), capacity(source.capacity), memory(source.memory)
	{
		source.memory = nullptr;
		source.count = 0;
		source.capacity = 0;
	}

	Stack& operator=(const Stack& source) // copy assignment
	{
		if (this != &source) // not a self-assignment
		{
			count = 0;
			for (i32 i = 0; i < count; i++) push(source[i]);
		}
		return *this;
	}

	Stack& operator=(Stack&& source) // move assignment
	{
		count = source.count;
		capacity = source.capacity;
		memory = source.memory;
		{
			source.memory = nullptr;
			source.count = 0;
			source.capacity = 0;
		}
		return *this;
	}
	
	~Stack()
	{
		if (memory) free(memory);
		memory = nullptr;
		count = 0;
		capacity = 0;
	}

	i32 push(const T& new_element)
	{
		if (count + 1 >= capacity) { increase_capacity(2 * capacity); }
		memory[count] = new_element;
		return count++;
	}

	inline T pop()
	{
		assert(count > 0);
		return memory[--count];
	}

	inline i32 get_capacity()		const { return capacity;		}
	inline i32 get_count()			const { return count;			}
	inline T get_element(i32 i)		const { return memory[i];		}
	inline T operator [](i32 i)		const { return memory[i];		}
	inline T& operator [](i32 i)		  { return memory[i];		}
	inline T operator &()				  { return *memory;			}

	T* begin() noexcept					  { return &memory[0];		}
	T* end() noexcept					  { return &memory[count];	}
	const T* begin()	   const noexcept { return &memory[0];		}
	const T* end()		   const noexcept { return &memory[count];	}
private:

	void increase_capacity(i32 new_capacity)
	{
		if (new_capacity > capacity)
		{
			T* ptr = (T*)realloc(memory, new_capacity * sizeof(T));
			if (ptr) memory = ptr;
		}
	}

	T* memory = nullptr;
	i32 count = 0;
	i32 capacity = 0;
};