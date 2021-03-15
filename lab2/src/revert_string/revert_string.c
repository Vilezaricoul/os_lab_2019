#include "revert_string.h"

void RevertString(char *str)
{
	int length = 0, i;
    char *begin, *end, temp;
 
    while( *(str + length) != '\0' )
        length++;

    begin  = str;
    end    = str;
    for (i = 0; i < length - 1; i++)
        end++;
 
    for (i = 0; i < length/2; i++)
        {        
        temp   = *end;
        *end   = *begin;
        *begin = temp;
 
        begin++;
        end--;
        }
}