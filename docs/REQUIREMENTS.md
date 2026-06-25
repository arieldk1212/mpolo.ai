# Requirements

## Hardware Requirements

1. 0V - 3.3V Range
2. LED Indicators for Communication, Power, etc. - GPIO.
3. Button for starting to send data. - Interrupt.
4. GPS Sensor.
5. Camera Connection for identification.
6. Multiple software systems for tracking, controlling, telemtry.
7. 3 Motors.
8. Battery.
9. SD Card to reserve memory.

## Software Requirements

* What is a sensor? module? component? device? learn how to identify each..

* Use Polling + Interrupts.
* Interrupts: Timer, GPIO, UART -> Make ISR's short!
* Polling: User Input, Display Render (if needed), Communications Parsing, Data TX/RX.
* Cast to uint8_t buffers.
* Make sure every once in a while the robot should come up only to transmit a GPS signal, health-check, if it collected important data - wait for downloading at the data center.
* Satellite communication?
* Self-destruct mechanisim??
* Data communication via lasers??
* Add OpenCV - New version with LLM integration!!
* GStreamer!!
* GPS Integration.
* Agent, Tracking, Control, Mission, UI.
* HTTP, LLM.
* Use CMSIS RTOS V2!

## Responsibilities

### ESP32S3/STM32R474RE - Responsibilities

* Responsible for the motors, sensors, etc.
* connects over UART with raspi.
* has the control system flashed in the chip.
* has an open channel of sensors and general telemetry.
* sends data of PSD, of certain mission frequencies to log and track anomalies.
* RF Shield? ML Calculations?
* What sensors to addd? Temperature/Motion, what else? what's needed for underwater activity?

### Raspberry Pi - Responsibilities

* OpenCV with the camera.
* Responsible for the whole pipeline of identification, tracking, sending over controls and where to move.
* has an integrated llm model (TinyML) with its own dataset.
* HTTP server.
* can also write custom kernels for the ai computation.
* UI for all the systems, camera, etc.

### Mission Workflow

1. Identification - Camera identifies a fish, labels it.
2. Thinking - Is it the mission's fish?
3. Track - Send commands, where, capture, track.
4. Autonomous!

## APIs / Systems

### Agent

* Small LLM (Large Language Model): A. Could interact with my home pc.
  B. Could integrate small LLM and llama.cpp for inference, API wrapper for
    the interaction.
  C. Which model? llama4? chat-gpt oss?
  D. Define set of rules and basic "brain" for the agent, who is he, mission,
    default actions, etc.

### Tracking System

* Consumes the coordinates of the agent, displays on map/screen UI,
  option to view previous data points, timestamps, status at point x.

### Control System

* Option to override the agent controls and move the agent as we wish,
  Move the camera to a desired elevation, azimuth.

### Mission System

* Set a mission, provide data, how do we pass data correctly, pulses of data
  while the mission is running from the agent.
