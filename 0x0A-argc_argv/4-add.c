#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
* check_num - check if a string contains only digits
* @str: the input string to be checked
*
* return: 1 if all characters are digits, 0 otherwise
 */
int check_num (char *str)
{
unsigned int count = 0;
while (count < strlen(str))
    {
If (!isdigit(str[count]))
        {
return (0);
        }
count++;
}
return (1);
}

/**
* main - entry point of the program
* @argc: number of command-line arguments
* @argv: array of command-line argument strings
*
* return: 0 on success, 1 on error
*/
int main (int argc, char *argv[])
{
int count;
int str_to_int;
int sum = 0;
count = 1;
while (count < argc)
{
If (check_num(argv[count]))
{
str_to_int = atoi(argv[count]);
sum += str_to_int;
}
Else
{
Printf ("Error\n");
return (1);
 }
Count++;
 }
Printf ("%d\n", sum);

return (0);
}

