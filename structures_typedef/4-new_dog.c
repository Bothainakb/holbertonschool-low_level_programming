#include "dog.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string using malloc
 * @str: string to duplicate
 *
 * Return: pointer to new string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *copy;
	int i;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		;

	copy = malloc(i + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		copy[i] = str[i];
	copy[i] = '\0';

	return (copy);
}

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

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = _strdup(name);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = _strdup(owner);
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	dog->age = age;

	return (dog);
}
