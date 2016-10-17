/* Author: James Ridey 44805632
 *         james.ridey@students.mq.edu.au  
 * Creation Date: 02-08-2016
 * Last Modified: Thu 11 Aug 2016 04:43:53 AM CDT
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Data 
{
	short news;
	short edge;
	char error;
	int cent;
	char holiday;
	char shake;
	float hair;
	long snakes;
	char toad;
	char window;
	unsigned short space;
	char cemetery[10];
	double fang;
	unsigned long chance;
	double development;
	unsigned int spy;
}; //_attribute__((__packed__)); 
//Disable padding in struct (This works with fwrite but is probably not in sprit of the problem

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr,"Usage: ./program file...\n");
		fprintf(stderr,"No file supplied\n");
		exit(EPERM);
	}

	FILE* file = fopen(argv[1], "rb");	
	if (file == NULL)
	{
		fprintf(stderr,"File does not exist\n");
		exit(ENOENT);
	}

	printf("news, edge, error, cent, holiday, shake, hair, "\
		   "snakes, toad, window, space, cemetery, fang, chance, development, spy\n");

	struct Data data = {0};
 	while(fread(&data.news, sizeof(short), 1, file))
	{
		fread(&data.edge, sizeof(short), 1, file);
		fread(&data.error, sizeof(char), 1, file);
		fread(&data.cent, sizeof(int), 1, file);
		fread(&data.holiday, sizeof(char), 1, file);
		fread(&data.shake, sizeof(char), 1, file);
		fread(&data.hair, sizeof(float), 1, file);
		fread(&data.snakes, sizeof(long), 1, file);
		fread(&data.toad, sizeof(char), 1, file);
		fread(&data.window, sizeof(char), 1, file);
		fread(&data.space, sizeof(short), 1, file);
		fread(&data.cemetery, 10*sizeof(char), 1, file);
		fread(&data.fang, sizeof(double), 1, file);
		fread(&data.chance, sizeof(long), 1, file);
		fread(&data.development, sizeof(double), 1, file);
		fread(&data.spy, sizeof(int), 1, file);

		printf("%d, %d, %d, %d, %c, %d, %f, %lx, %d, %d, %u, %s, %f, %lu, %f, %u\n",\
				data.news, data.edge, data.error, data.cent, data.holiday, data.shake,\
				data.hair, data.snakes, data.toad, data.window, data.space, data.cemetery,\
				data.fang, data.chance, data.development, data.spy);  
	}

	fclose(file);

	return 0;
}

