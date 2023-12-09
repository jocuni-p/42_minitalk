/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:35 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/12/08 10:41:28 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

/*---------------TRADUCE str A BITS-----------*/

void	encoder(char *str, int pid)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & (1 << j))
				e = kill(pid, SIGUSR1);
			else
				e = kill(pid, SIGUSR2);
			if (e == -1)
			{
				write(1, "Error (kill function failure)\n", 30);
				exit(EXIT_FAILURE);
			}
			j++;
			usleep(80);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || ft_atoi(av[1]) < 1 || !av[2] || av[2][0] == '\0')
	{
		write(1, "INVALID ARGUMENTS!\n", 19);
		write(1, "Usage: ./client <server_pid> <string>\n", 39);
		return (0);
	}
	pid = ft_atoi(av[1]);
	encoder(av[2], pid);
	return (0);
}
