/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:05:30 by mkartit           #+#    #+#             */
/*   Updated: 2024/03/14 20:05:32 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**strings;

	if (ac == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	strings = ft_get_values(av, ac);
	ft_create_stack(&stack_a, strings);
	if (!ft_check_sorted(stack_a))
		ft_push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
