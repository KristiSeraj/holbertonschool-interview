#include "slide_line.h"
void merge(int *line, int move, int i, int start,
	int *current, int *current_idx, int *blank)
{

	if (line[i] == 0)
	{
		*blank += 1;
	}

	if (i == start && line[i] != 0)
	{
		*current = line[i];
		*current_idx = i;
	}

	if (line[i] != 0 && line[i] == *current && i != start)
	{
		line[*current_idx] += line[i];
		line[i] = 0;
		*current = 0;
		*blank += 1;
	}

	if (line[i] != 0 && *current != line[i] && i != start)
	{
		line[i - (*blank * move)] = line[i];
		*current = line[i];
		*current_idx = i - (*blank * move);
		if (*blank)
			line[i] = 0;
	}
}
int slide_line(int *line, size_t size, int direction)
{

	int i, move, current, current_idx, blank, start;
	int sizeX = (int) size;

	if (!line || (direction != 0 && direction != 1))
		return (0);

	current = 0;
	blank = 0;

	if (direction == 0)
		move = 1;
	else
		move = -1;

	if (direction == 0)
	{
		for (i = start = current_idx =  0; i < sizeX; i++)
		{
			merge(line, move, i, start,
				&current, &current_idx, &blank);

		}
	}
	else
	{
		for (i = start = current_idx = sizeX - 1; i >= 0; i--)
		{
			merge(line, move, i, start,
				&current, &current_idx, &blank);
		}
	}
	return (1);
}
