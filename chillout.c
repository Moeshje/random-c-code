#include <stdio.h>
#include <gpiod.h>
int main(void)
{
struct gpiod_chip *chip = gpiod_chip_open("/dev/gpiochip0");
struct gpiod_request_config *req_cfg = gpiod_request_config_new();
struct gpiod_line_config *lconf = gpiod_line_config_new();
struct gpiod_line_settings *setthethings = gpiod_line_settings_new();
gpiod_line_settings_set_direction(setthethings, GPIOD_LINE_DIRECTION_OUTPUT);
unsigned int offsets[] = {36};
gpiod_line_config_add_line_settings(lconf, offsets, 1, setthethings);
struct gpiod_line_request *askme = gpiod_chip_request_lines(chip, req_cfg, lconf);
gpiod_line_request_set_value(askme, 36, GPIOD_LINE_VALUE_ACTIVE);
}
