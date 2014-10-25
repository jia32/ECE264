 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

#include "answer07.h"

#define FALSE 0
#define TRUE 1
static int checkValid(ImageHeader * header,const char*filename);

//I copied loadmp.c and changed a bit code to finish Image_load and Image_save
//I changed the attrubites, and the bytes per pixel(24 for pixel and 8 for ee264)
//And for image load, I changed some error print out to check if it is functioning.
Image * Image_load(const char * filename)
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
    { // We're only interested in a subset of valid files
      if(!checkValid(&header,filename)) 
	{
	  fprintf(stderr, "Invalid header in '%s\n'",filename);
	  err = TRUE;
	}
    }
  
  if(!err)
    { // Allocate Image struct
      tmp_im = malloc(sizeof(Image));			
      if(tmp_im == NULL) {
	fprintf(stderr, "Failed to allocate im structure\n");
	err = TRUE;
	free(tmp_im);
      } 
    }
  
    if(!err)
      { // Initialize the Image struct
	tmp_im->width = header.width;
	tmp_im->height = header.height;

	//Reading comment
	n_bytes = header.comment_len;
	tmp_im->comment = malloc(sizeof(char*)*n_bytes);
	read = fread(tmp_im->comment,sizeof(char),n_bytes,fp);
	printf("Comment is :%s\n ",tmp_im->comment);

	// Handle image data
	n_bytes = header.width * header.height;
	tmp_im->data = malloc(n_bytes);
	if(tmp_im->data == NULL) 
	  {
	    fprintf(stderr, "Failed to allocate %zd bytes for image data\n",
		    n_bytes);
	    err = TRUE;
	  }
    }
    /*
    if(!err) 
      { // Seek the start of the pixel data
	if(fseek(fp,22, SEEK_SET) != 0) {
	  fprintf(stderr, "Failed to seek %d, the data of the image data\n",
		  22);
	  err = TRUE;
	}
      }
    */

    if(!err) 
      { // Read pixel data
	n_bytes = header.width* header.height;
	tmp_im->data = malloc(sizeof(uint8_t)*n_bytes);
	read = fread(tmp_im->data,sizeof(uint8_t),n_bytes,fp);

	/*
	uint8_t * raw = malloc(n_bytes);
	if(raw == NULL) 
	  {
	    fprintf(stderr, "Could not allocate %zd bytes of image data\n",
		    n_bytes);
	    err = TRUE;
	  }
	else 
	  {
	    read = fread(raw, sizeof(uint8_t), n_bytes, fp);
	    if(n_bytes != read)
	      {
		fprintf(stderr, "Only read %zd of %zd bytes of image data\n", 
			read, n_bytes);
		err = TRUE;
	      } 
	  else 
	    {
	      int i;
	      for(i = 0; i < n_bytes;i++)
		{
		  tmp_im->data[i] = raw[i];
	      }
	    }
	  }
	  free(raw);*/
      }
	
    if(!err) 
      { // We should be at the end of the file now
	uint8_t byte;
	read = fread(&byte, sizeof(uint8_t), 1, fp);
	if(read != 0) 
	  {
	    fprintf(stderr, "Stray bytes at the end of file '%s'.\n",
		    filename);
	    err = TRUE;
	  }
      }
    
    
    if(!err) 
      { // We're winners... 
	im = tmp_im;  // bmp will be returned
	tmp_im = NULL; // and not cleaned up
      }
    
    // Cleanup
    if(tmp_im != NULL) 
      {
	Image_free(tmp_im);
      }
    
    if(fp) 
      {
	fclose(fp);
      }
    
    return im;
    
}

void Image_free(Image*image)
{
  free(image->comment);
  free(image->data);
  free(image);
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
 
int Image_save(const char * filename, Image * image)
{
    int err = FALSE; 
    FILE * fp = NULL;
    //uint8_t * buffer = NULL;    
    size_t written = 0;
    int size = image->width * image->height;

    // Attempt to open file for writing
    fp = fopen(filename, "wb");
    if(fp == NULL) {
	fprintf(stderr, "Failed to open '%s' for writing\n", filename);
	return FALSE; // No file ==> out of here.
    }

    // Prepare the header
    ImageHeader header;
    header.width = image->width;
    header.height = image->height;

    if(!err) {  // Write the header
	written = fwrite(&header, sizeof(ImageHeader), 1, fp);
	if(written != 1) {
	    fprintf(stderr, 
		    "Error: only wrote %zd of %zd of file header to '%s'\n",
		    written, sizeof(ImageHeader), filename);
	    err = TRUE;	
	}
    }
    if(!err) { // Write pixels	
	int i;
	for (i = 0; i < size && !err; i++)
	  {
	    written = fwrite (&image->data[i],sizeof(uint8_t),1,fp);
	  }
    }
    
    
    // Cleanup
    //free(buffer);
    if(fp)
      {
	fclose(fp);
      }    
    return !err;
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
  uint8_t max = intensity[0];
  uint8_t min = intensity[0];
  int i;
  int j;
  int size = width * height;
 
  for(i = 0; i < size; i++)
    {
	  if (intensity[i] > max)
	    {
	      max = intensity[i];
	    }
	  if (intensity[i] < min)
	    {
	      min = intensity[i];
	    }
    }
  
  for (j=0; j<size; j++)
    {
      intensity[j] = (intensity[j]-min) * 255.0/(max-min);
    } 
}

  

