#include "led_button.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED0_NODE DT_ALIAS(led0)
#define SW0_NODE  DT_ALIAS(sw0)

static const struct gpio_dt_spec led    = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0_NODE, gpios);

int led_button_init(void)
{
	int ret;

	if (!device_is_ready(led.port)) {
		return -ENODEV;
	}

	if (!device_is_ready(button.port)) {
		return -ENODEV;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
	if (ret < 0) {
		return ret;
	}

	ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret < 0) {
		return ret;
	}

	return 0;
}

void led_button_update(void)
{
	int pressed = gpio_pin_get_dt(&button);

	gpio_pin_set_dt(&led, pressed > 0 ? 1 : 0);
}
