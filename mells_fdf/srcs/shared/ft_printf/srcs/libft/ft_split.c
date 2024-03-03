/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:38:04 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:38:04 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Get the amount of times the string must be split to return all the words
 *	found, into seperate array pointers.
 *		Index the string until null term.
 *		If the index value is not the seperator character, we have found a new
 *		word.
 *		If the index value is at 0, increment word count.
 *		else if the previous index position is the seperator character,
 *		Increment word count.
 *		Return the amount of words found.
 */
static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (i == 0)
				count++;
			else if (s[i - 1] == c)
				count++;
		}
		i++;
	}
	return (count);
}

/*
 *	Locates the sub string using an index, Using the seprator char as the
 *	tracker.
 *		Loop through until unknown character.
 *		Move start position until its at unknown character and the previous is
 *		the seperator character. If index is of value 0, it will break the loop
 *		ready to get len of word.
 *		Check that position is not NULL term or not seperator character.
 *		Use sub-string function to return the word.
 */
static char	*get_word_from_string(const char *s, char c, int i)
{
	int	start;
	int	len;

	start = 0;
	while (s[start] != '\0' && s[start] == c)
		start++;
	while (i > 0)
	{
		start++;
		if (s[start] != c && s[start - 1] == c)
			i--;
	}
	len = 0;
	while (s[start + len] != '\0' && s[start + len] != c)
		len++;
	return (ft_substr(s, start, len));
}

/*
 *	Split string into words from the seperating character.
 *		Count how many times the string will be split. - How many words are in
 *		the string.
 *		Allocate memory for the split double array with amount of words as size.
 *		Iterate index in loop to store each word with return of function that
 *		will get the sub-string.
 *		NULL terminate the end of the double array.
 */
char	**ft_split(const char *s, char c)
{
	char	**split;
	int		words;
	int		i;

	i = 0;
	words = word_count(s, c);
	split = (char **)malloc(sizeof(char **) * (words + 1));
	if (!split)
		return (NULL);
	while (i < words)
	{
		split[i] = get_word_from_string(s, c, i);
		i++;
	}
	split[words] = NULL;
	return (split);
}
