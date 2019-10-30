#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void bufset (char *buf, char c, size_t len) {
	// very similar function to memset, to initialize a char array
	for (int i = 0; i < len; i++) {
		buf [i] = c;
	}
}

int main () {
	char s [128];
	bufset (s, 0, sizeof (char) * 128);
	strcpy (s, "hello world");

	//char *s = strdup("hello world!");
	free (s); //invalid free, can resolve this if use malloc or strdup like above
}
