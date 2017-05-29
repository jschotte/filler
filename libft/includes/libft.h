/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:27:04 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/28 10:13:17 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

# define BUFF_SIZE 192
# define FD 2147483647

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char	*dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *dest, const char *src);
char			*ft_strnstr(const char *dest, const char *src, size_t n);
int				ft_strcmp(const char *dest, const char *src);
int				ft_strncmp(const char *dest, const char *src, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memdup(const void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *dest, const void *src, size_t n);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putnbr(int n);
void			ft_putendl(char const *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_abs(int n);
char			*ft_freejoin(char *s1, char *s2);
int				get_next_line(int const fd, char **line);
int				ft_arraylen(char **s);

typedef struct	s_printf
{
	va_list		ap;
	int			i;
	int			fail;
	int			diese;
	int			moins;
	int			plus;
	int			space;
	int			zero;
	int			width;
	int			precision;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			ret;
	int			punct;
	int			size;
}				t_printf;

int				ft_printf(char *format, ...);
void			flag_diese(char *format, t_printf *env);
void			flag_moins(char *format, t_printf *env);
void			flag_plus(char *format, t_printf *env);
void			flag_space(char *format, t_printf *env);
void			flag_zero(char *format, t_printf *env);
void			flag_width(char *format, t_printf *env);
void			flag_precision(char *format, t_printf *env);
void			flag_length(char *format, t_printf *env);
void			ft_conv(char *format, t_printf *env);
void			conv_d(char *format, t_printf *env);
void			conv_c(t_printf *env, char *format);
void			conv_s(t_printf *env);
void			conv_pourcent(t_printf *env);
void			conv_u(t_printf *env, char *format);
void			conv_x(t_printf *env, char *format);
char			*ft_itoa_base_unsigned(unsigned long long value, int base);
void			conv_o(t_printf *env, char *format);
void			ft_put_zero(int k, t_printf *env);
void			ft_put_space(int k, t_printf *env);
void			ft_putnbr_u(unsigned long long value);
int				ft_putnstr(char*s, t_printf *env, int i);
void			conv_p(t_printf *env);
char			*ft_putstrl(char *s);
char			*ft_itoa_base_long(long long value, int base);
void			ft_putchar_nb(char c, int i);
void			wrong_conv(char *format, t_printf *env);
void			conv_bigc(t_printf *env);
char			**mask_unicode(char *wc);
void			ft_putwchar(char **bin);
void			conv_ws(t_printf *env, char *format);
char			*stockbis(char **bin, unsigned int size);
#endif
