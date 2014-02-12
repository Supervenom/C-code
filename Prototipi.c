 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Operazioni con i files */ 

int fclose(FILE *stream);  
/* Closes the stream. All buffers are flushed. If
successful, it returns zero. On error it returns EOF. */ 

int feof(FILE *stream);  
/* Tests the end-of-file indicator for the given
stream.  If the stream is at the end-of-file, then it returns a nonzero value.
If it is not at the end of the file, then it returns zero. */ 

FILE *fopen(const char *filename, const char *mode);  
/* Opens the filename
pointed to by filename.  The mode argument may be one of the following
constant strings: r    read text mode w    write text mode (truncates file to
zero length or creates new file) */ 

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);  
/* Reads
data from the given  stream into the array pointed to by ptr. It reads nmemb
number of elements of size size.  The total number of bytes read is
(size*nmemb). On success the number of elements read is returned.  On error or
end-of-file the total number of elements successfully read (which may be zero)
is returned. */

int fseek(FILE *stream, long int offset, int whence);  
/* On a text stream,
whence should  be SEEK_SET and offset should be either zero or a value
returned from ftell. The end-of-file indicator is reset. The error indicator
is NOT reset. On success zero is returned. On error a nonzero value is
returned.
Sets the file position of the stream to the given offset. The argument
offset signifies  the number of bytes to seek from the given whence position.
The argument whence can be:  
SEEK_SET     Seeks from the beginning of the file. 
SEEK_CUR     Seeks from the current position.  
SEEK_END     Seeks from the end of the file.  
On a text stream, whence should be SEEK_SET and offset
should be either zero or a value returned from ftell. The end-of-file
indicator is reset. The error indicator is NOT reset. On success zero is
returned. On error a nonzero value is returned. */

long int ftell(FILE *stream);   /* Returns the current file position of the
given stream.  If it is a text stream, then the value is a value useable by
the fseek function to return the file position to the current position. On
success the current file position is returned. On error a value of -1L is
returned and errno is set. */

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream); /*
Writes data from the array pointed to by ptr to the given stream. It writes
nmemb number of elements of size size. The total number of bytes written is
(size*nmemb). On success the number of elements writen is returned. On error
the total number of elements successfully writen (which may be zero) is
returned. */

int fprintf(FILE *stream, const char *format, ...);

int fscanf(FILE *stream, const char *format, ...);


/* Utilità varie */

int atoi(const char *str); 
/* The string pointed to by the argument str is converted to an 
integer (type int). */

void *malloc(size_t size); 
/* Allocates the requested memory and returns a pointer to it. 
The requested size is size bytes. The value of the space is indeterminate. 
On success a pointer to the requested space is returned. 
On failure a null pointer is returned. */

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *,
const void*)); 
/* Sorts an array. The beginning of the array is pointed to by
base. The array is nitems long with each element in the array size bytes long.
The elements are sorted in ascending order according to the compar function.
This function takes two arguments. These arguments are two elements being
compared. This function must return less than zero if the first argument is
less than the second. It must return zero if the first argument is equal to
the second. It must return greater than zero if the first argument is greater
than the second.

If multiple elements are equal, the order they are sorted in the array is
unspecified.

No value is returned.

Example:

#include<stdlib.h> 
#include<stdio.h> 
#include<string.h>

int main(void) {   
	char string_array[10][50]={"John",
	"Jane",                              "Mary",
	"Rogery",                            "Dave",
	"Paul",                              "Beavis",
	"Astro",                             "George",
	"Elroy"};

  	//Sort the list    
  	qsort(string_array,10,50,strcmp);

  	//Search for the item "Elroy" and print it
	printf("%s",bsearch("Elroy",string_array,10,50,strcmp));

  	return 0; 
} */

/* Operazioni sulle stringhe */

int strcmp(const char *str1, const char *str2); /* Compares the string pointed
to by str1 to the string pointed to by str2. Returns zero if str1 and str2 are
equal. Returns less than zero or greater than zero if str1 is less than or
greater than str2 respectively. */

int strncmp(const char *str1, const char *str2, size_t n); /* ompares at most
the first n bytes of str1 and str2. Stops comparing after the null character.
Returns zero if the first n bytes (or null terminated length) of str1 and str2
are equal. Returns less than zero or greater than zero if str1 is less than or
greater than str2 respectively. */

size_t strlen(const char *str); /* Computes the length of the string str up to
but not including the terminating null character. Returns the number of
characters in the string. */

char *strstr(const char *str1, const char *str2); /* Finds the first
occurrence of the entire string str2 (not including the terminating null
character) which appears in the string str1. Returns a pointer to the first
occurrence of str2 in str1. If no match was found, then a null pointer is
returned. If str2 points to a string of zero length, then the argument str1 is
returned. */

char *strcpy(char *str1, const char *str2); /* Copies the string pointed to by
str2 to str1. Copies up to and including the null character of str2. If str1
and str2 overlap the behavior is undefined. Returns the argument str1. */

char *strncpy(char *str1, const char *str2, size_t n); /* Copies up to n
characters from the string pointed to by str2 to str1. Copying stops when n
characters are copied or the terminating null character in str2 is reached. If
the null character is reached, the null characters are continually copied to
str1 until n characters have been copied. Returns the argument str1. */
