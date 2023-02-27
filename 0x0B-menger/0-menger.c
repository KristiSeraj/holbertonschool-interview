#include "menger.h"
/**
 * checks - checks for indices
 * @j: column
 * @i: row
 * Return: 1 if indices (1, 1) otherwise 0
 */
int checks(int i, int j)
{
	while (i != 0 && j != 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (0);

		i /= 3, j /= 3;
	}
	return (1);
}
/**
 * menger - draws a 2D level menger
 * @level: lever of menger sponge to draw
 */
void menger(int level)
{
	int i, j, limit;

	if (level < 0)
		return;

	for (i = 0, limit = pow(3, level); i < limit; i++)
	{
		for (j = 0; j < limit; j++)
		{
			checks(i, j) == 1 ? printf("%c", '#') : printf("%c", ' ');
		}
		printf("\n");
	}
}
