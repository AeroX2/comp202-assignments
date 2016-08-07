/* Author: James Ridey 44805632
 *         james.ridey@students.mq.edu.au  
 * Creation Date: 02-08-2016
 * Last Modified: Fri 05 Aug 2016 10:02:23 AM CDT
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Data 
{
	short news : 16;
	short edge : 16;
	char error : 8;
	int cent : 32;
	char holiday : 8;
	char shake : 8;
	float hair;
	long snakes : 64;
	char toad : 8;
	char window : 8;
	unsigned short space : 16;
	char cemetery[10];
	double fang;
	unsigned long chance;
	double development;
	unsigned int spy : 32;
} __attribute__((__packed__)) Data; //Disable padding in struct

typedef struct Array
{
	Data* data;
	int counter;
	int size;
} Array;

void print_array(Data* array, int length);
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
	data_entries.data = malloc(sizeof(Data));
	data_entries.counter = 0;
	data_entries.size = 1;
 	while(fread(&data_entries.data[data_entries.counter++], sizeof(Data), 1, file))
	{
		if (data_entries.counter >= data_entries.size)
		{
			data_entries.size *= 2;
			Data* tmp = realloc(data_entries.data, data_entries.size * sizeof(Data));
			if (tmp) data_entries.data = tmp;
			else
			{
				fprintf(stderr, "Could not allocate space for array");
				exit(ENOMEM);
			}
		}
	}
	fclose(file);

	//print_array(data_entries.data, data_entries.counter-1);
	qsort(data_entries.data, data_entries.counter, sizeof(Data), cmpfunc);
	print_array(data_entries.data, data_entries.counter-1);
	
	file = fopen(argv[2], "w");
	fwrite(data_entries.data, sizeof(Data), data_entries.counter, file); 
	fclose(file);
	
	free(data_entries.data);	

	return 0;
}

void print_array(Data* array, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		Data data = array[i];
		printf("%d, %d, %d, %d, %c, %d, %f, %lx, %d, %d, %u, %s, %f, %lu, %f, %u\n",\
				data.news, data.edge, data.error, data.cent, data.holiday, data.shake,\
				data.hair, data.snakes, data.toad, data.window, data.space, data.cemetery,\
				data.fang, data.chance, data.development, data.spy);  
	}
}

int cmpfunc(const void* this, const void* other)
{
	Data a = *(Data*)this;
	Data b = *(Data*)other;
	
	if (a.spy > b.spy) return 0; 
	if (a.edge > b.edge) return 0; 
	if (a.window < b.window) return 0; 
	if (a.cent > b.cent) return 0; 
	if (a.snakes < b.snakes) return 0; 
	if (a.shake > b.shake) return 0; 

	int i;
	for (i = 0; i < strlen(a.cemetery); i++)
	{
		if (a.cemetery[i] < b.cemetery[i]) return 0;
	}

	if (a.news < b.news) return 0; 
	if (a.hair > b.hair) return 0; 
	if (a.development < b.development) return 0; 
	if (a.toad > b.toad) return 0; 
	if (a.error < b.error) return 0; 
	if (a.chance > b.chance) return 0; 
	if (a.space > b.space) return 0; 
	if (a.fang < b.fang) return 0; 
	if (a.holiday > b.holiday) return 0; 
	return 0;
}

