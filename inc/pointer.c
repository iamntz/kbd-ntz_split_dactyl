
void pointing_device_init_user(void)
{
  set_auto_mouse_layer(5);     // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
  set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}