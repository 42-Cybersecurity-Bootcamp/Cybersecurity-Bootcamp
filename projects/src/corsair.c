/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corsair.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:52:02 by dugonzal          #+#    #+#             */
/*   Updated: 2022/07/20 21:19:02 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corsair.h"

/*/
Construya la clave privada a partir de dos primos y su producto (módulo)
y esa es la clave privada(clave cifrada).


*/
void	ft_generate_keys(void)
{
	system ("openssl genrsa -out private.key 2048"); //Genera la clave privada
	system ("openssl rsa -in private.key -pubout -out public.key "); //-pubout para generar la clave pública
	system ("mv private.key public.key keys"); //mover claves a carpeta keys
}

int	main(void)
{
	ft_generate_keys();
	return (0);
}
