#include "answer02.h"

size_t my_strlen(const char * str)
{
  int len = 0;
  while ((* str) != '\0') {
    len++;
    str ++;
  }
  return len;
}

int my_countchar(const char * str, char ch)
{
  int len = my_strlen(str);
  int ind;
  int count = 0;
  for (ind = 0; ind < len; ind++){
    if (str[ind] == ch) {
      count++;
    }
  }
  return count;
}

char* my_strchr(const char * str, int ch)
{
  int len = my_strlen(str);
  int ind;

  for (ind = 0; ind < len; ind++) {
    if (str[ind] == (char) ch) {
      return (char*) str[ind];
    }
  }
}
char * my_strrchr(const char * str, int ch)
  {
    int len = my_strlen(str);
    int ind;

      for (ind = len; ind > 0; ind--) {
      if (str[ind] == (char) ch) {
	return (char *)str[ind];
      }
    }

  }

  char * my_strstr(const char * haystack, const char * needle)
  {
    if (needle == NULL)
      {
	return haystack;
      }

    while (haystack != '\0')
      {
	const char *h;
	const char *n;
	for (h = haystack, n = needle; *h == *n; ++h, ++n) {
	}
	if (*n == '\0') {
	  return haystack;
	}
	*haystack++;
      }
  }


  char * my_strcpy(char * dest, const char * src)
  {
    int ind;
    for (ind = 0; ind < my_strlen(src);ind++)
      {
	dest[ind] = src[ind];
      }
    return dest;
  }
  char * my_strcat(char * dest, const char * src)
  {
    int i;
    int j;
    for (i = 0; dest[i] != '\0';i++)
      {
	for (j = 0; src[j]!='\0'; j++)
	  {
	    dest[i+j] = '\0';
	  }
      }
    dest[i+j] = '\0';
    return dest;
  }

  int my_isspace(int ch)
  {
    if (ch == '\t' || ch == ' '|| ch == '\f'|| ch == '\n'|| ch == '\r'|| ch == '\v')
      {
	return 1;
      }
    else return 0;
  }

  int my_atoi(const char * str)
  {
    int ret = 0;
    int neg = 0;
    int n = 0;
    while (str)
      {
	if (my_issapce(*str) == 1)
	  {
	    str++;
	  }
	if (*str == '-')
	  {
	    neg = 1;
	  }
	while ((*str <= '9') && (*str >= '0'))
			      {
				ret *= 10;
				n += *str - '0';
			      }
      }
    str++;
  if (neg == 1)
    {
      return -n;
    }
  else{
    return n;}
  }
