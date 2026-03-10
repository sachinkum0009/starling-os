#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

#define SLEEP_TIME_MS 1000

int main(void)
{
	int ret;

	if (!device_is_ready(led.port)) {
		return -1;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return -1;
	}

	while (1) {
		gpio_pin_toggle(led.port, led.pin);
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
