/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:02:05 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/17 14:03:55 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void
	ft_error_exit(char *err_message, int exit_code)
{
	ft_putendl_fd("ERROR", 2);
	ft_putendl_fd(err_message, 2);
	exit(exit_code);
}
