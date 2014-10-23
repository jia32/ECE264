 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

#include "answer07.h"

#define FALSE 0
#define TRUE 1
static int checkValid(ImageHeader * header,const char*filename);

//For testing
int main(int argc, char * * argv)
{
  const char * in_filename = argv[1];
  
  // Read the file
  Image * im = Image_loadbmp(in_filename);
  if(im == NULL) 
    {
      fprintf(stderr, "Error: failed to read '%s'\n", in_filename);
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}


Image * Image_loadbmp(const char * filename)
{
  FILE *fp = NULL;
  ImageHeader header;
  Image * tmp_im = NULL;
  Image * im = NULL;
  size_t read;
  size_t n_bytes = 0;
  int err = FALSE;
  if(!err)
    { // Open filename
      fp = fopen(filename, "rb");
      if(!fp) {
	fprintf(stderr, "Failed to open file '%s'\n", filename);
	err = TRUE;
      }
    }
  
  if(!err)
    { // Read the header
      read = fread(&header, sizeof(ImageHeader), 1, fp);
      if(read != 1) {
	fprintf(stderr, "Failed to read header from '%s'\n", filename);
	err = TRUE;
      }
    }    
  
  if(!err)
    { // We're only interested in a subset of valid bmp files
      if(!checkValid(&header,filename)) 
	{
	  fprintf(stderr, "Invalid header in %s\n",filename);
	  err = TRUE;
	}
    }
  
  if(!err)
    { // Allocate Image struct
      tmp_im = malloc(sizeof(Image));			
      if(tmp_im == NULL) {
	fprintf(stderr, "Failed to allocate im structure\n");
	err = TRUE;
      } 
    }
  
    if(!err) { // Initialize the Image struct
	tmp_im->width = header.width;
	tmp_im->height = header.height;

	// Handle the comment
	char * filename_cpy = strdup(filename);	// we want to call basename
	char * file_basename = basename(filename_cpy); // requires editable str
	const char * prefix = "Original BMP file: ";
	n_bytes = sizeof(char) * (strlen(prefix) + strlen(file_basename) + 1);
	tmp_im->comment = malloc(n_bytes);
	if(tmp_im->comment == NULL) 
	  {
	    fprintf(stderr, "Failed to allocate %zd bytes for comment\n",
		    n_bytes);
	    err = TRUE;
	  } else {
	  sprintf(tmp_im->comment, "%s%s", prefix, file_basename);
	}
	free(filename_cpy); // this also takes care of file_basename
	
	// Handle image data
	n_bytes = sizeof(uint8_t) * header.width * header.height;
	tmp_im->data = malloc(n_bytes);
	if(tmp_im->data == NULL) 
	  {
	    fprintf(stderr, "Failed to allocate %zd bytes for image data\n",
		    n_bytes);
	    err = TRUE;
	  }
    }

    if(!err) { // Seek the start of the pixel data
      if(fseek(fp,22, SEEK_SET) != 0) {
	fprintf(stderr, "Failed to seek %d, the data of the image data\n",
		22);
	err = TRUE;
      }
    }
    

    if(!err) { // Read pixel data
      size_t bytes_per_row = ((8 * header.width + 31)/32) * 4;
      n_bytes = bytes_per_row * header.height;
      uint8_t * rawbmp = malloc(n_bytes);
      if(rawbmp == NULL) {
	fprintf(stderr, "Could not allocate %zd bytes of image data\n",
		n_bytes);
	err = TRUE;
      } else {
	read = fread(rawbmp, sizeof(uint8_t), n_bytes, fp);
	if(n_bytes != read) {
	  fprintf(stderr, "Only read %zd of %zd bytes of image data\n", 
		  read, n_bytes);
	  err = TRUE;
	} else {
	  // Must convert RGB to grayscale
	  uint8_t * write_ptr = tmp_im->data;
	  uint8_t * read_ptr;
	  int intensity;
	  int row, col; // row and column
	  for(row = 0; row < header.height; ++row) {
	    read_ptr = &rawbmp[row * bytes_per_row];
	    for(col = 0; col < header.width; ++col) {
	      intensity  = *read_ptr++; // blue
	      intensity += *read_ptr++; // green
	      intensity += *read_ptr++; // red	
	      *write_ptr++ = intensity / 3; // now grayscale
	    }
	  }
	}
      }
      free(rawbmp);
    }
    
    if(!err) { // We should be at the end of the file now
      uint8_t byte;
      read = fread(&byte, sizeof(uint8_t), 1, fp);
      if(read != 0) {
	fprintf(stderr, "Stray bytes at the end of bmp file '%s'\n",
		filename);
	err = TRUE;
      }
    }
    
    
    if(!err) { // We're winners... 
      im = tmp_im;  // bmp will be returned
      tmp_im = NULL; // and not cleaned up
    }
    
    // Cleanup
    if(tmp_im != NULL) {
      free(tmp_im->comment); // Remember, you can always free(NULL)
      free(tmp_im->data);
      free(tmp_im);
    }
    if(fp) {
      fclose(fp);
    }
    
    return im;
    
}

static int checkValid(ImageHeader * header,const char * filename)
{
  
    // Make sure the magic number is correct
    if (header->magic_number != ECE264_IMAGE_MAGIC_NUMBER)
      {	
	fprintf(stderr, "Magic number incorrect in '%s'\n", filename);
	return FALSE;
      }
    //Make sure neither the width nor height is zero.
    if (header->width == 0) 
      {	
	fprintf(stderr, "Width is zero in '%s'\n", filename);
	return FALSE;
      }
    if (header->height == 0) 
      {	
	fprintf(stderr, "Height is zero in '%s'\n", filename);
	return FALSE;
      }

    //Make sure the length of the comment is not zero
    if (header->comment_len == 0) 
      {	
	fprintf(stderr, "Comment length is 0 in '%s'\n", filename);
	return FALSE;
      }

    // We're winners!!!
    return TRUE;

}
