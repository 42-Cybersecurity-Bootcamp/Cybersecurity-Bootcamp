/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corsair.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:52:02 by dugonzal          #+#    #+#             */
/*   Updated: 2022/07/17 12:20:39 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corsair.h"

/*/
Construya la clave privada a partir de dos primos y su producto (módulo)
y esa es la clave privada(clave cifrada).

Implementación propia de una librería o conjunto de funciones en C para operar
con enteros de gran tamaño.

tengo que abrir un archivo y guardar la clave generada en un archivo.

cuestion: ¿Qué es una clave privada?

operacion de obtencion de dos primos y su producto (módulo)

	esta haciendo una funcion que recibe como parametro dos numeros primos done


	// Encuentra el máximo común divisor entre dos números??

	porque necesito encotrar el maximo comun divisor entre los numeros primos?
	esta funncion es recursiva, es decir que llama a si misma hasta que se obtenga

	while(num2 > 0) // porque num2 > 0 // por decir algo.
    {
      temp = num1 % num2; //porqu
      num1 = num2;
      num2 = temp;
    }


step 0. antes de leer la clave publica tenemos que generar una clave publica
*/

int	main(void)
{
	int	fd;

	fd = open ("keys/key_public.txt", O_WRONLY); // lectura de la clave publica
	printf ("%d\n", fd);
	close (fd);
}
