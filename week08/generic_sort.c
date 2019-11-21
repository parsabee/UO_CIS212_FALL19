#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

void
swap ( void *array, size_t size, int i, int j)
{

	/* a generic swap would be like this
	 *
	 *	tmp = array [i]         store content of array[i] in a temp valriable
	 *  array [i] = array [j]   update content of array [i] to be array [j]
	 *  array [j] = tmp         update array [j] to be whats in tmp   
	 */

	char tmp [size];      // tem variable
	memset(tmp, 0, size); //tmp is not initiallize, this initializes it
	memcpy(tmp, array+i*size, size);          //      tmp = array[i]
	memcpy(array+i*size, array+j*size, size); // array[i] = array[j]
	memcpy(array+j*size, tmp, size);          // array[j] = tmp
}

int
intCmpFxn (void *a, void *b)
{
	/* compare function for int types */
	int *ia = (int *)a;
	int *ib = (int *)b;
	if (*ia < *ib)
		return -1;
	else if (*ia > *ib)
		return 1;
	else
		return 0;
}

int
charCmpFxn (void *a, void *b)
{
	/* compare function for char types */
	char *ia = (char *)a;
	char *ib = (char *)b;
	if (*ia < *ib)
		return -1;
	else if (*ia > *ib)
		return 1;
	else
		return 0;
}

void
sort (void *array, size_t size, int n_items, int (*cmpFxn)(void *, void *))
{
	/* bubble sort */

	for (int i = 0; i < n_items; i++)
	{
		for (int j = i+1; j < n_items; j++)
		{

			// you can't use array[i] because you can't dereference a void* 
			if (cmpFxn(array+i*size, array+j*size) > 0)
			{
				swap(array, size, i, j);
			}
		}
	}
}

int
main ()
{
	int A[5] = {5, 4, 3, 2, 1};
	printf("before: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	sort((void *)A, sizeof(int), 5, intCmpFxn);

	printf("after: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");



	char B[5] = {'c', 'd', 'a', 'f', 'x'};
	printf("before: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%c ", B[i]);
	}
	printf("\n");
	sort((void *)B, sizeof(char), 5, charCmpFxn);

	printf("after: ");
	for (int i = 0; i < 5; i++)
	{
		printf("%c ", B[i]);
	}
	printf("\n");
}







