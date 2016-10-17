/* Author: James Ridey 44805632
 *         james.ridey@students.mq.edu.au  
 * Creation Date: 10-08-2016
 * Last Modified: Thu 18 Aug 2016 09:32:49 PM AEST
 */
#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int init_array(Array* array)
{
	Data** tmp = malloc(sizeof(Data*));
	if (tmp) array->data = tmp;
	else return 1;
	array->counter = 0;
	array->size = 1;
	return 0;
}

int check_array(Array* array)
{
	if (array->counter >= array->size)
	{
		array->size *= 2;
		Data** tmp = realloc(array->data, array->size * sizeof(Data*));
		if (tmp) array->data = tmp;
		else return 1;
	}
	return 0;
}

int push_array(Array* array, Data* data)
{
	array->data[array->counter++] = data;
	return check_array(array);
}

void free_array(Array* array)
{
	int i;
	for (i = 0; i < array->counter; i++)
	{
		free(array->data[i]);
		array->data[i] = NULL;
	}
	free(array->data);

	array->data = NULL;
}

void print_array(Array* array)
{
	int i;
	for (i = 0; i < array->counter-1; i++)
	{
		Data data = *array->data[i];
		printf("%d, %d, %d, %d, %c, %d, %f, %lx, %d, %d, %u, %s, %f, %lu, %f, %u\n",\
				data.news, data.edge, data.error, data.cent, data.holiday, data.shake,\
				data.hair, data.snakes, data.toad, data.window, data.space, data.cemetery,\
				data.fang, data.chance, data.development, data.spy);  
	}
}

