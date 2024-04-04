/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:17:12 by mkartit           #+#    #+#             */
/*   Updated: 2024/03/19 12:17:14 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_bonus(t_stack **stack_a, t_stack **stack_b, char *line)
{
	ft_putstr_fd("Error\n", 2);
	get_next_line(-1);
	free(line);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	exit(255);
}

void	exec_instructions(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		func_swap(stack_a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		func_swap(stack_b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		func_ss(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		func_push(stack_b, stack_a, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		func_push(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		func_rotate(stack_a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		func_rotate(stack_b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		func_rr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		func_rev_rotate(stack_a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		func_rev_rotate(stack_b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		func_rrr(stack_a, stack_b, 0);
	else
		ft_free_bonus(stack_a, stack_b, line);
	free(line);
}

void	read_in(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		exec_instructions(line, stack_a, stack_b);
	}
	if (ft_lstsize(*stack_b) != 0)
	{
		ft_putstr_fd("KO\n", 2);
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		exit(1);
	}
}

void	check_if_sorted(t_stack *stack_a)
{
	if (ft_check_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	read_in(&stack_a, &stack_b);
	check_if_sorted(stack_a);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
