#include <stm32f30x_conf.h>
#include <led_driver.h>

void init_led(void) {
    // Enable clock for GPIO ports A, B, C
    RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
    RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
    RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

    /* Configure pins for LED */
    // Pin PB4, red
    GPIOB->OSPEEDR &= ~(0x00000003 << (R_LED_PB4 * 2)); // Clear speed register
    GPIOB->OSPEEDR |=  (0x00000002 << (R_LED_PB4 * 2)); // Set speed register
    GPIOB->OTYPER  &= ~(0x00000003 << (R_LED_PB4 * 2)); // Clear output type register
    GPIOB->OTYPER  |=  (0x00000000 << (R_LED_PB4 * 2)); // Set output type register (0x00 - Push-pull, 0x01 - Open-drain)
    GPIOB->MODER   &= ~(0x00000003 << (R_LED_PB4 * 2)); // Reset mode register
    GPIOB->MODER   |=  (0x00000001 << (R_LED_PB4 * 2)); // Set mode register (0x00 - Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

    // Pin PC7, green
    GPIOC->OSPEEDR &= ~(0x00000003 << (G_LED_PC7 * 2)); // Clear speed register
    GPIOC->OSPEEDR |=  (0x00000002 << (G_LED_PC7 * 2)); // Set speed register
    GPIOC->OTYPER  &= ~(0x00000003 << (G_LED_PC7 * 2)); // Clear output type register
    GPIOC->OTYPER  |=  (0x00000000 << (G_LED_PC7 * 2)); // Set output type register (0x00 - Push-pull, 0x01 - Open-drain)
    GPIOC->MODER   &= ~(0x00000003 << (G_LED_PC7 * 2)); // Reset mode register
    GPIOC->MODER   |=  (0x00000001 << (G_LED_PC7 * 2)); // Set mode register (0x00 - Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

    // Pin PA9, blue
    GPIOA->OSPEEDR &= ~(0x00000003 << (B_LED_PA9 * 2)); // Clear speed register
    GPIOA->OSPEEDR |=  (0x00000002 << (B_LED_PA9 * 2)); // Set speed register
    GPIOA->OTYPER  &= ~(0x00000003 << (B_LED_PA9 * 2)); // Clear output type register
    GPIOA->OTYPER  |=  (0x00000000 << (B_LED_PA9 * 2)); // Set output type register (0x00 - Push-pull, 0x01 - Open-drain)
    GPIOA->MODER   &= ~(0x00000003 << (B_LED_PA9 * 2)); // Reset mode register
    GPIOA->MODER   |=  (0x00000001 << (B_LED_PA9 * 2)); // Set mode register (0x00 - Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
}

void set_led(uint8_t red, uint8_t green, uint8_t, blue) {
}