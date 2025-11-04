/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:53:50 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/04 15:14:16 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include "get_next_line.h"
#include "ft_printf.h"

void    *ft_memset(void *s, int c, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
void   *ft_memchr(const void *s, int c, size_t n);
void    *ft_calloc(size_t count, size_t size);
void    ft_striteri(char *s, void (*f)(unsigned int,  char*));
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
int     ft_isdigit(int c);
int     ft_isalpha(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
int     ft_strncmp(char *s1, char *s2, unsigned int n);
int     ft_atoi(const char *str);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
char    *ft_strnstr(const char *haystack, const char *needle, size_t n);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
size_t  ft_strlcat(char *dest, const char *src, size_t size);
size_t  ft_strlen(const char *str);

// ---------- ft_printf ----------
int     ft_printf(const char *format, ...);
int     ft_putchar(char c);
int     ft_putstr(const char *str);
int     ft_putnbr(int n);
int     ft_putnbr_unsigned(unsigned int n);
int     ft_putnbr_hex_uppercase(unsigned int n);
int     ft_putnbr_hex_lowercase(unsigned int n);
int     ft_putnbr_hex_memory(unsigned long long n);
int     ft_putptr(void *ptr);
int     ft_handle_conversion(const char *format, int i, va_list *ap);

// ---------- get_next_line ----------
char	*get_next_line(int fd);

typedef struct   s_list
{
    void        *content;
    struct s_list   *next;
}                   t_list;

int    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstdelone(t_list *lst, void (*del)(void *));
void    ft_lstclear(t_list **lst, void (*del)(void *));
void    ft_lstiter(t_list *lst, void (*f)(void *));
void    ft_lstadd_front(t_list **lst, t_list *new);
int     ft_lstsize(t_list *lst);
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list  *ft_lstlast(t_list *lst);
t_list  *ft_lstnew(void *content);

#endif
