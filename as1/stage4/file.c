/* Author: James Ridey 44805632
 *         james.ridey@students.mq.edu.au  
 * Creation Date: 10-08-2016
 * Last Modified: Wed 10 Aug 2016 09:13:19 AM CDT
 */
#include "file.h"

Data* read_file(FILE* file, Array* array)
{
	static Data data = {0};

	if(!fread(&data.news, sizeof(short), 1, file)) return NULL;
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

	return &data;
}

void write_file(FILE* file, Array* array)
{
	int i;
	for (i = 0; i < array->counter; i++)
	{
		Data data = array->data[i];
		fwrite(&data.news, sizeof(short), 1, file);
		fwrite(&data.edge, sizeof(short), 1, file);
		fwrite(&data.error, sizeof(char), 1, file);
		fwrite(&data.cent, sizeof(int), 1, file);
		fwrite(&data.holiday, sizeof(char), 1, file);
		fwrite(&data.shake, sizeof(char), 1, file);
		fwrite(&data.hair, sizeof(float), 1, file);
		fwrite(&data.snakes, sizeof(long), 1, file);
		fwrite(&data.toad, sizeof(char), 1, file);
		fwrite(&data.window, sizeof(char), 1, file);
		fwrite(&data.space, sizeof(short), 1, file);
		fwrite(&data.cemetery, 10*sizeof(char), 1, file);
		fwrite(&data.fang, sizeof(double), 1, file);
		fwrite(&data.chance, sizeof(long), 1, file);
		fwrite(&data.development, sizeof(double), 1, file);
		fwrite(&data.spy, sizeof(int), 1, file);
	}
}
