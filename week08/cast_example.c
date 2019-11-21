#include <stdio.h>
#include <stdlib.h>

typedef struct parent {
	void *self;
	void (*print)(void *);
}Parent;

typedef struct child {
	int a; /* two random ints */
	int b;
}Child;

void printChild (void *s) {/* this function will be assigned to Parent->print function*/

	Child *c = (Child *)s; /* we have to do this cast */
	printf ("%d\n", c->a);
	printf ("%d\n", c->b);
}

void printParent (Parent *p) {
	p->print(p->self);
}

Parent *CreateChild (int a, int b)
{

	/* child class */
	Child *c = malloc (sizeof(Child));
	c->a = a; 
	c->b = b

	/* parent class */
	Parent *p = malloc (sizeof(p));
	p->self = c;
	p->print = printChild;

	return p;
}

void Destroy(Parent *p) {
	free(p->self);
	free(p);
}

int main () {

	Parent *p = CreateChild(22, 33);
	printParent(p);
	Destroy (p);
}
