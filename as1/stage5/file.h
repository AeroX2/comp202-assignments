#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#include "array.h"

typedef union
{
	char c;
	int i;
	long l;
	float f;
	double d;
} any_type;

Data* read_file(FILE* file);
any_type read_msb(FILE* file, int size);
void write_file(FILE* file, Array* array);

#endif
