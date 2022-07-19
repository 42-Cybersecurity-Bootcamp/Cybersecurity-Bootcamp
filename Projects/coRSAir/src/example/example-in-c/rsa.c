/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:24:47 by ciclo             #+#    #+#             */
/*   Updated: 2022/07/18 15:07:07 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program for RSA asymmetric cryptographic
// algorithm. For demonstration values are
// relatively small compared to practical
// application
#include <math.h>
#include <stdio.h>

// Returns gcd of a and h
int	gcd(int a, int h)
{
	int	temp;

	while (1)
	{
		temp = a % h; //
		if (temp == 0)
			return (h);
		a = h;
		h = temp;
	}
}

// Code to demonstrate RSA algorithm
int	main(void)
{
	double	p;
	double	q;
	double	n;
	double	e;
	double	phi;
	double	d;
	double	msg;
	double	c;
	double	m;

	// Two random prime numbers
	p = 3;
	q = 7;
	// First part of public key:
	n = p * q;
	// Finding other part of public key.
	// e stands for encrypt
	e = 2;
	phi = (p - 1) * (q - 1);
	while (e < phi)
	{
		// e must be co-prime to phi and
		// smaller than phi.
		if (gcd(e, phi) == 1)
			break ;
		else
			e++;
	}
	// Private key (d stands for decrypt)
	// choosing d such that it satisfies
	// d*e = 1 + k * totient
	int k = 2; // A constant value
	d = (1 + (k * phi)) / e;
	// Message to be encrypted
	msg = 20;
	printf("Message data = %lf", msg);
	// Encryption c = (msg ^ e) % n
	c = pow(msg, e);
	c = fmod(c, n);
	printf("\nEncrypted data = %lf", c);
	// Decryption m = (c ^ d) % n
	m = pow(c, d);
	m = fmod(m, n);
	printf("\nOriginal Message Sent = %lf", m);
	return (0);
}
// This code is contributed by Akash Sharan.
