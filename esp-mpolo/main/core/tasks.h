#ifndef TASKS_H_
#define TASKS_H_

namespace rt::core {

static void InitTasks() {}

}  // namespace rt::core

/*
Tasks & Queues:

https://stackoverflow.com/questions/78027020/freertos-on-esp32-task-handling-priorities-interrupts

QueueHandle_t ev_queue; // Queue for sending events to worker thread
TimerHandle_t timer;    // Timer for generating periodic events

// Event definitions
typedef enum {
    EV_READ_SENSORS,
    EV_FAN_CLEANING,
    EV_UPDATE_RGB_LED,
    EV_CONTROL_DISPLAY,
} event_t;

// ISR generates some event
void IRAM_ATTR gotTouchSEN55cleaning() {
    event_t ev = EV_FAN_CLEANING;
    xQueueSendFromISR(ev_queue, &ev, NULL);
}

// ISR generates some other event
void IRAM_ATTR gotTouchDisplayCarousel() {
    event_t ev = EV_CONTROL_DISPLAY;
    xQueueSendFromISR(ev_queue, &ev, NULL);
}

// Timer generates the periodic events
void on_timer(TimerHandle_t timer_h) {
    event_t ev;
    if (TIME_TO_READ_SENSORS()) {
        ev = EV_READ_SENSORS;
        xQueueSend(ev_queue, &ev, 0);
    }
    if (TIME_TO_UPDATE_RGB_LED()) {
        ev = EV_UPDATE_RGB_LED;
        xQueueSend(ev_queue, &ev, 0);
    }
}

// Single task handles all events in order of appearance
void worker(void* arg) {
    while (true) {
        event_t ev;
        if (xQueueReceive(ev_queue, &ev, portMAX_DELAY)) {
            switch (ev) {
            case EV_READ_SENSORS:
                ReadSensors(); // Your code in here, no FreeRTOS task management
needed break; case EV_FAN_CLEANING: FanCleaningSEN55(); break; case
EV_UPDATE_RGB_LED: UpdateRGBLED(); break; case EV_CONTROL_DISPLAY:
                ControlDisplay();
                break;
            }
        }
    }
}

void app_main() {
    ev_queue = xQueueCreate(10, sizeof(event_t));
    assert(ev_queue);
    BaseType_t ret = xTaskCreatePinnedToCore(worker, "Worker", 10000, NULL, 10,
NULL, 1); assert(ret == pdPASS); timer = xTimerCreate("MyTimer",
pdMS_TO_TICKS(100), pdTRUE, NULL, on_timer); assert(timer);
}
*/

#endif
