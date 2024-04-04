/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:05:44 by mkartit           #+#    #+#             */
/*   Updated: 2024/03/14 20:05:46 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_b(t_stack **stack_a, t_stack **stack_b, t_chunk *data)
{
	int	j;

	j = 0;
	if (data->position < ft_lstsize(*stack_a) / 2)
		while (j++ < data->position)
			func_rotate(stack_a, 1);
	else
		while (j++ < ft_lstsize(*stack_a) - data->position)
			func_rev_rotate(stack_a, 1);
	if ((*stack_a)->index >= data->size - (data->offset / 2))
	{
		func_push(stack_a, stack_b, 2);
		func_rotate(stack_b, 2);
	}
	else
		func_push(stack_a, stack_b, 2);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_chunk *data)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (i++ < data->offset && *stack_a)
	{
		tmp = *stack_a;
		data->position = 0;
		while (tmp && tmp->index > data->size)
		{
			tmp = tmp->next;
			data->position++;
		}
		put_b(stack_a, stack_b, data);
	}
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b))
	{
		if ((*stack_b)->index == highest_index(*stack_b)
			|| (*stack_b)->index == highest_index(*stack_b) - 1)
			func_push(stack_b, stack_a, 1);
		else if (pos_finder(stack_b,
				highest_index(*stack_b)) > ft_lstsize(*stack_b) / 2)
			while (!((*stack_b)->index == highest_index(*stack_b)
					|| (*stack_b)->index == highest_index(*stack_b) - 1))
				func_rev_rotate(stack_b, 2);
		else
			while (!((*stack_b)->index == highest_index(*stack_b)
					|| (*stack_b)->index == highest_index(*stack_b) - 1))
				func_rotate(stack_b, 2);
		if (ft_lstsize(*stack_a) > 1
			&& (*stack_a)->index > (*stack_a)->next->index)
			func_swap(stack_a, 1);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_chunk	data;
	int		size_stack;

	size_stack = ft_lstsize(*stack_a);
	data.size = size_stack / n_chunks(size_stack);
	data.offset = size_stack / n_chunks(size_stack);
	while (ft_lstsize(*stack_a))
	{
		push_to_b(stack_a, stack_b, &data);
		if (size_stack <= 100 && n_chunks(size_stack) == 9)
			data.offset = 20;
		data.size += data.offset;
	}
	push_to_a(stack_a, stack_b);
}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	ft_get_indexes(stack_a);
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
			func_swap(&(*stack_a), 1);
	}
	else if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		sort_5(stack_a, stack_b, five_four(stack_a));
	else
		ft_sort(stack_a, stack_b);
}
