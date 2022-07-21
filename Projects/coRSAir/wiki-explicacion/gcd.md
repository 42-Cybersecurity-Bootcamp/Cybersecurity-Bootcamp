# FUNCION GCD

Devuelve el máximo común divisor de dos o más enteros. El máximo común divisor es el entero más grande que divide tanto number1 como number2 sin un resto.


# prototipo de funcion
int	FT_GCD(number1, number2)


# funcion
creamos una variable temporal tipo int, en este caso le llamamos tmp, aqui es donde vamos a guradar el modulo de number1 y number2
- tmp = number1 % number2 ¿si tmp es 0 retornamos numero dos?
- guardamos el modulo de number1 y number2 en tmp
