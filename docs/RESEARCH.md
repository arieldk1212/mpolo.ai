# Research

## Resources

### From Post about underwater PSI

"At just fifty feet down, water pressure is already 37 psi. That's nearly three times the air pressure at the surface of the ocean.
Go down two-thousand feet…and it's 908 psi.
At crush depth for a nuclear sub — roughly three-thousand feet — it's 1,350 psi
Five-thousand, and you're up to 2,247 psi.
And you've still got another thirty-four thousand feet to go before you reach the deepest spot, and 17,500 psi!
It's difficult because without some very, very, very careful engineering, anything you send, manned or unmanned, ends up like a beer can run over by a semi…"

### Development

* What is a sensor? module? component? device? learn how to identify each..
* Make sure every once in a while the robot should come up only to transmit a GPS signal, health-check, if it collected important data - wait for downloading at the data center.
* Satellite communication?
* Self-destruct mechanisim??

## Physical Model

1. A device that has motors, camera, body, no wires, sensors.

## How?

### Main Components

Agent (Brain), Tracking System, Control System, Mission System, Telemetry System.

* Agent -> Trained model that decides how to act according to the mission's
  settings, suppossed to be solo explorer, go off the grid until completion.
* Tracking System -> How we track the agent, position, health-checks.
* Control System -> Option for overriding the agent's controls and taking over
  the move decisions, play around with the camera.
* Mission System -> setting the mission, target, how long, cancel, start, status,
  reports.
* Agent Settings -> General options for how to handle other stuff, data, actions,
  etc.
* UI -> Current Location Screen, Mission Screen, Controls, Tracking, Telemetry.

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

### ESP32S3 - Responsibilities

* Responsible for the motors, sensors, etc.
* connects over UART with raspi.
* has the control system flashed in the chip.
* has an open channel of sensors and general telemetry.
* sends data of PSD, of certain mission frequencies to log and track anomalies.

### Raspberry Pi - Responsibilities

* OpenCV with the camera.
* responsible for the whole pipeline of identification, tracking, sending over controls and where to move.
* has an integrated llm model (TinyML) with its own dataset.
* HTTP server.
* can also write custom kernels for the ai computation.
* UI for all the systems, camera, etc.

### Mission Workflow

1. Identification - Camera identifies a fish, labels it.
2. Thinking - Is it the mission's fish?
3. Track - Send commands, where, capture, track.
4. Autonomous!
