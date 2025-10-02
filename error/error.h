/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:34:57 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:35:04 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MIN_INT_STR "2147483648"
# define MAX_INT_STR "2147483647"

void	exit_error(void);
int		is_not_numeric(const char *str);
int		is_overflow(const char *str);
int		has_duplicates(int *number, int count);
int		validate_arguments(int count, char *argv[]);
#endif
