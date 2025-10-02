/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_id_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/09/30 16:46:19 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:46:20 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_id_list(t_id_list *id_list)
{
	if (!id_list)
		return ;
	free(id_list->id);
	id_list->id = NULL;
	free(id_list->data_value);
	id_list->data_value = NULL;
}
