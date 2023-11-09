#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a name using a provided function.
 * @name: The name to be printed.
 * @f: A pointer to a function that takes a char pointer as an argument.
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

