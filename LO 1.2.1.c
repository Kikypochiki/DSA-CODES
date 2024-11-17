#ifndef PLAYGROUND
#define PLAYGROUND
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char data1 = 'X';
	int data2 = 100;
	float data3 = 3.14f;

	void *p = &data1;
	printf("%c\n", *(char*)p);

	p = &data2;
	printf("%d\n", *(int*)p);

	p = &data3;
	printf("%.2f\n", *(float*)p);
}

#endif