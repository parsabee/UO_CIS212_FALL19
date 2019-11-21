#include <stdio.h>
#include <stdlib.h>

typedef struct parent {
	void *self;
	void (*print)(void *);
}Parent;

typedef struct child {
	int a;
	int b;
}Child;

void printing (void *s) {
	Child *little = (Child *)s;
	printf ("%d\n", little->a);
	printf ("%d\n", little->b);
}

void printParent (Parent *p) {
	p->print(p->self);
}

int main () {

	/* child class */
	Child *c = malloc (sizeof(Child));
	c->a = 22;
	c->b = 33;

	/* parent class */
	Parent *p = malloc (sizeof(p));
	p->self = c;
	p->print = printing;

	printParent(p);
}
