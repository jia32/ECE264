#ifndef PA02_H
#define PA02_H
#include <stdlib.h>
/**
 * Length of C string 'str', excluding the terminating null byte ('\0')
 *
 * Examples:
 * my_strlen("abc"); // 3
 * my_strlen(""); // 0
 * my_strlen(NULL); // error -- undefined behavior. You do not need to
 * // consider this case. See the README -- FAQ for more info.
 */
size_t my_strlen(const char * str);
/**
 * Count the number of occurrences of character 'ch' in C string 'str'
 *
 * Examples:
 * my_countchar("foo", 'o'); // 2
 */
int my_countchar(const char * str, char ch);
/**
 * Return a pointer to the first occurrence of character 'ch' in C string 'str'
 * Return NULL if 'ch' is not found.
 *
 * Note that the terminating '\0' character is considered to be part of the
 * string. Thus, if 'ch' is specified as '\0', then return a pointer to the
 * null terminator of the string.
 *
 * Examples:
 * const char * str = "Hello World!";
 * printf("'%s'\n", my_strchr(str, 'o')); // prints "'o World!'\n"
 * printf("'%s'\n", my_strchr(str, 'z')); // prints "'(null)'\n"
 * // i.e., my_strchr(str, 'z') == NULL
 * printf("'%s'\n", my_strchr(str, '\0')); // prints "''\n"
 *
 * Please read the README FAQ before attempting this function.
 */
char * my_strchr(const char * str, int ch);
/**
 * Same as my_strchr(...), except it searches from the right-hand-side
 *
 * Examples:
 * const char * str = "Hello World!";
 * printf("'%s'\n", my_strrchr(str, 'o')); // prints "'orld!'\n"
 * printf("'%s'\n", my_strrchr(str, 'z')); // prints "'(null)'\n"
 * // i.e., my_strrchr(str, 'z') == NULL
 * printf("'%s'\n", my_strrchr(str, '\0')); // prints "''\n" *
 */
char * my_strrchr(const char * str, int ch);
/** Finds the first occurrence of C-string 'needle' in C-string 'haystack'
 * Return 'haystack' when 'needle' is the empty string (ie, "").
 * The terminating null bytes are not compared.
 *
 * Examples:
 * const char * str = "Hello World!";
 * printf("'%s'\n", my_strstr(str, "World")); // prints "'World!'\n"
 * printf("'%s'\n", my_strstr(str, "")); // prints "'Hello World!'\n"
 * printf("'%s'\n", my_strstr(str, "hello")); // prints "'(null)'\n"
 * // i.e., my_strstr(str, "hello") == NULL
 */
char * my_strstr(const char * haystack, const char * needle);
/**
 * Copies C-string 'src' (including the null-byte terminator) into the memory
 * pointed to by 'dest'.
 * The strings must not overlap, and 'dest' must be large
 * enough to contain 'src', *including* the terminating null-byte.
 * (NOTE: Just as with the real strcpy function, these are PRECONDITIONS,
 * NOT something your function should check for!)
 *
 * Returns 'dest'
 *
 * Examples:
 * const char * str = "Hello World!"; // strlen(str) == 12, but 13 bytes with \0
 * char buffer[50];
 * printf("%s\n", my_strcpy(buffer, str)); // prints "Hello World!\n"
 */
char * my_strcpy(char * dest, const char * src);
/**
 * Append C-string 'src' to C-string 'dest'. A precondition is 'dest' must be
 * large enough to contain both 'dest' and 'src', *including* the terminating
* null-byte.
*
* Returns 'dest'
*
* Examples:
* char buffer[50];t by 10
* (4.b) Add (*str - '0') to ret
  * (4.c) Increment str
  * (5) If there was a minus sign, return -ret. Otherwise return ret.
*
  * Examples:
*  my_atoi("0"); // 0
* my_atoi("-12"); // -12
* my_atoi("15th of March would be the ides."); // 15
* my_atoi("4 months to Summer."); // 4
* my_atoi("\n\f\t\v\r 6 white space characters handled correctly."); // 6
* my_atoi("garbage, instead of a number like 73 for example, should yield a zero"); // 0
*/
int my_atoi(const char * str);
#endif
