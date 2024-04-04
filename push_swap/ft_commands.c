/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:04:11 by mkartit           #+#    #+#             */
/*   Updated: 2024/03/14 20:04:12 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_swap(t_stack **stack, int flag)
{
	t_stack	*temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->next = *stack;
		*stack = temp;
		if (flag == 1)
			ft_putstr_fd("sa\n", 1);
		else if (flag == 2)
			ft_putstr_fd("sb\n", 1);
		else
			return ;
	}
}

void	func_ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	func_swap(stack_a, 0);
	func_swap(stack_b, 0);
	if (flag == 1)
		ft_putstr_fd("ss\n", 1);
	else
		return ;
}

void	func_push(t_stack **stack_from, t_stack **stack_to, int flag)
{
	t_stack	*temp;

	if (*stack_from)
	{
		temp = *stack_from;
		*stack_from = (*stack_from)->next;
		temp->next = *stack_to;
		*stack_to = temp;
		if (flag == 1)
			ft_putstr_fd("pa\n", 1);
		else if (flag == 2)
			ft_putstr_fd("pb\n", 1);
		else
			return ;
	}
}

void	func_rotate(t_stack **stack, int flag)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		last = ft_lstlast(*stack);
		last->next = temp;
		temp->next = NULL;
		if (flag == 1)
			ft_putstr_fd("ra\n", 1);
		else if (flag == 2)
			ft_putstr_fd("rb\n", 1);
		else
			return ;
	}
}

void	func_rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	func_rotate(stack_a, 0);
	func_rotate(stack_b, 0);
	if (flag == 1)
		ft_putstr_fd("rr\n", 1);
	else
		return ;
}
