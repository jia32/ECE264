#ifndef PA02_H
#define PA02_H 

#include <stdlib.h>
 
/** 
 * Length of C string 'str', excluding the terminating null byte ('\0')
 * 
 * Examples:
 * my_strlen("abc"); // 3
 * my_strlen("");   // 0
 * my_strlen(NULL); // error -- undefined behavior. You do not need to 
 *                  // consider this case. See the README -- FAQ for more info.
 */
size_t my_strlen(const char * str);
{
  int len = 0;
  while ((* str) != '\0') {
    len++;
    str ++;
  }
  return len;
}
/**
 * Count the number of occurrences of character 'ch' in C string 'str'
 *
 * Examples: 
 * my_countchar("foo", 'o'); // 2
 */
int my_countchar(const char * str, char ch);
{
  int len = my_strlen(str);
  int ind;
  int count = 0;
  for (ind = 0; ind < len; ++ind){
    if (str[ind] == ch) {
      count++;    
    }
  }
  return count;
}
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
 *                                        // i.e., my_strchr(str, 'z') == NULL
 * printf("'%s'\n", my_strchr(str, '\0')); // prints "''\n"
 *
 * Please read the README FAQ before attempting this function.
 */
char * my_strchr(const char * str, int ch);
{
  int len = my_strlen(str);
  int ind;
  int count;
  const char str1;
  for (ind = 0; ind<len; ++ind) {
    if (str[ind] == ch) {
      count = ind;
      ind = len;
    }
  }
  for (ind = 0; ind < len - count; ++ind) {
    str1[ind] = str[count];
  }
  return str1;     
}
/** 
 * Same as my_strchr(...), except it searches from the right-hand-side 
 *
 * Examples:
 * const char * str = "Hello World!";
 * printf("'%s'\n", my_strrchr(str, 'o')); // prints "'orld!'\n"
 * printf("'%s'\n", my_strrchr(str, 'z')); // prints "'(null)'\n"
 *                                         // i.e., my_strrchr(str, 'z') == NULL
 * printf("'%s'\n", my_strrchr(str, '\0')); // prints "''\n" *
 */
char * my_strrchr(const char * str, int ch);
{
  int len = my_strlen(str);
  int ind;
  int count;
  const char *str1;
  for (ind = len; ind > 0; ind--) {
    if (str[ind] == char) {
      count = ind;
      ind = 0;
    }
  }
  for (ind = 0, ind < len - count; ind++) {
    str1[ind] = str[count];
  }
  str1[count] = "\0";
  return str1;
}
/** Finds the first occurrence of C-string 'needle' in C-string 'haystack'
 * Return 'haystack' when 'needle' is the empty string (ie, "").
 * The terminating null bytes are not compared.
 *
 * Examples:
 * const char * str = "Hello World!";
 * printf("'%s'\n", my_strstr(str, "World")); // prints "'World!'\n"
 * printf("'%s'\n", my_strstr(str, ""));      // prints "'Hello World!'\n"
 * printf("'%s'\n", my_strstr(str, "hello")); // prints "'(null)'\n"
 *                                      // i.e., my_strstr(str, "hello") == NULL
 */
char * my_strstr(const char * haystack, const char * needle);
{
  int len = my_strlen(haystack);
  int ind;
  int count = 0;
  const char str1;
  const char str2 = needle;
  if (*str == 0){
    return haystack;
  }
  for (; *haystack != 0; haystack++){
    if (*haystack == *str2) {
      break;
    }
    str1 = haystack;
    while ( *str != '\0') {
    if (*str == 0) {
      return haystack;
    }
    if ( *str1++ != *str2++) {
      break;
    }
    str2 = needle;
  }
  return (char) 0;
}
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
{
  int ind;
  for (ind = 0; src[ind] != '\0'; ++ind) {
    dest[ind] = src[ind];
  }
  dest[ind] = '\0';
  return dest;
}
/**
 * Append C-string 'src' to C-string 'dest'. A precondition is 'dest' must be 
 * large enough to contain both 'dest' and 'src', *including* the terminating
 * null-byte.
 *
 * Returns 'dest'
 *
 * Examples:
 * char buffer[50];
 * my_strcpy(buffer, "Hello ");
 * printf("%s\n", my_strcat(buffer, "Zippy!")); // prints "Hello Zippy!"
 */
char * my_strcat(char * dest, const char * src);
{
  while (*dest != '\0') {
    *dest++;
  }
  do
  {
    *dest++ = *src++;
  }
  while (*src != '\0');
}
/**
 * Returns 1 when 'ch' is a whitespace character, and 0 otherwise.
 *
 * By default, white-space characters are: space ' ', form-feed '\f', 
 * newline '\n', carriage return '\r', horizontal tab '\t' and vertical tab '\v'
 *
 * See the README FAQ for more information.
 *
 * Examples:
 * my_isspace(' '); // 1
 * my_isspace('\f'); // 1
 * my_isspace('\n'); // 1
 * my_isspace('\r'); // 1
 * my_isspace('\t'); // 1
 * my_isspace('\v'); // 1
 * char ch;
 * for(ch = 'A'; ch <= 'Z'; ++ch)
 *    my_isspace(ch); // always 0
 */
int my_isspace(int ch);
{



  return;
}

  
/**
 * Converts (only) the initial portion of 'str' to an integer.
 *
 * Implement my_atoi(str) as follows:
 * (1) Increment str to skip all white-space characters as defined by 
 * my_isspace(...)
 * (2) If there is a '-' sign, note that 'str' is a negative number, and 
 * increment str past the minus sign.
 * (3) Initialize a return value "ret" to 0. (int ret = 0)
 * (4) While '0' <= *str <= '9':
 *     (4.a) Multiply ret by 10
 *     (4.b) Add (*str - '0') to ret
 *     (4.c) Increment str
 * (5) If there was a minus sign, return -ret. Otherwise return ret.
 *
 * Examples:
 * my_atoi("0"); // 0
 * my_atoi("-12"); // -12
 * my_atoi("15th of March would be the ides."); // 15
 * my_atoi("4 months to Summer."); // 4
 * my_atoi("\n\f\t\v\r 6 white space characters handled correctly."); // 6
 * my_atoi("garbage, instead of a number like 73 for example, should yield a zero"); // 0
 */
int my_atoi(const char * str);

#endif
