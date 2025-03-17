/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergho <aghergho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:59:17 by aghergho          #+#    #+#             */
/*   Updated: 2025/03/17 12:07:14 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_check_empty_element(char *comp)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (comp[i])
	{
		if (comp[i] == ',')
			counter++;
		i++;
	}
	if (counter > 2)
		return (0);
	return (1);
}

int	ft_check_components(int identifier_id, char **components, int *counter)
{
	if (identifier_id == 1)
		return (ft_check_ambient_component(components, counter));
	if (identifier_id == 2)
		return (ft_check_camera_component(components, counter));
	if (identifier_id == 3)
		return (ft_check_light_component(components, counter));
	if (identifier_id == 4)
		return (ft_check_sphere_component(components));
	if (identifier_id == 5)
		return (ft_check_plane_component(components));
	if (identifier_id == 6)
		return (ft_check_cylinder_component(components));
	if (identifier_id == 7)
		return (ft_check_cone_component(components));
	return (1);
}

int	is_identifier(char *identifier)
{
	if (identifier && !ft_strcmp(identifier, "A"))
		return (1);
	if (identifier && !ft_strcmp(identifier, "C"))
		return (2);
	if (identifier && !ft_strcmp(identifier, "L"))
		return (3);
	if (identifier && !ft_strcmp(identifier, "sp"))
		return (4);
	if (identifier && !ft_strcmp(identifier, "pl"))
		return (5);
	if (identifier && !ft_strcmp(identifier, "cy"))
		return (6);
	if (identifier && !ft_strcmp(identifier, "co"))
		return (7);
	return (0);
}

int	ft_check_map_components(t_map **map)
{
	t_map_line	*tmp;
	int			identifier_id;
	int			i;

	i = 0;
	tmp = (*map)->lines;
	while (tmp)
	{
		identifier_id = is_identifier(tmp->line_component[0]);
		if (!identifier_id)
			return (error_handler(0, i, tmp->line_component[0]),
				ft_free_map(&(*map)->lines), 0);
		if (!ft_check_components(identifier_id, tmp->line_component,
				((*map)->scen_elements)))
			return (error_handler(1, i, ""), ft_free_map(&(*map)->lines), 0);
		tmp = tmp->next;
		i++;
	}
	if ((*map)->scen_elements[0] > 1 || (*map)->scen_elements[1] > 1
		|| (*map)->scen_elements[1] < 1)
		return (error_handler(2, i, ""), ft_free_map(&(*map)->lines), 0);
	return (1);
}
