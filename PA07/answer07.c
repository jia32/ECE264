 
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

static int checkValid(BMP_Header * header);

Image * Image_loadbmp(const char * filename)
{
  FILE *fp = NULL;
  ImageHeader header;
  int err = FALSE;
  if(!err) { // Open filename
    fp = fopen(filename, "rb");
	if(!fp) {
	  fprintf(stderr, "Failed to open file '%s'\n", filename);
	  err = TRUE;
	}

    }

    if(!err) { // Read the header
	read = fread(&header, sizeof(BMP_Header), 1, fp);
	if(read != 1) {
	    fprintf(stderr, "Failed to read header from '%s'\n", filename);
	    err = TRUE;
	}
    }    

    if(!err) { // We're only interested in a subset of valid bmp files
	if(!checkValid(&header)) {
	    fprintf(stderr, "Invalid header in '%s'\n", filename);
	    err = TRUE;
	}
    }

static int checkValid(ImageHeader * header)
{
  
    // Make sure the magic number is correct
    if (header->type != ECE264_IMAGE_MAGIC_NUMBER) return FALSE;

    //Make sure neither the width nor height is zero.
    if (header->width == 0) return FALSE;
    if (header->height == 0) return FALSE;

    //Make sure the length of the comment is not zero
    if (header->comment_len == 0) return FALSE;

    // We're winners!!!
    return TRUE;

}
