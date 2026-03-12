#ifndef LED_BUTTON_H
#define LED_BUTTON_H

/**
 * @brief Initialize the LED and button GPIO pins.
 *
 * @return 0 on success, negative errno code on failure.
 */
int led_button_init(void);

/**
 * @brief Read the button state and drive the LED accordingly.
 *        LED turns ON while button is pressed, OFF when released.
 */
void led_button_update(void);

#endif /* LED_BUTTON_H */
