#include <stdio.h>
#include <string.h>

#include "answer02.h"

#define BUFFER_LEN 1024

int main(int argc, char * * argv)
{
  printf("This is  PA02.\n");

	   
    const char * s1 = "Hello World!";
    const char * s2 = "";
    const char * s3 = "foo";

    // -- my_strlen, should be: 12, 0, and 3
    printf("my_strlen(\"%s\") = %d\n", s1, (int) my_strlen(s1));
    printf("my_strlen(\"%s\") = %d\n", s2, (int) my_strlen(s2));
    printf("my_strlen(\"%s\") = %d\n", s3, (int) my_strlen(s3));

    // -- my_countchar, should be: 3, 0, and 2
    printf("my_countchar(\"%s\", 'l') = %d\n", s1, (int) my_countchar(s1, 'l'));
    printf("my_countchar(\"%s\", 'o') = %d\n", s2, (int) my_countchar(s2, 'o'));
    printf("my_countchar(\"%s\", 'o') = %d\n", s3, (int) my_countchar(s3, 'o'));

    // -- my_strchr, should be: "llo World!", "(null)", and ""
    printf("my_strchr(\"%s\", 'l') = %s\n", s1, my_strchr(s1, 'l'));
    printf("my_strchr(\"%s\", 'o') = %s\n", s2, my_strchr(s2, 'o'));
    printf("my_strchr(\"%s\", '\\0') = %s\n", s3, my_strchr(s3, '\0'));

    // -- my_strstr, should be: "World!", "Hello World!", "(null)"
    printf("my_strstr(\"%s\", \"World\") = %s\n", s1, my_strstr(s1, "World"));
    printf("my_strstr(\"%s\", \"\") = %s\n", s1, my_strstr(s1, ""));
    printf("my_strstr(\"%s\", \"hello\") = %s\n", s1, my_strstr(s1, "hello"));

    // -- my_strcpy. For this function you need a buffer where you
    // copy the string to. 
    char buffer[BUFFER_LEN];
    my_strcpy(buffer, s1);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s1, buffer);
    my_strcpy(buffer, s2);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s2, buffer);
    my_strcpy(buffer, s3);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s3, buffer);

    // -- my_strcat. You will have to do this yourself... just
    // look at my_strcpy for an example, and go from there.
    
    printf("strcpy: %s\n", buffer, my_strcpy(buffer,"Hello "));
    printf("strcat: %s\n", buffer, my_strcat(buffer,"Zipper!");
);
    // -- my_isspace. You will have to do this for yourself.
    printf(my_issapce(' '));
  
    // -- my_atoi. You will have to do this for yourself.
    printf(my_atoi("0"));
    return EXIT_SUCCESS;
}


