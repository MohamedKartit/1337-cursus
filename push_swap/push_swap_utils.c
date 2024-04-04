/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:17:36 by mkartit           #+#    #+#             */
/*   Updated: 2024/03/19 12:17:40 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_indexes(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *stack;
	if (!tmp->next)
		return ;
	while (tmp)
	{
		tmp->index = 0;
		tmp1 = *stack;
		while (tmp1)
		{
			if (tmp->num > tmp1->num)
				tmp->index++;
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

int	ft_min_num_pos(t_stack **stack)
{
	int		pos;
	t_stack	*temp;

	temp = *stack;
	pos = 0;
	while (temp->index != 0)
	{
		temp = temp->next;
		pos++;
	}
	return (pos);
}

t_stack	*ft_min_num(t_stack **stack)
{
	int		pos;
	t_stack	*temp;

	temp = *stack;
	pos = 0;
	while (temp->index != 0)
	{
		temp = temp->next;
		pos++;
	}
	return (temp);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, int flag)
{
	int		min_pos;
	t_stack	*temp;
	t_stack	*min_node;

	min_node = ft_min_num(stack_a);
	min_pos = ft_min_num_pos(stack_a);
	while ((*stack_a)->index != min_node->index)
	{
		if (min_pos <= 2)
			func_rotate(stack_a, 1);
		else
			func_rev_rotate(stack_a, 1);
	}
	func_push(stack_a, stack_b, 2);
	temp = *stack_a;
	while (temp)
	{
		temp->index = temp->index - 1;
		temp = temp->next;
	}
	if (flag == 1)
		sort_3(stack_a);
	else if (flag == 2)
		sort_5(stack_a, stack_b, 1);
	func_push(stack_b, stack_a, 1);
}

void	sort_3(t_stack **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num
		&& (*stack_a)->next->num > (*stack_a)->next->next->num)
		(func_swap(&(*stack_a), 1), func_rev_rotate(&(*stack_a), 1));
	else if ((*stack_a)->num > (*stack_a)->next->num
		&& (*stack_a)->next->num < (*stack_a)->next->next->num
		&& (*stack_a)->num > (*stack_a)->next->next->num)
		func_rotate(&(*stack_a), 1);
	else if ((*stack_a)->num < (*stack_a)->next->num
		&& (*stack_a)->next->num > (*stack_a)->next->next->num
		&& (*stack_a)->num > (*stack_a)->next->next->num)
		func_rev_rotate(&(*stack_a), 1);
	else if ((*stack_a)->num > (*stack_a)->next->num
		&& (*stack_a)->next->num < (*stack_a)->next->next->num)
		func_swap(&(*stack_a), 1);
	else if ((*stack_a)->num < (*stack_a)->next->num
		&& (*stack_a)->next->num > (*stack_a)->next->next->num)
		(func_swap(&(*stack_a), 1), func_rotate(&(*stack_a), 1));
}
