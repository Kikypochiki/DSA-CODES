#include <stdio.h>
#include <stdlib.h>

//dynamic memory allocation
int main()
{

	int x = 10;
	int *p = (int*)malloc(sizeof(int));

	p = &x;
	*p = 8;

	float y = 3.14f;

	float *pi = (float*)malloc(sizeof(float));
	pi = &y;

	p = (int*)pi;

	float *p_ptr;
	p_ptr = (float*)p;

	printf("%.2f\n", (float)*p_ptr);
	//printf("%.2f\n", y);
	return 0;
}
