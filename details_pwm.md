
# Cálculos de PWM e Controle de Luminosidade

## 1) Frequência e Período de PWM
- **fpwm = 50 Hz**, **tpwm = 20 ms** (1)
- **fpwm = fclock / div * wrap**  (2)

### Cálculos:
- (1) e (2)
  ```
  50 = 125 * 10^6 / 64 * wrap
  wrap = 125 * 10^6 / 64 * 50
  wrap = 39062,5 ≈ 39062
  ```

Assim, temos:
- **div**: 64
- **wrap**: 39062

## 2) Cálculo de Duty Cycle (DC) para 180 graus
- **DC = 0,12% [180 graus]**
  
  ```
  0,12 = x / 39062
  x = 4687,44 ≈ 4687
  ```

## 3) Cálculo de Duty Cycle (DC) para 90 graus
- **DC = 0,0735% [90 graus]**
  
  ```
  0,0735 = x / 39062
  x = 2871,057 ≈ 2871
  ```

## 4) Cálculo de Duty Cycle (DC) para 0 graus
- **DC = 0,025% [0 graus]**
  
  ```
  0,025 = x / 39062
  x = 976,55 ≈ 977
  ```

## 5) Incremento de ±5µs
- **inc = 5 * 39062 / 20000 = 9,76 ≈ 10**

## 6) Observação sobre a luminosidade do LED
Devido aos valores baixos de Duty Cycle (DC), o LED apresentou luminosidade baixa, com variação praticamente imperceptível.
