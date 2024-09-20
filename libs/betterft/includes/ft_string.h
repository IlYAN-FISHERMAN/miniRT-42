/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:36:32 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 19:00:26 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

// includes
# include "betterft_includes.h"
# include "ft_garbage_collector.h"
# include "ft_memory.h"

//	ft_strchr: Returns a pointer to the first occurrence of the character 'c'
//	in the string 's'.
//	@param 's': The string to search in.
//	@param 'c': The character to search for.
//	@return The pointer to the first occurrence of 'c' in 's' or NULL if 'c'
char		*ft_strchr(const char *s, int c);

//	ft_strrchr: Returns a pointer to the last occurrence of the character 'c'
//	in the string 's'.
//	@param 's': The string to search in.
//	@param 'c': The character to search for.
//	@return The pointer to the last occurrence of 'c' in 's' or NULL if 'c'
char		*ft_strrchr(const char *s, int c);

//	ft_strcmp: Compares the two strings 's1' and 's2'.
//	@param 's1': The first string to compare.
//	@param 's2': The second string to compare.
//	@return An integer less than, equal to, or greater than zero if 's1' is
int			ft_strcmp(const char *s1, const char *s2);

//	ft_strncmp: Compares the two strings 's1' and 's2' up to 'n' characters.
//	@param 's1': The first string to compare.
//	@param 's2': The second string to compare.
//	@param 'n': The maximum number of characters to compare.
//	@return An integer less than, equal to, or greater than zero if 's1' is
int			ft_strncmp(const char *s1, const char *s2, size_t n);

//	ft_strdup: Duplicates the string 'src'.
//	@param 'src': The string to duplicate.
//	@return A pointer to the newly allocated string or NULL if the allocation
char		*ft_strdup(const char *src);

//	ft_striteri: Applies the function 'f' to each character of the string 's'
//	passing its index as first argument.
//	@param 's': The string to iterate.
//	@param 'f': The function to apply to each character.
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

//	ft_strsepjoin: Joins the strings in the array 'arr' with the separator
//	'sep'.
//	@param 'arr': The array of strings to join.
//	@param 'sep': The separator to use.
//	@return The resulting string.
char		*ft_strsepjoin(char **arr, char sep);

//	ft_strjoin: Allocates and returns a new string, which is the result of the
//	concatenation of 's1' and 's2'.
//	@param 's1': The prefix string.
//	@param 's2': The suffix string.
//	@return The new string or NULL if the allocation fails.
char		*ft_strjoin(const char *s1, const char *s2);

//	ft_strsjoin: Allocates and returns a new string, which is the result of the
//	concatenation of 'size' strings.
//	@param 'size': The number of strings to concatenate.
//	@param '...': The strings to concatenate.
//	@return The new string or NULL if the allocation fails.
char		*ft_strsjoin(size_t size, ...);

//	ft_strlcat: Appends the string 'src' to the end of 'dst'.
//	It will append at most 'dstsize' - strlen(dst) - 1 characters.
//	It will then NUL-terminate, unless 'dstsize' is 0 or the original 'dst'
//	string was longer than 'dstsize'.
//	@param 'dst': The destination string.
//	@param 'src': The source string.
//	@param 'dstsize': The size of the destination buffer.
//	@return The total length of the string it tried to create.
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

//	ft_strlcpy: Copies up to 'size' characters from the NUL-terminated string
//	'src' to 'dst', NUL-terminating the result.
//	@param 'dst': The destination string.
//	@param 'src': The source string.
//	@param 'size': The size of the destination buffer.
//	@return The total length of the string it tried to create.
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

//	ft_strlen: Computes the length of the string 'str'.
//	@param 'str': The string to compute the length of.
//	@return The length of the string.
size_t		ft_strlen(const char *str);

//	ft_strmapi: Applies the function 'f' to each character of the string 's'
//	passing its index as first argument to create a new string.
//	@param 's': The string to iterate.
//	@param 'f': The function to apply to each character.
//	@return The new string or NULL if the allocation fails.
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//	ft_strncat: Appends the string 'src' to the end of 'dest'.
//	It will append at most 'nb' characters.
//	@param 'dest': The destination string.
//	@param 'src': The source string.
//	@param 'nb': The maximum number of characters to append.
//	@return The destination string.
char		*ft_strncat(char *dest, const char *src, size_t nb);

//	ft_strnstr: Locates the first occurrence of the null-terminated string
//	'needle' in the string 'haystack', where not more than 'len' characters
//	are searched.
//	@param 'haystack': The string to search in.
//	@param 'needle': The string to search for.
//	@param 'len': The maximum number of characters to search.
//	@return A pointer to the first occurrence of 'needle' in 'haystack' or NULL
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

//	ft_strreplace: Replaces all occurrences of 'old' in 'src' with 'new'.
//	@param 'src': The string to search in.
//	@param 'old': The string to search for.
//	@param 'new': The string to replace with.
//	@return The new string or NULL if the allocation fails.
char		*ft_strreplace(char *src, char *old, char *new);

//	ft_strreplace_first: Replaces the first occurrence of 'old' in 'src' with
//	'new'.
//	@param 'src': The string to search in.
//	@param 'old': The string to search for.
//	@param 'new': The string to replace with.
//	@return The new string or NULL if the allocation fails.
char		*ft_strreplace_first(char *src, char *old, char *new);

//	ft_strstr: Locates the first occurrence of the null-terminated string
//	'needle' in the string 'haystack'.
//	@param 'haystack': The string to search in.
//	@param 'needle': The string to search for.
//	@return A pointer to the first occurrence of 'needle' in 'haystack' or NULL
char		*ft_strstr(const char *haystack, const char *needle);

