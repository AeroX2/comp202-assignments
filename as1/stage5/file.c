/* Author: James Ridey 44805632
 *         james.ridey@students.mq.edu.au  
 * Creation Date: 10-08-2016
 * Last Modified: Thu 18 Aug 2016 09:30:26 PM AEST
 */
#include <stdlib.h>

#include "file.h"


Data* read_file(FILE* file)
{
	//Don't allocate memory until we know there is more to read
	short tmp_short;
	if(!fread(&tmp_short, sizeof(short), 1, file)) return NULL;

	Data* data = malloc(sizeof(Data));	
	data->holiday = (char) tmp_short;

	fread(&data->cemetery, 10*sizeof(char), 1, file);

	float tmp_float;
	fread(&tmp_float, sizeof(float), 1, file);
	data->space = (unsigned short) tmp_float;

	fread(&tmp_short, sizeof(short), 1, file);
	data->shake = (char) tmp_short;

	char tmp_char;
	fread(&tmp_char, sizeof(char), 1, file);
	data->cent = tmp_char >> 2 & 1;
	data->error = tmp_char >> 4 & 1;
	data->news = tmp_char >> 5 & 1;
	data->edge = tmp_char >> 7 & 1;

	data->snakes = read_msb(file,sizeof(int)).i;
	data->fang = read_msb(file,sizeof(float)).f;
	data->chance = read_msb(file, sizeof(short)).l;

	fread(&data->spy, sizeof(long), 1, file);
	
	data->development = (double) read_msb(file, sizeof(float)).f;

	fread(&data->toad, sizeof(short), 1, file);

	any_type tmp_union = read_msb(file, sizeof(double));
	tmp_union.l <<= sizeof(float)*8;
	data->hair = tmp_union.d;

	data->window = read_msb(file, sizeof(int)).c;

	return data;
}

any_type read_msb(FILE* file, int field_size)
{
	any_type field = {0};
	field.l = 0;
	
	int i;
	unsigned char temp;
	for (i = 0; i < field_size; i++)
	{
		fread(&temp, sizeof(char), 1, file);
		field.l |= temp << (i*8);
	}
	return field;
}

void write_file(FILE* file, Array* array)
{
	int i;
	for (i = 0; i < array->counter; i++)
	{
		Data data = *array->data[i];
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
