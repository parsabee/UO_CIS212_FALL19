#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct name FullName;
typedef struct info Info;

struct name {
	char *fname;
	char *lname;
};

struct info {
	int age;
	FullName *full_name;
	void (*print)(Info *);
	void (*destroy)(Info *);
};

void printInfo (Info *info) {
	printf("first name: %s\n", info->full_name->fname);
	printf("last name: %s\n", info->full_name->lname);
	printf("age: %d\n", info->age);
}

void destroyInfo (Info *info) {
	free (info->full_name->fname);
	free (info->full_name->lname);
	free (info->full_name);
	free (info);
}

/*
 * return valid FullName* if successful, NULL if fail
 */
FullName *createName (char *first_name, char *last_name) {

	/* malloc full name */
	FullName *name = (FullName *)malloc(sizeof(FullName));
	/* 
	 * remember malloc might return NULL if you run out of memory
	 * always check to see that its not null
	 */
	if (name != NULL) {
		name->fname = strdup(first_name); /* strdup calls malloc, so you need to make sure it hasnt failed*/
		
		if (name->fname != NULL) {
			name->lname = strdup(last_name);

			if (name->lname != NULL) {
				return name;

			} else { /* strdup(last_name) returned NULL, i.e. malloc failure */
					 /* so we need to free what we have malloc'd so far and return NULL */

				/* free(name->lname) I dont want to do this, because I know that strdup(last_name) wasnt successful
				 * so name->lname doesn't have heap memory associated with it */
				free (name->fname);
				free (name);
				return NULL;
			}
		} else { /* strdup(first_name) returned NULL, i.e. malloc failure */

			free(name);
			return NULL;
		}
	}

	return name;
}

/*
 * return valid Info* if successful, NULL if fail
 */
Info *createInfo (int age, char *first_name, char *last_name) {

	/* malloc info */
	Info *info = (Info *)malloc(sizeof(Info));

	/* 
	 * remember malloc might return NULL if you run out of memory
	 * always check to see that its not null
	 */

	if (info != NULL) {

		FullName *name = createName(first_name, last_name);

		if (name != NULL) { /* remember we made our function `createName()' return NULL if unsuccessful 
							 * so we need to check that here */
			info->age = age;
			info->full_name = name;
			info->print = printInfo;
			info->destroy = destroyInfo;

		} else { /* malloc failure, free what malloc allocated successfully */
			/* so wont free (name) because it wasn't successful */
			/* but will free (info) because that was a successful allocation */
			free(info);
			return NULL;
		}
		return info;
	}
	return NULL; /* malloc info failed */
}

int main () {

	Info *info = createInfo (30, "John", "Doe");

	if (info != NULL) { /* remember `createInfo()' returns NULL if it failed */

		info->print(info);
		info->destroy(info);
		return 0;
	}
	return 1;
}