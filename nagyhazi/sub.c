#include <stdio.h>
#include <stdlib.h>
#include "sub.h"

/* fuggveny arra, hogy a kapott rgb ertekek 0 es 255 kozott maradjanak*/
int truncate (float x)
{
    if(x<0) return 0;
    if(x>255) return 255;
    return x;
}

