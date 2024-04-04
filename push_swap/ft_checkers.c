/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:03:55 by mkartit           #+#    #+#             */
/*   Updated: 2024/03/14 20:03:58 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_checker(char *number)
{
	int	i;

	i = 0;
	if (ft_strlen(number) > 11)
		return (TRUE);
	if (!(number[i] == '+' || number[i] == '-' || (number[i] >= '0'
				&& number[i] <= '9')))
		return (TRUE);
	if ((number[i] == '+' || number[i] == '-') && !(number[i + 1] >= '0'
			&& number[i + 1] <= '9'))
		return (TRUE);
	i++;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	ft_check_dub(t_stack *stack, int num)
{
	t_stack	*ptr;

	ptr = stack;
	if (ptr == NULL)
		return (FALSE);
	while (ptr->next)
	{
		if (ptr->num == num)
			return (TRUE);
		ptr = ptr->next;
	}
	return (FALSE);
}

t_bool	ft_check_sorted(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr->next)
	{
		if (ptr->num > ptr->next->num)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}
