#include "monty.h"
/**
 * _calloc - concatenate tw strings specially
 * @eles: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *_calloc(unsigned int eles, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (eles == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(eles * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (eles * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
/**
 * _realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @osize: old number of bytes
 * @nsize: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int osize, unsigned int nsize)
{
	char *p = NULL;
	unsigned int i;

	if (nsize == osize)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(nsize);
		if (!p)
			return (NULL);
		return (p);
	}
	if (nsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (nsize > osize)
	{
		p = malloc(nsize);
		if (!p)
			return (NULL);
		for (i = 0; i < osize; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(nsize);
		if (!p)
			return (NULL);
		for (i = 0; i < nsize; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
