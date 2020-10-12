/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:34:17 by roddavid          #+#    #+#             */
/*   Updated: 2018/02/06 14:08:21 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putendl(const char *s);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(const char *str);
void			ft_putstr_fd(const char *s, int fd);
void			ft_strclr(char *str);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_sqrt(int nb);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_itoa(int nb);
char			*ft_strtrim(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoinfree(const char *s1, const char *s2, int index);
char			*ft_strcut_free(char *s1, char c);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strsub_free(const char *s, unsigned int start, size_t len);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strdup(const char *src);
char			*ft_strdup_free(const char *src);
char			*ft_strcdup(const char *src, char c);
char			*ft_strfdup(const char *src, char c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *hay, const char *needl);
char			*ft_strnstr(const char *hay, const char *needl, size_t len);
char			**ft_strsplit(const char *s, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *d, const void *s, int c, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_bzero(void *b, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
struct s_list	*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t			ft_int_len(int nb);
int				ft_word(const char *s, char c);
size_t			ft_len(const char *s, char c, unsigned int start);
unsigned int	ft_start(const char *s, char c, int i);
void			ft_swap(int *a, int *b);
int				ft_islower(int c);
int				ft_isupper(int c);

#endif
