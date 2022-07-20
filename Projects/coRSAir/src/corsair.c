/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corsair.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:52:02 by dugonzal          #+#    #+#             */
/*   Updated: 2022/07/20 20:02:24 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corsair.h"

/*/
Construya la clave privada a partir de dos primos y su producto (módulo)
y esa es la clave privada(clave cifrada).
/*/

void	ft_generate_keys(void)
{
	system ("openssl genrsa -out private.pem 2048");
	system ("openssl rsa -in private.pem -pubout -out public.pem ");
	system ("mv private.pem public.pem keys");
}

int	main(void)
{
	ft_generate_keys();
	return (0);
}
