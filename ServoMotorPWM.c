#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_GPIO 22
#define LED_GPIO 12

// Ajuste da configuração do PWM para 50Hz (Período de 20ms = 20000us)
#define PWM_WRAP 39062 // Valor Wrap (valor máximo do contador PWM)
#define PWM_CLKDIV 64.0 // Ajuste do clock divisor

// Definição dos ciclos de trabalho conforme os cálculos
#define PULSO0_GRAUS 977   // 0 graus (DC =  0,025%)
#define PULSO90_GRAUS 2871  // 90 graus (DC = 0,0735%)
#define PULSO180_GRAUS 4687 // 180 graus (DC = 0,12%)

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_GPIO, GPIO_FUNC_PWM);
    gpio_set_function(LED_GPIO, GPIO_FUNC_PWM);
    
    uint slice_num = pwm_gpio_to_slice_num(SERVO_GPIO);
    uint8_t state = 1;
    
    pwm_set_wrap(slice_num, PWM_WRAP);
    pwm_set_clkdiv(slice_num, PWM_CLKDIV);
    pwm_set_enabled(slice_num, true);
    
    while (1) {
        if (state)
        { //Realiza os 3 movimentos iniciais uma única vez (posiciona o braço em 180, 90 e 0 graus, respectivamente) com pausa de 5s entre eles 
            pwm_set_gpio_level(SERVO_GPIO, PULSO180_GRAUS);
            sleep_ms(5000);
            pwm_set_gpio_level(SERVO_GPIO, PULSO90_GRAUS);
            sleep_ms(5000);
            pwm_set_gpio_level(SERVO_GPIO, PULSO0_GRAUS);
            sleep_ms(5000);
            state = 0;
        }

        // Movimentação periódica suave entre 0 e 180 graus
        for (uint32_t pulso = PULSO0_GRAUS; pulso <= PULSO180_GRAUS; pulso += 10) {
            pwm_set_gpio_level(SERVO_GPIO, pulso);
            sleep_ms(10);
        }
        for (uint32_t pulso = PULSO180_GRAUS; pulso >= PULSO0_GRAUS; pulso -= 10) {
            pwm_set_gpio_level(SERVO_GPIO, pulso);
            sleep_ms(10);
        }
    }
}
