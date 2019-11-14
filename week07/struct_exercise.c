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

void printName (Info *info) {
	printf("%s\n", info->full_name->fname);
	printf("%s\n", info->full_name->lname);
	printf("%d\n", info->age);
}

void destroyInfo (Info *info) {
	free (info->full_name->fname);
	free (info->full_name->lname);
	free (info->full_name);
	free (info);
}

int main () {
	FullName *name = (FullName *)malloc(sizeof(FullName));
	name->fname = strdup ("John");
	name->lname = strdup ("Doe");

	Info *info = (Info *)malloc (sizeof(Info));
	info->age = 30;
	info->full_name = name;
	info->print = printName;
	info->destroy = destroyInfo;

	info->print(info);
	info->destroy(info);
}