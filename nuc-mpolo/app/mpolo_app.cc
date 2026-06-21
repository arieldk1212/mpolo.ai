#include "mpolo_app.h"

__IO uint32_t kBspButtonState = BUTTON_RELEASED;

extern "C" void MpoloApp() {
  while (true) {
    if (kBspButtonState == BUTTON_PRESSED) {
      BSP_LED_On(LED_GREEN);
      kBspButtonState = BUTTON_RELEASED;
    }
  }
}
