 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

#include "answer07.h"

typedef struct ImageHeader_st {
    uint32_t magic_number; // Should be ECE264_IMAGE_MAGIC_NUMBER
    uint32_t width;        // [width x height], cannot be zero
    uint32_t height;
    uint32_t comment_len;  // A comment embedded in the file
} ImageHeader;

typedef struct Image_st {
    int width;
    int height;
    char * comment;
    uint8_t * data;
} Image;

Image * Image_loadbmp(const char * filename)
{
  int err = FALSE;
  if(!err)
    {
      

}
