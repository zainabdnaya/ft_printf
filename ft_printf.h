/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:36:25 by zdnaya            #+#    #+#             */
/*   Updated: 2020/01/18 11:19:25 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>
# include <inttypes.h>

typedef struct		s_print
{
	va_list			ap;
	char			*format;
	int				n;
	int				l;
	char			z;
	int				j;
	char			type;
	char			*frt;
	int				r;
	int				size;
	int				d;
	char			*s;
	int				ud;
	char			chr;
	long			o;
	char			*srt;
	int				oldindex;
	char			*strg;
	int				k;
	int				a;
	int				q;
	int				m;
	int				kl;
	int				etoile;

}					t_print;

void				null_dprint(t_print *str, int w, int p, int j);
void				ft_precesion_d1(t_print *str, int w, int p, int k);
void				ft_precesion_d2(t_print *str, int w, int p, int k);
void				print_dd(t_print *str, int w, int p, int k);
void				ft_flags_d(t_print *str);
void				pres_002(t_print *str, int k);
void				pres_001(t_print *str, int p, int w, int k);
void				print_01d(t_print *str, int k, int p, int w);
void				pret(t_print *str, int k, int w, int p);
void				ft_flags_pointer(t_print *str);
void				ft_null(t_print *str, int w, int p);
void				ft_null1(t_print *str, int w);
void				ft_precesion_p1(t_print *str, int w, int p, char *srt);
void				ft_precesion_p2(t_print *str, int w, int p, char *srt);
void				null_uprint_next1(t_print *str, int w, int p);
void				print_space(t_print *str, int size, int b);
void				print_nge(int *k);
void				ft_zero_print(t_print *str, int w, int p, int k);
void				ft_zero_print0(t_print *str, int w, int l, int size);
void				ft_zero_print1(t_print *str, int w, int p, int k);
void				ft_flags_string(t_print *str);
void				flag_condtion(t_print *str, int w, int p, char *string);
void				strpositive_width(t_print *str, int w, int p, char *string);
void				strpositive_width1 (t_print *str, int w,
							int p, char *string);
void				strnegative(t_print *str, int w, int p, char *string);
void				zeronegative(t_print *str, int w, int p, char *string);
void				ft_precesion_h4(t_print *str, int w, int p, char *string);
void				nextstrneg(t_print *str, int w, int p, char *string);
void				strnegative_presi(t_print *str, int w, int p, char *string);
void				check_type(t_print *str);
void				ft_printtype(t_print *str, char c);
void				ft_checknext(t_print *str);
void				zapper_zero(char *str, int *i, int *sign);
void				zeronegative_presi(t_print *str, int w
							, int p, char *string);
void				print_null(t_print *str, int w, int p, char *string);
void				ft_zero_string(t_print *str, int w, int p, char *string);
void				zeropositive_width(t_print *str, int w
							, int p, char *string);
void				zeropositive_width1(t_print *str
							, int w, int p, char *string);
void				zeronegative_width(t_print *str, int w
							, int p, char *string);
void				zeronegative_width1(t_print *str, int p, char *string);
void				strsize(t_print *str, int w, int p, char *string);
void				strsize0(t_print *str, int w, int p, char *string);
void				strsize1(t_print *str, int w, int p, char *string);
void				strnegative_width(t_print *str, int w, int p, char *string);
void				negativestr1(t_print *str, int w, int p, char *string);
void				ft_flags_char(t_print *str);
void				ft_percentage_flag(t_print *str);
void				ft_percentage_flag1(t_print *str, int w);
void				ft_flags_unsigned(t_print *str);
void				ft_flags_unsigned1(t_print *str, int w, int p, int j);
void				ft_zero_print_u(t_print *str, int w, int p, unsigned int k);
void				null_uprint(t_print *str, int w, int p, int j);
void				null_uprint_next2(t_print *str, int w);
void				ft_uprecesion_u1(t_print *str, int w, int p);
void				ft_precesion_u2(t_print *str, int w, int p);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
void				ft_putnbr_u(unsigned int n);
void				ft_putstr_string(char *s, int p);
void				ft_flags_char(t_print *str);
void				ft_percentage_flag(t_print *str);
void				ft_percentage_flag1(t_print *str, int w);
void				hexazero_flag(t_print *str, int w, int p, int size);
void				hexazero_flag1(t_print *str, int w, int p, int size);
void				ft_precesion_h1(t_print *str, int w, int p, int j);
void				ft_precesion_h3(t_print *str, int w, int p, char *string);
void				ft_precesion_h2(t_print *str, int w, int p, int j);
void				ft_flags_hexa(t_print *str, char c);
void				ft_flags_hexa1(t_print *str, int w, int p, int j);
int					ft_printf(const char *format, ...);
int					ft_printcheck(t_print *str, char *format);
int					ft_check_number(t_print *str);
int					ft_stock_nbr(t_print *str, int j);
int					ft_search(t_print *str, int i);
int					ft_char_print(t_print *str2);
int					ft_int_print(t_print *str1);
int					ft_pointerprint(t_print *str6);
int					ft_char_print(t_print *str2);
int					ft_hexadecimal_print(t_print *str5);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					peration(const char *str, long lenght, int sign);
int					ft_atoi(const char *str);
int					ft_usignedint_print(t_print *str4);
int					ft_string_print(t_print *str3);
int					mine_strlen(char *s);
int					ft_strpoint(char *str, char c, int index);
int					ft_uintlen(unsigned int n);
char				*ft_itoa_base(unsigned value, int base, int c);
char				test_hex(int v);
char				*convert(void *p);
void				ft_ipd (t_print *str, int w, int p);
char				*ft_strchr(const char *s, int c);
char				*myalloc(char *arr, int n, int *sign);
char				*ft_itoa(int n);
char				*ft_strdup(const char *src);
size_t				ft_digit_count(long num, int base);
size_t				ft_intlen(int n);
void				ft_zero_print2(t_print *str, int w, int p, int k);
void				ft_initialization(t_print *v);
void				null_dprint1(t_print *str, int w, int p, int j);
void				ft_zero_string1(t_print *str, int w, int p, char *string);
void				zeropositive1_width1 (t_print *str, int w
								, int p, char *string);
void				ft_ipdt_print (t_print *str, int w, int p);
#endif
