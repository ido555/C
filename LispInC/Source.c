#include <stdio.h>

void main() {
	char* text = "abc test 123";
	puts(text);

	typedef struct {
		float x;
		float y;
	} point;

	point p;
	p.x = 5.5;
	p.y = 12;
	return;
};