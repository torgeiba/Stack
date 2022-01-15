#include "Stack.h"
#include "stdio.h"


// Testing
Stack<i32> make_stack()
{
	Stack<i32> result;
	result.push(5);
	result.push(6);
	result.push(7);
	result.push(8);
	return result;
}

i32 main(i32 argc, char* argv[])
{
	Stack<i32> s;

	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);

	Stack<i32> s1 = s;

	s[1] = 4;

	printf("s:\n");
	for (i32 i = 0; i < s.get_count(); i++)
	{

		printf("%d\n", s[i]);
	}
	printf("\n");


	printf("s:\n");
	for (i32 i : s)
	{

		printf("%d\n", i);
	}
	printf("\n");

	printf("s1:\n");
	for (i32 i = 0; i < s1.get_count(); i++)
	{

		printf("%d\n", s1[i]);
	}
	printf("\n");


	Stack<i32> s2 = make_stack();
	printf("s2:\n");
	for (i32 i : s2)
	{ 
		printf("%d\n", i);
	}
	printf("\n");
}
