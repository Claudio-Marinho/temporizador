#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

int estado_semaforo = 0;

// Função para controlar os LEDs
void set_leds(int vermelho, int amarelo, int verde) {
    gpio_put(LED_VERMELHO, vermelho);
    gpio_put(LED_AMARELO, amarelo);
    gpio_put(LED_VERDE, verde);
}

bool repeating_timer_callback(struct repeating_timer *t) {
    switch (estado_semaforo) {
        case 0: // Vermelho
            set_leds(1, 0, 0);
            printf("SINAL VERMELHO!\n");
            estado_semaforo = 1;
            break;
        case 1: // Amarelo
            set_leds(0, 1, 0);
            printf("SINAL AMARELO!\n");
            estado_semaforo = 2;
            break;
        case 2: // Verde
            set_leds(0, 0, 1);
            printf("SINAL VERDE!\n");
            estado_semaforo = 0;
            break;
    }
    return true;
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        sleep_ms(1000);
        printf("rotina de repetição\n");
    }
    return 0;
}