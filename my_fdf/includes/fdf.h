/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:14:04 by aroberts          #+#    #+#             */
/*   Updated: 2024/03/22 17:29:03 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "./keys.h"
# include "./msgs.h"

# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080

# define BUFFER_SIZE 1000

// Colours
# define BG 0x383838

//basic stack information
typedef struct s_stack
{
	int				z;
	int				colour;
	struct s_stack	*last;
}					t_stack;

// camera information
typedef struct s_map
{
	int				width;
	int				height;
	int				z_max;
	int				z_min;
	int				z_range;
	int				*altitude;
	int				*colours;
	char			*file;
}					t_map;

// hook information
typedef struct s_hook
{
	int				key_press;
	void			(*function)();
	struct s_hook	*next;
}					t_hook;

//image information
typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
}					t_img;

//window
typedef struct s_fdf
{
	void			*win;
	void			*mlx;
	t_map			*map;
	t_hook			*events;
	t_img			img;
	//t_camera		camera;
}					t_fdf;

//colour information
typedef struct s_argb
{
	int		a;
	int		r;
	int		g;
	int		b;
}			t_argb;

//position information
typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

// init functions
bool		init(t_fdf *fdf);
t_img		create_new_image(void *mlx);
// render functions
void		draw_quad(t_img img, t_point v, t_point offset, t_argb c);
void		render_fdf(t_fdf *fdf);
// colours functions
void		pixel_put(t_img *img, t_point v, int colour);
int			argb_to_int(t_argb argb);
t_argb		int_to_argb(int colour);
t_argb		get_opposite(int colour);
// hook functions
int			key_handler(int key, void *param);
int			x_close_win(void *param);
void		load_event_hooks(t_fdf *fdf);
// runner functions
void		runner(t_img img);
// close functions
void		terminate(char *message, short error);
void		destroy(int key_press, void *param);
// error functions
char		*gen_error_msg(char *s1, char *s2);
// utility functions
//bool		check_file(char *file_name);
bool		valid_int(int nb);
// stack functions
bool		save_to_stack(char **values, t_stack **data);
void		free_stack(t_stack **stack);
void		stack_to_arrays(t_stack *data, t_map **map);
// map functions
bool		parse_map(t_map *map, t_stack **data);

#endif