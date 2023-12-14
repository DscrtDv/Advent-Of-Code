/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 18:38:46 by tcensier      #+#    #+#                 */
/*   Updated: 2023/12/14 20:15:15 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//Advent of code day 1

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

void	get_num(char *line)
{
	int found = 0;
	char *num;
	
	while (line && *line)
	{
		while (isdigit(*line))
		{
			if (!isdigit(*(line + 1)))
				found++;
			if (found == 0)
			{
				*num = *line;
				num++;
			}
			line++;
		}
		*num = '\0';
		found = 0;
		printf("%s\n", num);
		line++;
	}
}

int main (void)
{
	char *line = NULL;
	size_t len = 0;
	FILE *fd = fopen("input.txt", "r");
	
	if (fd != NULL)
	{
		while (getline(&line, &len, fd) != -1)
		{
			get_num(line);
		}
		free(line);
		fclose(fd);
	}
	return (0);
}