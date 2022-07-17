# El algoritmo consta de tres pasos: generación de claves, cifrado y descifrado

# Idea del algoritmo

Supongamos que Bob quiere enviar a Alicia un mensaje secreto que solo ella pueda leer.

Alicia envía a Bob una caja con un candado abierto, del que solo Alicia tiene la llave. Bob recibe la caja, escribe el mensaje, lo pone en la caja y la cierra con su candado (ahora Bob no puede leer el mensaje). Bob envía la caja a Alicia y ella la abre con su llave. En este ejemplo, la caja con el candado es la «clave pública» de Alicia, y la llave del candado es su «clave privada».

[img1]: ../images/rsa.png "RSA"

El algoritmo RSA es un algoritmo de criptografía asimétrica. Asimétrico en realidad significa que funciona en dos claves diferentes, es decir , clave pública y clave privada. Como el nombre describe, la clave pública se otorga a todos y la clave privada se mantiene privada.

# Un ejemplo de criptografía asimétrica:

Un cliente (por ejemplo, un navegador) envía su clave pública al servidor y solicita algunos datos.
El servidor cifra los datos utilizando la clave pública del cliente y envía los datos cifrados.
El cliente recibe estos datos y los descifra.
Dado que esto es asimétrico, nadie más, excepto el navegador, puede descifrar los datos, incluso si un tercero tiene la clave pública del navegador.

¡La idea! La idea de RSA se basa en el hecho de que es `difícil factorizar un número entero grande`. La clave pública consta de dos números donde un número es la multiplicación de dos números primos grandes. Y la clave privada también se deriva de los mismos dos números primos. Entonces, si alguien puede factorizar el gran número, la clave privada está comprometida. Por lo tanto, la fuerza del cifrado depende totalmente del tamaño de la clave y si duplicamos o triplicamos el tamaño de la clave, la fuerza del cifrado aumenta exponencialmente. Las claves RSA suelen tener una longitud de 1024 o 2048 bits, pero los expertos creen que las claves de 1024 bits podrían romperse en un futuro próximo. Pero hasta ahora parece ser una tarea inviable.
