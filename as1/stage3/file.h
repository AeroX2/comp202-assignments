#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#include "array.h"

Data* read_file(FILE* file, Array* array);
void write_file(FILE* file, Array* array);

#endif
