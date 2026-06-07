# Research

## Resources:

### From Post about underwater PSI

"At just fifty feet down, water pressure is already 37 psi. That's nearly three times the air pressure at the surface of the ocean.
Go down two-thousand feet…and it's 908 psi.
At crush depth for a nuclear sub — roughly three-thousand feet — it's 1,350 psi
Five-thousand, and you're up to 2,247 psi.
And you've still got another thirty-four thousand feet to go before you reach the deepest spot, and 17,500 psi!
It's difficult because without some very, very, very careful engineering, anything you send, manned or unmanned, ends up like a beer can run over by a semi…"


## Physical Model

1. A device that has motors, camera, body, no wires, sensors.


## How?

### Main Components: 

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

