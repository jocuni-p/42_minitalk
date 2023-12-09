/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:58:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/12/06 10:54:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

/*------TRADUCE 'SIGUSR1 = 1' y 'SIGUSR2 = 0' A BIT->CHAR->STRING-------*/
void	decoder(int sig)
{
	static int	i = 0;
	static int	c = 0;

	if (sig == SIGUSR1)
		c = c | (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

/*---------ENTREGA EL PID Y ACTIVA RECEPCION DE SIGNALS---------*/
int	main(void)
{
	write(1, "'server' process running. ID [", 30);
	ft_putnbr_fd(getpid(), 1);
	write(1, "]\n", 2);
	write(1, "Waiting for a signal ", 21);
	sleep(1);
	write(1, ".", 1);
	sleep(1);
	write(1, ".", 1);
	sleep(1);
	write(1, ".\n", 2);
	signal(SIGUSR1, decoder);
	signal(SIGUSR2, decoder);
	while (1)
		;
	return (0);
}
