#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include "myprint.h"

int myprint(const char* fmt,...){
    va_list args;
    va_start(args,fmt);

    int numFormats = 0;
    int i = 0;
    while(*(fmt+i)){
        if(*(fmt+i) == '&'){
	    printf("%d",va_arg(args,int));
	    numFormats++;
	}else
	    printf("%c",*(fmt+i));
        i++;
    }
    return numFormats;
}
