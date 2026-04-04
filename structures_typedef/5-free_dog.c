#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees a dog created with new_dog
 * @d: pointer to dog_t to free
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	/* free allocated strings first */
	if (d->name != NULL)
		free(d->name);
	if (d->owner != NULL)
		free(d->owner);

	/* free the struct itself */
	free(d);
}
