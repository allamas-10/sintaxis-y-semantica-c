# Especificación Matemática de la Biblioteca Strings (v2)

**Definiciones:**
* Σ (Sigma): Alfabeto de caracteres.
* Σ* (Sigma estrella): Todas las cadenas posibles (incluida la vacía).
* ε (Epsilon): Representa la cadena vacía.
* B: Valores lógicos {true, false}.
* N0: Números naturales con el cero {0, 1, 2, ...}.
* Z: Números enteros.
* D: Dígitos decimales {'0' al '9'}.


## 1. IsEmpty (EstáVacío)
Chequea si la cadena es nula o no tiene caracteres.
Firma: IsEmpty: Σ* -> B

IsEmpty(s) = 
  * true, si s = ε o s es NULL
  * false, en caso contrario



## 2. GetLength (Obtener longitud)
Cuenta los caracteres de la cadena de forma recursiva.
Firma: GetLength: Σ* -> N0

GetLength(s) = 
  * 0, si s = ε
  * 1 + GetLength(t), si s = h.t (h es el primer caracter y t el resto)



## 3. AreEqual (Son iguales)
Compara dos cadenas recursivamente para ver si son idénticas.
Firma: AreEqual: Σ* x Σ* -> B

AreEqual(s1, s2) = 
  * true, si s1 = ε y s2 = ε
  * AreEqual(t1, t2), si los primeros caracteres h1 y h2 son iguales
  * false, si los caracteres actuales son distintos


## 4. AreDecimalDigits (Son dígitos)
Verifica que todos los caracteres de la cadena pertenezcan al conjunto D.
Firma: AreDecimalDigits: Σ* -> B

AreDecimalDigits(s) = 
  * false, si s = ε
  * true, si todos los caracteres h de s pertenecen a D
  * false, si algún caracter no pertenece a D



## 5. Contains (Contiene)
Busca si un caracter 'c' vive adentro de la cadena 's'.
Firma: Contains: Σ* x Σ -> B

Contains(s, c) = 
  * true, si el caracter actual h = c
  * false, si llegamos al final (s = ε) sin encontrarlo
  * Contains(t, c), si todavía no lo encontramos pero queda cadena



## 6. ToInteger (Convertir a entero)
Transforma la cadena de texto en su valor numérico real.
Firma: ToInteger: Σ* -> Z

ToInteger(s) = Valor numérico de los caracteres sumados según su posición decimal. Devuelve 0 si la cadena no es numérica o está vacía.


## 7. Concatenate (Concatenar)
Une la cadena 'fuente' al final de la cadena 'destino'.
Firma: Concatenate: Σ* x Σ* -> Σ*



## 8. Power (Potencia)
Repite la cadena 's' un número 'n' de veces sobre sí misma.
Firma: Power: Σ* x N0 -> Σ*



## 9. Reverse (Invertir)
Da vuelta el orden de los caracteres de la cadena original.
Firma: Reverse: Σ* -> Σ*