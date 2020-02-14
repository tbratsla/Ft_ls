/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:16:47 by tbratsla          #+#    #+#             */
/*   Updated: 2019/01/07 15:16:47 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define ADDP(a, b) {b = a; a = ft_strpjoin(b, "0", 2); free(b);}
# define ADD(a, b) {b = a; a = ft_strjoin("0", b); free(b);}
# define CHECKFOR(a) if (!a) return (0);
# define IFNOT(a, b) if (!a) {va_end(b); return (0);}
# define TOZERO(a, b, c) a = 0; b = 0; c = 0;
# define IFNEG(a, b, c) if (a) {b[c] = '-'; c++;}
# define ADDONE(a, b, c) {b = a; a = ft_strjoin("1", b); free(b); (*c)++;}
# define ADDPONE(a, b, c) {b = a; a = ft_strpjoin(b, "1", 1); free(b); (*c)++;}
# define ADDSTR(a, b, c) {a = ft_atoi(b); b[--(*c)] = a % 10 + 49; (*c)++;}
# define ABCD(a, b, c, d) {a = *b; c = handle_else(&a, c, &d); *b = a;}
# define ABCDE(a, b, c, d) {c[*b] = '0'; a = *b; c = d; *b = a;}
# define INI(a, b, c) a[3] = b; a[1] = 0; c *= 10; a[0] = 0;
# define CON(a, b) {a[(*b)++] = '0'; continue ;}
# define ADDSP(a, b) {b = *a; *a = ft_strjoin(b, " "); free(b);}
# define DUP(a, b) if (a[0] == '0') {b = ft_strdup(&a[1]); free(a); return(b);}
# define RET(a, b, c) {(*a) -= b[1]; if (c) return (c); else return (NULL);}
# define IFF(a, b, c) {a[b[1]] = ft_strnew(b[2] - b[0] + 1); c; b[1]++; break ;}
# define ELIF(a, b, c, d) a += b; c++; d--;
# define MIO(a, b, c) a; b *= -1; c *= -1;

typedef	struct	s_split
{
	int			i;
	int			j;
	int			chr;
}				t_split;

int				ft_printf(const char *format, ...);
int				ft_count_amount(const char *format);
char			**ft_make_pos(const char *format, int *amount);
int				ft_print(const char *format, va_list args, char **pos);
void			free_pos(char **pos, int amount);
int				ft_create_str(va_list args, char *pos);
int				ft_print_c(va_list args, char *pos);
int				ft_print_s(va_list args, char *pos);
void			ft_while_to_s(int len, char *s);
int				ft_check_flags(char *pos, char **s, long long d);
int				ft_check_zero(char *pos);
int				ft_print_d(va_list args, char *pos);
int				ft_print_hd(va_list args, char *pos);
char			*ft_strpjoin(char const *s1, char const *s2, int p);
int				ft_check_digit(char *pos);
char			*ft_str_with_zero(char *pos, char **s, long long d);
char			*ft_str_with_digits(char *pos, char **s);
char			*ft_check_minus(char *pos, char **s, int i);
char			*ft_check_plus(char *pos, char **s, long long d);
char			*ft_check_dot(char *pos, char **s, long long d);
char			*ft_check_dot(char *pos, char **s, long long d);
char			*ft_long_itoa(long long n);
int				ft_print_hhd(va_list args, char *pos);
int				ft_print_id(va_list args, char *pos);
int				ft_print_ld(va_list args, char *pos);
int				ft_print_lld(va_list args, char *pos);
int				ft_print_hhd(va_list args, char *pos);
int				ft_print_u(va_list args, char *pos);
int				ft_print_hu(va_list args, char *pos);
int				ft_print_hhu(va_list args, char *pos);
int				ft_print_lu(va_list args, char *pos);
int				ft_print_llu(va_list args, char *pos);
int				ft_print_iu(va_list args, char *pos);
char			*ft_unsigned_long_itoa(unsigned long long n);
int				ft_check_uflags(char *pos, char **s);
char			*ft_check_udot(char *pos, char **s);
int				ft_check_uzero(char *pos);
int				ft_check_udigit(char *pos);
char			*ft_str_with_uzero(char *pos, char **s);
char			*ft_str_with_udigits(char *pos, char **s);
char			*ft_check_uminus(char *pos, char **s, int i);
char			*ft_check_uplus(char *pos, char **s);
size_t			ft_ugenlenn(unsigned long long n);
size_t			ft_llgenlenn(long long n);
int				ft_check_oflags(char *pos, char **s);
char			*ft_check_odot(char *pos, char **s);
int				ft_check_ozero(char *pos);
int				ft_check_odigit(char *pos);
char			*ft_str_with_ozero(char *pos, char **s);
char			*ft_str_with_odigits(char *pos, char **s);
char			*ft_check_ominus(char *pos, char **s, int i);
char			*ft_check_oplus(char *pos, char **s);
char			*ft_str_with_ogrid(char *pos, char **s);
char			*ft_itoa_base(unsigned long long value, int base);
int				ft_print_o(va_list args, char *pos);
int				ft_print_ho(va_list args, char *pos);
int				ft_print_hho(va_list args, char *pos);
int				ft_print_lo(va_list args, char *pos);
int				ft_print_llo(va_list args, char *pos);
int				ft_print_io(va_list args, char *pos);
int				ft_check_xflags(char *pos, char **s);
char			*ft_check_xdot(char *pos, char **s);
int				ft_check_xzero(char *pos);
int				ft_check_xdigit(char *pos);
int				ft_print_x(va_list args, char *pos);
int				ft_print_hx(va_list args, char *pos);
int				ft_print_hhx(va_list args, char *pos);
int				ft_print_lx(va_list args, char *pos);
int				ft_print_llx(va_list args, char *pos);
int				ft_print_ix(va_list args, char *pos);
char			*ft_str_with_xzero(char *pos, char **s);
char			*ft_str_with_xdigits(char *pos, char **s);
char			*ft_check_xminus(char *pos, char **s, int i);
char			*ft_check_xplus(char *pos, char **s);
char			*ft_str_with_xgrid(char *pos, char **s);
char			*ft_strup(char *s);
char			*ft_check_sdot(char *pos, char *s);
char			*ft_strdown(char *s);
int				ft_print_p(va_list args, char *pos);
char			*ft_strrev(char *str);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_isalpha(int c);
char			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlen(const char *str);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
void			*ft_memalloc(size_t size);
char			*ft_itoa(int n);
size_t			ft_genlenn(int n);
int				ft_check(unsigned long long res, int sign);
char			*ft_strdup(const char *s1);
int				ft_print_f(va_list args, char *pos);
int				ft_print_llf(va_list args, int prec, char **pos);
int				ft_print_lf(va_list args, int prec, char **pos);
int				ft_print_if(va_list args, int prec, char **pos);
long double		ft_calc_modulo(long double nb, int *size);
void			ft_handle_integer(long double *nb, char **str,\
							int *i, long double modulo);
char			*ft_handle_decimals(char *str, int *i, long double nb,\
							int precision);
int				ft_handle_inf(char **s, long double nb);
int				ft_put_float_to_string(long double nb,\
				int precision, char **pos);
char			*ft_check_fflags(char **s, int neg, char **pos);
char			*ft_str_with_fzero(char *pos, char **s, int neg);
char			*ft_str_with_fdigits(char *pos, char **s);
char			*ft_check_fminus(char *pos, char **s, int i);
char			*ft_check_fplus(char *pos, char **s, int neg);
char			*ft_str_with_fgrid(char *pos, char **s);
int				ft_print_per(char *pos);
char			*ft_str_with_perzero(char *pos, char **s);
char			*ft_str_with_perdigits(char *pos, char **s);
char			*ft_check_perminus(char *pos, char **s, int i);
char			*ft_str_with_czero(char *pos, char **s);
char			*ft_str_with_cdigits(char *pos, char **s, int j);
char			*ft_check_cminus(char *pos, char **s, int i);
void			ft_make_pos_two(const char **format,\
				int *a, int *j, char ***pos);
void			ft_str_xzero_help(char **pos, int *prec, char ***s);
char			*handle_else(int *i, char *str, int *number);
char			*handle_else_two(int *i, char *str, int *number);
char			*handle_if(int j[4], char *str, long int *i, long double nb);
void			ifj(int *len, char **pos, char **s, int j);
char			*ft_check_pdot(char *pos, char *s, long long d);
char			*ft_str_with_pdigits(char *pos, char *s);
char			*ft_check_pminus(char *pos, char *s, int i);
#endif