//	ft_strtrim: Allocates and returns a copy of 's1' with the characters
//	specified in 'set' removed from the beginning and the end of the string.
//	@param 's1': The string to trim.
//	@param 'set': The set of characters to trim.
//	@return The trimmed string or NULL if the allocation fails.
char		*ft_strtrim(const char *s1, const char *set);

//	ft_substr: Allocates and returns a substring from the string 's'.
//	The substring begins at index 'start' and is of maximum size 'len'.
//	@param 's': The string to create the substring from.
//	@param 'start': The start index of the substring.
//	@param 'len': The maximum length of the substring.
//	@return The substring or NULL if the allocation fails.
char		*ft_substr(char const *s, unsigned int start, size_t len);

//	ft_tablen: Computes the length of the null-terminated array of strings
//	'tab'.
//	@param 'tab': The array of strings to compute the length of.
//	@return The length of the array.
size_t		ft_tablen(char **tab);

//	ft_tabadd: Adds the string 'str' to the null-terminated array of strings
//	'tab'.
//	@param 'tab': The array of strings to add to.
//	@param 'str': The string to add.
//	@return The new array or NULL if the allocation fails.
char		**ft_tabadd(char **tab, char *str);

//	ft_tabjoin: Joins the strings in the null-terminated array 'array' into a
//	new dynamically allocated string.
//	@param 'array': The array of strings to join.
//	@return The resulting string or NULL if the allocation fails.
char		*ft_tabjoin(char **array);

//	ft_tolower: Converts the character 'c' to lowercase.
//	@param 'c': The character to convert.
//	@return The lowercase character.
int			ft_tolower(int c);

//	ft_toupper: Converts the character 'c' to uppercase.
//	@param 'c': The character to convert.
//	@return The uppercase character.
int			ft_toupper(int c);

//	ft_countwords: Counts the number of words in the string 's' separated by the
//	character 'c'.
//	@param 's': The string to count the words in.
//	@param 'c': The character to separate the words.
//	@return The number of words.
size_t		ft_countwords(char const *s, char c);

//	ft_split: Allocates and returns an array of strings obtained by splitting
//	's' using the character 'c' as a delimiter.
//	The array must be ended by a NULL pointer.
//	@param 's': The string to split.
//	@param 'c': The delimiter character.
//	@return The array of new strings or NULL if the allocation fails.
char		**ft_split(char const *s, char c);

//	ft_joint_all: Concatenates all strings in the null-terminated array 'str'
//	into a new dynamically allocated string.
//	@param 'str': The array of strings to concatenate.
//	@return The resulting string or NULL if the allocation fails.
char		*ft_joint_all(char **str);

//	ft_free_tab: Frees the memory allocated for a null-terminated array of
//	strings. Each string in the array must have been allocated dynamically.
//	@param 'tab': The array of strings to free.
//	@return 0 if the memory was freed successfully, 1 otherwise.
int			ft_free_tab(char **tab);

//	ft_isalnum: Checks if the character 'c' is alphanumeric.
//	@param 'c': The character to check.
//	@return 1 if 'c' is alphanumeric, 0 otherwise.
int			ft_isalnum(int c);

//	ft_isalpha: Checks if the character 'c' is alphabetic.
//	@param 'c': The character to check.
//	@return 1 if 'c' is alphabetic, 0 otherwise.
int			ft_isalpha(int c);

//	ft_isascii: Checks if the character 'c' is a 7-bit unsigned char value that
//	fits into the ASCII character set.
//	@param 'c': The character to check.
//	@return 1 if 'c' is an ASCII character, 0 otherwise.
int			ft_isascii(int c);

//	ft_isdigit: Checks if the character 'c' is a digit.
//	@param 'c': The character to check.
//	@return 1 if 'c' is a digit, 0 otherwise.
int			ft_isdigit(int c);

//	ft_isprint: Checks if the character 'c' is a printable character.
//	@param 'c': The character to check.
//	@return 1 if 'c' is a printable character, 0 otherwise.
int			ft_isprint(int c);

//	ft_isspace: Checks if the character 'c' is a white-space character.
//	@param 'c': The character to check.
//	@return 1 if 'c' is a white-space character, 0 otherwise.
int			ft_isspace(char c);

//	ft_atoi: Converts the initial portion of the string 'str' to an integer.
//	@param 'str': The string to convert.
//	@return The converted integer.
int			ft_atoi(const char *str);

//	ft_atoi_base: Converts the initial portion of the string 'str' to an integer
//	using the base 'base'.
//	@param 'str': The string to convert.
//	@param 'base': The base to use.
//	@return The converted integer.
int			ft_atoi_base(const char *str, const char *base);

//	ft_itoa_base_un: Converts the unsigned long integer 'n' to a string
//	representing the number in the base 'base'.
//	@param 'n': The number to convert.
//	@param 'base': The base to use.
//	@return The new string or NULL if the allocation fails.
char		*ft_itoa_base_un(unsigned long n, const char *base);

//	ft_itoa_un: Converts the unsigned long integer 'n' to a string.
//	@param 'n': The number to convert.
//	@return The new string or NULL if the allocation fails.
char		*ft_itoa_un(unsigned long n);

//	ft_itoa_base: Converts the integer 'n' to a string representing the number
//	in the base 'base'.
//	@param 'n': The number to convert.
//	@param 'base': The base to use.
//	@return The new string or NULL if the allocation fails.
char		*ft_itoa_base(int n, const char *base);

//	ft_itoa: Converts the integer 'n' to a string.
//	@param 'n': The number to convert.
//	@return The new string or NULL if the allocation fails.
char		*ft_itoa(int n);

#endif