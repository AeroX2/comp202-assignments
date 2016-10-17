#ifndef ARRAY_H
#define ARRAY_H

typedef struct Data 
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
} Data;

typedef struct Array
{
	Data** data;
	int counter;
	int size;
} Array;

int init_array(Array* array);
int check_array(Array* array);
int push_array(Array* array, Data* data);
void free_array(Array* array);

void print_array(Array* array);

#endif
