/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:24:38 by lmells            #+#    #+#             */
/*   Updated: 2024/03/19 14:06:10 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "err_msgs.h"
# include "keys.h"
# include "../srcs/shared/ft_printf/includes/ft_printf.h"

# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080
# define MENU_W 250
# define BUFFER_SIZE 1000

/*	** DEFAULT COLOURS **  */
# define BG 0x282828
# define MENU_BG 0x222222
# define TEXT 0xFFFFFF

typedef struct s_stack
{
	int				z;
	int				colour;
	struct s_stack	*next;
}					t_stack;

typedef struct s_hook
{
	int				key_press;
	void			(*function)();
	struct s_hook	*next;
}					t_hook;

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

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pix;
	int				vec_len;
	int				endian;
}					t_img;

typedef struct s_math
{
	double			sin_x;
	double			sin_y;
	double			cos_x;
	double			cos_y;
}					t_math;

typedef struct s_camera
{
	double			off_x;
	double			off_y;
	double			rot_x;
	double			rot_y;
	double			rot_z;
	double			flat;
	double			iso;
	double			zoom;
	t_math			math;
}					t_camera;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_hook			*events;
	t_img			img;
	t_camera		camera;
}					t_fdf;

typedef struct s_argb
{
	int				a;
	int				r;
	int				g;
	int				b;
}					t_argb;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	t_argb			colour;
}					t_point;

/*	Length of line.
 *	Direction of line.
 */
typedef struct s_vector
{
	t_point			delta;
	t_point			sign;
}					t_vector;

/*	** Init Functons **  */
bool		init(char *file, t_map *map, t_fdf *fdf);
t_img		create_new_image(void *mlx);
t_camera	new_camera(t_map *map);
/*	** Projection Functon **  */
void		rotate_3d(t_point *p, t_fdf *fdf);
t_point		project(t_point p, t_fdf *fdf);
/*	** Render Functions **  */
void		render_fdf(t_fdf *fdf);
void		print_menu_text(t_fdf *fdf);
/*	** Point Functions **  */
t_point		get_sign(t_point *s, t_point *f);
t_point		get_absolute(t_point *s, t_point *f);
t_point		set_point(int x, int y, t_fdf *fdf);
/*	** Colour Functions **  */
int			argb_to_int(t_argb argb);
int			set_colour(t_point curr, t_point s, t_point f, t_point delta);
void		put_pixel(t_img *img, t_point v, int colour);
t_argb		int_to_argb(int colour);
t_argb		set_default_colour_scheme(t_map *map, int *z);
/*	** Map Functions **  */
bool		parse_map(t_map *map, t_stack **data);
char		*read_map_file(int fd);
/*	** Event Functions **  */
void		update_rot(int key_press, t_fdf *fdf);
void		update_zoom(int key_press, t_fdf *fdf);
void		pan_movement(int key_press, t_fdf *fdf);
void		reset_default(int key_press, t_fdf *fdf);
void		change_projection(int key_press, t_fdf *fdf);
/*	** Stack Functions **  */
bool		save_to_stack(char **values, t_stack **data);
void		free_stack(t_stack **stack);
void		stack_to_arrays(t_stack *data, t_map **map);
/*	** Hook Functions **  */
int			x_close_win(void *param);
int			key_handler(int key_press, void *param);
void		load_event_hooks(t_fdf *fdf);
/*	** Close Functions **  */
void		destroy(int key_press, void *param);
void		terminate(char *message, short error);
/*	** Error Functions **  */
bool		valid_int(int nb);
bool		check_file(char *file_name);
char		*gen_error_msg(char *s1, char *s2);
/*	** Math Functions **  */
double		calc_percentage(int s, int f, int c);
double		degrees_to_radian(double degrees);
/*	** Utility Functions **  */
int			max_val(int x, int y);
int			set_bg_colour(int index);
/*	** Debug Functions **  */
void		check_hooks(t_hook *list);
void		print_array(int *array, t_map *map);
void		print_stack(t_stack *stack, t_map *map);

#endif
