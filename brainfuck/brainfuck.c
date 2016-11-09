/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 12:08:59 by exam              #+#    #+#             */
/*   Updated: 2016/10/18 12:41:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_whilestart(char *s, char *res, int i)
{
	int count;

	count = 1;
	if (res[i] != 0)
		return (s);
	while (count != 0)
	{
		++s;
		if (*s == ']')
			count--;
		else if (*s == '[')
			count++;
	}
	return (s);
}

char 	*ft_whileend(char *s, char *res, int i)
{
	int count;

	count = 1;
	if (res[i] == 0)
		return (s);
	while (count != 0)
	{
		--s;
		if (*s == '[')
			count--;
		else if (*s == ']')
			count++;
	}
	return (s);
}

void	brainfuck(char *s)
{
	char	*res;
	int		i;

	res = (char *)malloc(2048);
	if (!res)
		return ;
	i = 0;
	while (i < 2048)
	{
		res[i] = 0;
		i++;
	}
	i = 0;
	while (*s != '\0')
	{
		if (*s == '>')
			i++;
		else if (*s == '<')
			i--;
		else if (*s == '+')
			res[i] += 1;
		else if (*s == '-')
			res[i] -= 1;
		else if (*s == '.')
			ft_putchar(res[i]);
		else if (*s == '[')
			s = ft_whilestart(s, res, i);
		else if (*s == ']')
			s = ft_whileend(s, res, i);
		s++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		brainfuck(argv[1]);
	return (0);
}
