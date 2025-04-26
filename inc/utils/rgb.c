void trackball_set_rgbw(uint8_t red, uint8_t green, uint8_t blue, uint8_t white)
{
  uint8_t data[] = {0x00, red, green, blue, white};
  i2c_transmit(TRACKBALL_ADDRESS, data, sizeof(data), 100);
}