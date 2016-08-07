/* Author: James Ridey 44805632
 *         james.ridey@students.mq.edu.au  
 * Creation Date: 02-08-2016
 * Last Modified: Fri 05 Aug 2016 05:10:54 AM CDT
 */
#include <stdio.h>

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
};

int main()
{
	struct Data data = {
		0,             //news
		0,             //edge
		1,             //error
		0,             //cent
		'G',           //holiday
		1,             //shake
		-32135.970703, //hair
		-63,           //snakes
		1,             //toad
		-1,            //window
		28451,         //space
		"quiet",       //cemetery
		0.007812,      //fang
		0321,          //chance
		-0.001250,     //development
		0xCC0          //spy
	};

	printf("news, edge, error, cent, holiday, shake, hair, "\
		   "snakes, toad, window, space, cemetery, fang, chance, development, spy\n");
	printf("%d, %d, %d, %d, %c, %d, %f, %lx, %d, %d, %u, %s, %f, %lu, %f, %lu\n",\
			data.news, data.edge, data.error, data.cent, data.holiday, data.shake,\
			data.hair, data.snakes, data.toad, data.window, data.space, data.cemetery,\
			data.fang, data.chance, data.development, data.spy);  

	return 0;
}

