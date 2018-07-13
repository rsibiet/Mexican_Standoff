/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:24:18 by rsibiet           #+#    #+#             */
/*   Updated: 2015/12/07 15:24:22 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	read_loop(char *delim_string, char **ptr, int op, char **doc)
{
	char	*tmp;
	char	*tmp2;

	while (**ptr)
	{
		tmp = *ptr;
		while (**ptr && **ptr != '\n')
			(*ptr)++;
		if (**ptr == '\n')
			(*ptr)++;
		tmp = ft_strndup(tmp, *ptr - tmp);
		if (op == DLESSDASH)
			tmp = remove_tab(tmp);
		if (!ft_strcmp(delim_string, tmp))
			break ;
		tmp2 = ft_strjoin(*doc, tmp);
		free(*doc);
		free(tmp);
		*doc = tmp2;
	}
}
