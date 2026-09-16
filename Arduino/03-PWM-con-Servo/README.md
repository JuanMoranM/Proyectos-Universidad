# Proyecto PWM con Servomotor

Este proyecto sirve para comprender cómo funcionan, de manera básica, las entradas analógicas del microcontrolador Arduino y el control de motor mediante la modulación por ancho de pulso PWM. 
Se usó también en este proyecto la funcióon map() que nos sirve para hacer un mapeo de los valores obtenidos en la entrada analógica (0 - 1024) a valores manejables para hacer funcionar el motor con PWM (0 - 255).
Además se ha usado la función millis() para poder ejecutar un filtro en la señal obtenida mediante la entrada analógica, además de un filtro pasabajas implementado de manera física.

**Lista de Componentes**

- 1 Arduino UNO R3.
- 1 Potenciómetro de 1K Ohm.
- 1 Resistencia de 1K Ohm.
- 1 Condensador cerámico de 1uF.
- 1 Servomotor SG90.
- Fuente de alimentación externa.

*Consejos para la implementación*

-Se debe tener una fuente externa adicional para la alimentación del servo, esto a fin de reducir el ruido, generado por el mismo motor, al momento de obtener la señal mediante el ADC de arduino.
-Se usa una diferencia de 20 milisegundos, suficiente para poder filtrar unas 100 muestras de la señal de manera óptima, tener en cuenta que en este caso el máximo sería de unas 192 muestras, por lo que si deseáramos aumentar el número de muestras deberíamos aumentar la diferencia. Esto se calcula de la siguiente manera:

La cantidad de muestras por segundo del Arduino UNO son 9600, osea que en 20 milisegundos ha tomado 192 muestras, nosotros promediamos 100 de esas 192, podríamos aumentar a unas 150 muestras, si quisieramos más deberíamos de aumentar la diferencia de 20 milisegundos a unos 30 (por ejemplo), pero tener en cuenta de que esto también aumenta la inercia del sistema (demora más en seguir la señal).
