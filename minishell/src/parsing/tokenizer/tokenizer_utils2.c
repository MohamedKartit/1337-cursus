/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho <aghergho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:31:01 by aghergho          #+#    #+#             */
/*   Updated: 2024/08/27 19:04:26 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mshell.h"

int	check_parenthise_token(char *token, int index)
{
	if (is_l_parenthise(token[index]))
		return (check_left_p_token(token, index));
	return (check_right_p_token(token, index));
}

int	check_parenthis_token(char *cmd, int i, int start)
{
	return ((is_parenthise(cmd[i]) && check_parenthise_token(cmd, i))
		&& !ft_check_quote(cmd, i) && start == -1);
}
