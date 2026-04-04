#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *name_copy;
	char *owner_copy;
	int i;

	if (name == NULL || owner == NULL)
		return (NULL);

	/* allocate dog struct */
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	/* allocate and copy name */
	for (i = 0; name[i]; i++)
		;
	name_copy = malloc(i + 1);
	if (name_copy == NULL)
	{
		free(dog);
		return (NULL);
	}
	for (i = 0; name[i]; i++)
		name_copy[i] = name[i];
	name_copy[i] = '\0';

	/* allocate and copy owner */
	for (i = 0; owner[i]; i++)
		;
	owner_copy = malloc(i + 1);
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(dog);
		return (NULL);
	}
	for (i = 0; owner[i]; i++)
		owner_copy[i] = owner[i];
	owner_copy[i] = '\0';

	/* assign values */
	dog->name = name_copy;
	dog->age = age;
	dog->owner = owner_copy;

	return (dog);
}
