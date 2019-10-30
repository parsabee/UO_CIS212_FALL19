#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	FILE *f = fopen ("reading.c", "r");
	if (f) {
		fseek (f, 0, SEEK_END);
		long len = ftell (f);
		fseek (f, 0, SEEK_SET);
		char buf [len + 1]; // +1 because we need one extra character for null terminating char
		memset (buf, 0, sizeof (char) *(len+1)); //initialize buffer
		fread (buf, sizeof (char), len, f);
		printf ("%s\n", buf);
		fclose (f);	
	}
}
