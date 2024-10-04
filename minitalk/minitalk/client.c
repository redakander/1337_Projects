/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:04:29 by rkander           #+#    #+#             */
/*   Updated: 2024/07/14 19:35:20 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include "minitalk.h"

int	pid_convert(const char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		else
			exit(0);
		if (nb > 4194304)
			exit(0);
		i++;
	}
	return (nb);
}

static void	envoyer_binaire(int num, int pid)
{
	int		i;
	int		mask;

	i = 7;
	while (i >= 0)
	{
		mask = (1 << i);
		if (num & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	int		num;

	if (ac != 3)
		return (write(1, "Syntax error:./client \"pid\" \"message\"\n", 38), 1);
	pid = pid_convert(av[1]);
	i = 0;
	while (av[2][i])
	{
		num = av[2][i];
		envoyer_binaire(num, pid);
		i++;
	}
}
