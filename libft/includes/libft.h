/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:52:06 by dpetrysh          #+#    #+#             */
/*   Updated: 2017/11/08 16:52:15 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdarg.h>
# include <unistd.h>
#include <locale.h>
#include <limits.h>

# define BUFF_SIZE 1000

# define ABS(x)	((x) < 0 ? -(x) : (x))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct	s_num
{
	int		m;
	int		s;
	char	*n;
}				t_num;
typedef	struct	s_strr
{
	int		s;
	wchar_t	*n;
}				t_wstr;

typedef	struct	s_str
{
	int		s;
	char	*str;
}				t_str;

typedef struct	s_spec
{
	int			res;
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
	int			width;
	int			prec;
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			j;
	int			z;
	int			type;
	int			other;
}				t_spec;

int					ft_printf(const char *format, ...);

void				make_struct(t_spec *sp, int start);
void				main_job(void *p, t_spec *sp);
void				bring_text(char *str, t_spec *sp, int *ind);
int					detect_type(char *str);

void				add_char(char **s1, char c);
char				*str_add(char **s1, char *s2);
char				get_chardig(int n, int big);
int					get_rank(long long n, int base);
char				*ft_itoa_base(long long n, int base, int big);

int					get_rank_uns(unsigned long long n, int base);
char				*ft_itoa_base_uns(unsigned long long n, int base, int big);

void				make_sign(t_spec *sp, t_num *num);
void				make_minus(t_num *num);
void				make_plus(t_num *num);
void				make_inv_plus(t_num *num);
void				make_more_zero(t_num *num);

void				make_tnum(t_num *num);
int					make_specific(char **str, t_spec *sp);
void				make_zero(t_spec *sp, t_num *num);
void				nbr_struct(char *str, t_num *num);
void				use_prec(t_spec *sp, t_num *num);

void				make_flag(char *str, t_spec *sp);
void				make_length(char *str, t_spec *sp);
void				make_width(char *str, t_spec *sp);
void				make_precision(char *str, t_spec *sp);
void				make_type(char *str, t_spec *sp);

void				put_together(t_spec *sp, t_num *num);
void				noprec_minus_in(t_spec *sp, t_num *num);
void				noprec_minus_off(t_spec *sp, t_num *num);
void				minus_flag_in(t_spec *sp, t_num *num);
void				minus_flag_off(t_spec *sp, t_num *num);

int					is_flag(char c);
int					is_length(char c);
int					is_type(char c);
int					is_unsigned_type(char c);
int					is_known(char c);

int					get_wlen(wchar_t *str);
int					count_bytes(wchar_t c);
int					put_wchar(wchar_t c);
void				use_width_wstr(t_wstr *w, t_spec *sp);
void				precise_wstr(t_wstr *w, t_spec *sp);

void				type_c(void *p, t_spec *sp);
void				put_char_simp(t_spec *sp, t_num *num, char c);
void				put_chzero(t_spec *sp, t_num *num);
char				*ft_chardup(char c);

void				type_s(void *p, t_spec *sp);
void				put_str_simp(t_spec *sp, t_num *num);
void				precise_string(t_num *num, t_spec *sp);
void				put_wstr(t_spec *sp, wchar_t *wstr);
void				make_wstr(void *p, t_spec *sp);

void				type_d(void *p, t_spec *sp, int big);
void				type_o(void *p, t_spec *sp, int big);
void				type_u(void *p, t_spec *sp, int big);
void				type_x(void *p, t_spec *sp, int big);
void				type_p(void *p, t_spec *sp);
void				type_pers(t_spec *sp);

void				make_hash_x(void *p, t_spec *sp, t_num *num);
void				make_hash_o(t_spec *sp, t_num *num);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *lit, size_t l);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_strmap(char const *s, char (*f)(char));
void				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					ft_power(int d, int p);
int					ft_strbegin(char const *s);
int					ft_strend(char const *s);
int					ft_wordnum(char const *s, char c);
int					ft_wordlen(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					get_next_line(const int fd, char **line);
char				*ft_itoa_base(long long n, int base, int big);

#endif
