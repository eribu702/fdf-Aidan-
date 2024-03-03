/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:48:18 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:47:41 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define FD_STDIN 1
# define FD_STDOUT 2
# define FD_STDERR 3

# define FD_EOF 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_lstsize(t_list *lst);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_append_char(char *old_arr, char byte);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(const char *s, unsigned int size, size_t len);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
char		*ft_strrchr(const char *s1, int c);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		**ft_split(const char *s, char c);
void		ft_bzero(void *s, size_t n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
size_t		ft_strlcat(char *dest, const char *src, size_t dest_size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*	** Added **  */
int			hex_atoi(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			strchr_flag(const char *str, int c, int flag);
char		*ft_strndup(char *str, int n_bytes);
char		*float_to_array(double nb, int decimal);
char		*trim_component(char *component, int c);
char		*ft_strnjoin(char *s1, char *s2, int bytes);
void		ft_free(char **ptr);
void		free_split(char **split);
void		*ft_malloc_fill(size_t count, size_t size);
long int	conv_atoli(const char *str);

#endif
