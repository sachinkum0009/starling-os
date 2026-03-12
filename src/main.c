#include <zephyr/kernel.h>
#include "led_button.h"

int main(void)
{
	if (led_button_init() < 0) {
		return -1;
	}

	while (1) {
		led_button_update();
		k_msleep(10);
	}
	return 0;
}
