#include "swap.h"

void Swap(char *left, char *right)
{
	char swap=*left;
	*left=*right;
	*right=swap;
}