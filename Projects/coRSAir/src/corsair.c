/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corsair.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:52:02 by dugonzal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/17 15:10:19 by ciclo            ###   ########.fr       */
=======
/*   Updated: 2022/07/20 21:19:02 by dugonzal         ###   ########.fr       */
>>>>>>> 7c8da723ba7b454f365fc4d6fdf9b026c6ace52c
/*                                                                            */
/* ************************************************************************** */

#include "corsair.h"

/*/
Construya la clave privada a partir de dos primos y su producto (módulo)
y esa es la clave privada(clave cifrada).


<<<<<<< HEAD
tengo que abrir un archivo y guardar la clave generada en un archivo.

cuestion: ¿Qué es una clave privada?

operacion de obtencion de dos primos y su producto (módulo)

	esta haciendo una funcion que recibe como parametro dos numeros primos done


	// Encuentra el máximo común divisor entre dos números??

	porque necesito encotrar el maximo comun divisor entre los numeros primos?
	esta funncion es recursiva, es decir que llama a si misma hasta que se obtenga

*/
/*
la funcion gcd es una funcion recursiva que se llama a si misma hasta que se obtenga el maximo comun divisor

Devuelve el máximo común divisor de dos o más enteros.
El máximo común divisor es el entero más grande que divide tanto number1 como number2 sin un resto.

int	ft_gcd(int a, int h)
{
	int	temp;

	while (1)
	{
		temp = a % h;
		if (temp == 0)
			return (h);
		a = h;
		h = temp;
	}

step 0. antes de leer la clave publica tenemos que generar una clave publica
=======
>>>>>>> 7c8da723ba7b454f365fc4d6fdf9b026c6ace52c
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
