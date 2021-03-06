/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:51:23 by gzagura           #+#    #+#             */
/*   Updated: 2017/12/11 13:51:24 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	get_number(const char *str)
{
	unsigned long int	n;
	int					i;
	int					sign;

	i = -1;
	sign = 1;
	n = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*(str + ++i) <= '9' && *(str + i) >= '0')
	{
		if ((n > 922337203685477580 || (n == 922337203685477580
										&& *(str + i) - '0' > 7)) && sign == 1)
			return (-1);
		if ((n > 922337203685477580 || (n == 922337203685477580
										&& *(str + i) - '0' > 8)) && sign == -1)
			return (0);
		n = n * 10 + (*(str + i) - 48);
	}
	return ((int)(n * sign));
}

int			ft_atoi(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	return (get_number(str));
}
