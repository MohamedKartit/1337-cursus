/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:32:16 by mkartit           #+#    #+#             */
/*   Updated: 2024/03/15 16:32:21 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef enum a_bool
{
	FALSE = 0,
	TRUE = 1,
}					t_bool;

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_chunk
{
	int				size;
	int				offset;
	int				position;
}					t_chunk;

/*========== Pasring ==========*/
char				**ft_get_values(char **av, int ac);
char				**ft_split_numbers(char **av, int ac, int size);
char				**ft_split(char const *s, char c);
unsigned int		ft_cwords(const char *s, char c);
void				ft_create_stack(t_stack **stack_a, char **strings);
/*========== Checkers ==========*/
t_bool				ft_check_dub(t_stack *stack, int num);
t_bool				ft_checker(char *number);
t_bool				ft_check_sorted(t_stack *stack);
/*========== Utils ==========*/
size_t				ft_strlen(const char *s);
int					ft_lstsize(t_stack *lst);
void				free_all(t_stack **stack_a, char **strings, int flag);
void				free_func(char **strings);
long				ft_atoi(const char *nptr);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstclear(t_stack **lst);
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstlast(t_stack *lst);
/*========== printing =========*/
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
/*========== Commands ==========*/
void				func_swap(t_stack **stack, int flag);
void				func_ss(t_stack **stack_a, t_stack **stack_b, int flag);
void				func_push(t_stack **stack_from, t_stack **stack_to,
						int flag);
void				func_rotate(t_stack **stack, int flag);
void				func_rev_rotate(t_stack **stack, int flag);
void				func_rr(t_stack **stack_a, t_stack **stack_b, int flag);
void				func_rrr(t_stack **stack_a, t_stack **stack_b, int flag);
/*========== sort Stack ==========*/
void				ft_push_swap(t_stack **stack_a, t_stack **stack_b);
void				sort_3(t_stack **stack_a);
void				sort_5(t_stack **stack_a, t_stack **stack_b,
						int flag);
void				ft_get_indexes(t_stack **stack);
t_stack				*ft_min_num(t_stack **stack);
int					ft_min_num_pos(t_stack **stack);
int					n_chunks(int size);
int					highest_index(t_stack *stack);
int					pos_finder(t_stack **stack, int pos);
/*============== BONUS =============*/
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *s, char c);
char				*ft_read_lines(int fd, char *get_line);
char				*ft_lines(char *read_lines);
char				*ft_new_lines(char *read_lines);
char				*get_next_line(int fd);
int					ft_strcmp(char *s1, char *s2);
void				exec_instructions(char *line, t_stack **stack_a,
						t_stack **stack_b);
void				read_in(t_stack **stack_a, t_stack **stack_b);
void				check_if_sorted(t_stack *stack_a);
int					five_four(t_stack **stack_a);

#endif
