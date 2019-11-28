#include <gb/gb.h>
/*
	Valores binarios de sonido
	Canal 1 regsiter 0: caida/subidad de tono
		7 no se usa
		6-4 tiempo de actualizacion de tono, 1 cambia el tono, 0 desactivado, max 7
		3 direccion de actualizacion, arrina 1, abajo 0
		2-0 cantidad de tono sumado/restado, 0 desactivado, max 6
	Canal 1, regsiter 1: patron de wave y longitud de sonido (canales 1, 2 y 4)
		7-6 patron de wave, 0-3 (1/ 8, 1/4, 2/4, 3/4), decide cuanto tiempo va a estar encendido respecto a apagado
		5-0 longitud del sonido (cuanto mas grande el numero mas corto el sonido)
	Canal 1, register 2: control de volumen dinamico
		7-4 volumen inicial
		3 direccion de actualizacion, arriba 1, abajo 0 (canales 1, 2 y 4)
		2-0 cantidad de tono sumado/restado, 0 desactivado
		Nota: cada tono sumado es n/64 segundos, n es 1-7
	Canal 1, register 3: tono (el menos importante, en el regsitro 4 se controla mas) y noise (canales 1, 2 y 3)
		7-0 bits de tono, menos importantes
	Canal 1, register 4: playback y tono bits mas significantes (canales 1, 2, 3 y 4)
		7 inicializa el canal (write only)
		6 continuidad del sonido, independiente de la longitud puesta en el canal 1, se reproducira constantemente si el valor es 0
		5-3 no se usa
		2-0 bits de tono
	Si se quiere cambiar la frecuencia, se hace con el reg 4, si se quiere cambiar de forma precisa, se hace con el reg 3
*/
void soundJump(){
	if (joypad() & J_A){
		NR10_REG = 0x16; // canal 1 regsiter 0, 0001 0110
		NR11_REG = 0x40; // canal 1 register 1, 0100 0000
		NR12_REG = 0x73; // canal 1, register 2, 0111 0011
		NR13_REG = 0x70; // canal 1, register 3, 1110 1000
		NR14_REG = 0x84; // canal 1, regsiter 4, 1100 0011
	}
}

/*
    Valores binarios
    Noise 1
        5-0 longitud de sonido
        0001 1111 maxima longitud
    Noise 2 control de volumen
        7-4 volumen inicial 0-0F, 0 no hay sonido
        3 direccion del volumen
        2-0 cantidad de volumen sumado/restado
        1111 0001 empezar con volumen a tope, direccion del volumen descendente, restar 1 cada vez
    Noise 3 control de tono
        7-4 cambiar tono
        3 cantidad de tono sumado/restado, 0 = 15 bit 1 = 7 bit
        2-0 division del ratio de tono
        0011 0000 cambia la frecuencia cada 3 veces?, cantidad 15, division 0
    Noise 4 control de noise
        7 inicializar (1 = reiniciar)
        6 bucle o si termina en lo indicado en el Noise 1
        5-0 sin usar
        1100 0000 iniciar sonido sin ser continuo
*/
void noise(){
    if (joypad() & J_B){
        NR41_REG = 0x1F;
        NR42_REG = 0xF1;
        NR43_REG = 0x57;
        NR44_REG = 0x80;
        delay(1000);
    }
}