/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:58:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/12/08 12:37:11 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

/*------CONVIERTE 'SIGUSR1 = 1' y 'SIGUSR2 = 0' A BIT->CHAR->STRING-------*/
void	decoder(int sig)
{
	static int	i = 0;// son estaticas para no perder el valor entre llamadas
	static int	c = 0;//pongo todos los bits a valor 0

	if (sig == SIGUSR1)
		c = c | (1 << i);//establece a 1 el valor del bit 'i' del char 'c' (rellenando los bits de der. a izq.)
	i++;
	if (i == 8)//si tenemos ya los 8 bits que conforman el byte
	{
		write(1, &c, 1);
		i = 0;
		c = 0;//reinicio valores para empezar con un nuevo char
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
	while (1)//while infinito para mantener el programa/proceso en marcha
		;
	return (0);
}
