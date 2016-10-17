/* Author: James Ridey 44805632
 *         james.ridey@students.mq.edu.au  
 * Creation Date: 02-08-2016
 * Last Modified: Mon 15 Aug 2016 06:06:13 PM AEST
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "array.h"
#include "file.h"

#define min(a,b) \
	(((a) < (b)) ? (a) : (b))

#define asc(a,b) \
	if (a > b) return 1; \
	else if (a < b) return -1;

#define des(a,b) \
	if (a > b) return -1; \
	else if (a < b) return 1;

int cmpfunc(const void* this, const void* other);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr,"Usage: ./program input output...\n");
		fprintf(stderr,"Not enough arguments\n");
		exit(EPERM);
	}

	FILE* file = fopen(argv[1], "rb");	
	if (file == NULL)
	{
		fprintf(stderr,"Input file does not exist\n");
		exit(ENOENT);
	}

	Array data_entries = {0};
	if (init_array(&data_entries))
	{
		fprintf(stderr, "Could not allocate space for array");
		exit(ENOMEM);
	}

	Data* data = NULL;
	while((data = read_file(file, &data_entries)))
	{
		if (push_array(&data_entries, data))
		{
			fprintf(stderr, "Could not allocate space for array");
			exit(ENOMEM);
		}
	}
	fclose(file);

	//print_array(&data_entries);
	qsort(data_entries.data, data_entries.counter, sizeof(Data*), cmpfunc);
	//print_array(&data_entries);
	
	file = fopen(argv[2], "wb");
	write_file(file, &data_entries);
	fclose(file);
	
	free_array(&data_entries);

	return 0;
}

int cmpfunc(const void* this, const void* other)
{
	Data a = **((Data**) this);
	Data b = **((Data**) other);

	asc(a.spy, b.spy)
	asc(a.edge, b.edge)
	des(a.window, b.window)
	asc(a.cent, b.cent)
	des(a.snakes, b.snakes)
	asc(a.shake, b.shake)

	des(strcmp(a.cemetery, b.cemetery), 0)

	des(a.news, b.news)
	asc(a.hair, b.hair)
	des(a.development, b.development)
	asc(a.toad, b.toad)
	des(a.error, b.error)
	asc(a.chance, b.chance)
	asc(a.space, b.space)
	des(a.fang, b.fang)
	asc(a.holiday, b.holiday)

	return 0;
}

