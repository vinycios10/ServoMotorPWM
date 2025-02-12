# Controle de Servo Motor com Raspberry Pi Pico

## Descrição
Este programa controla um servo motor conectado à GPIO 22 do Raspberry Pi Pico, utilizando PWM para movimentar o servo entre as posições de 0°, 90° e 180°. Além disso, ele implementa uma movimentação periódica suave entre 0° e 180°.

## Requisitos
- Raspberry Pi Pico
- Servo motor compatível com PWM
- VS Code ou outro ambiente de desenvolvimento compatível
- Pico SDK instalado

## Configuração do PWM
- **Frequência do PWM**: 50Hz (Período de 20ms)
- **PWM Wrap**: 39062
- **Clock Divisor**: 64.0
- **Ciclos de Trabalho**:
  - 0°: 977 (0,025%)
  - 90°: 2871 (0,0735%)
  - 180°: 4687 (0,12%)

## Instalação e Uso
1. Clone ou copie este repositório para seu ambiente de desenvolvimento.
2. Compile o código utilizando o Pico SDK.
3. Carregue o binário no Raspberry Pi Pico.
4. Conecte o servo motor na GPIO 22 e um LED opcional na GPIO 12.
5. Execute o programa e observe o movimento do servo.

## Funcionamento
- O programa inicia movendo o servo para 180°, depois 90° e, por fim, 0°, com pausas de 5 segundos entre as mudanças.
- Em seguida, entra em um loop onde o servo se movimenta suavemente entre 0° e 180° com incrementos de 10 unidades a cada 10ms.

## Observações
- Caso deseje alterar a suavidade do movimento, ajuste o incremento e o tempo de delay no loop principal.
- Certifique-se de que seu servo motor suporta os valores definidos para evitar problemas mecânicos.

## Autor
Projeto desenvolvido como parte de um exercício prático para controle de PWM com Raspberry Pi Pico.

