#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0x47, 0xD1, 0x63, 0xC6, 0x9B, 0x46, 0x4E, 0x05, 0x88, 0xEF, 0x82, 0x83, 0x91, 0xA0, 0x44, 0x0C }
PBL_APP_INFO(MY_UUID,
             "Hello World", "Christian Fink",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;
TextLayer helloLayer;


void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Window Name");
  window_stack_push(&window, true /* Animated */);
	
	text_layer_init(&helloLayer, GRect(0, 65, 144, 30));
	text_layer_set_text_alignment(&helloLayer, GTextAlignmentCenter);
	text_layer_set_text(&helloLayer, "Hello World!");
	text_layer_set_font(&helloLayer, fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));
	layer_add_child(&window.layer, &helloLayer.layer);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
