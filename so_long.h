/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khallal <khallal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:18:30 by khallal           #+#    #+#             */
/*   Updated: 2022/12/29 11:52:38 by khallal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 23
# endif

typedef struct s_p
{
	int		x;
	int		y;
}			t_p;

typedef struct s_e
{
	int		x;
	int		y;
}			t_ene;

typedef struct s_data
{
	int		coin;
	int		player;
	int		exit;
	int		n_line;
	int		lent_line;
	char	**map;
	char	**flod;
	char	**flode;
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	void	*imag;
	void	*mahdi;
	char	*path;
	t_p		k;
	int		colone;
	int		line;
	t_ene	e;
	int		step;
}			t_khalifa;

char		**ft_split(char const *s, char c);
char		**check_map(int fd, t_khalifa *f);
int			creat_map(t_khalifa *m);
int			check_map_name(char *p);
int			empty_line(char *k);
void		empty_map(char k);
int			number_line(char *k);
void		wall(t_khalifa *m, char c);
void		put_image(t_khalifa *m, int y);
void		check_arg(int a);
void		check_fd(int i);
void		key_down(t_khalifa *m);
int			key_hook(int keycode, t_khalifa *m);
void		position(t_khalifa *m);
void		key_up(t_khalifa *m);
void		key_left(t_khalifa *m);
void		key_right(t_khalifa *m);
int			coin(t_khalifa *m);
void		path(t_khalifa *m);
int			collection(t_khalifa *m);
char		*ft_itoa(int n);
void		enemy(t_khalifa *m);
void		put_img(t_khalifa *m, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(char *s);
char		*get_next_line(int fd);

#endif