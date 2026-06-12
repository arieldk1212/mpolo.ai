# Hardware

## Base Components

### Camera

* Logitech C270

### MCU & Board

#### Board

* To connect (OLD): ssh <adk@adk.local>, pass: adk, WITHOUT tailscale (Ras OS).
* To connect (UPDATED): ssh adk@192.168.7.8, WITHOUT tailscale (Ubuntu 26.04 + ROS 2 Lyrical Luth).

* Raspberrypi 4 Model B 4GB RAM.

* OS: Ubuntu 26.04 LTS + ROS.

* Architecture:
Broadcom BCM2711, Quad core Cortex-A72 (ARM v8) 64-bit SoC @ 1.8GHz
1GB, 2GB, 3GB, 4GB or 8GB LPDDR4-3200 SDRAM (depending on model)
2.4 GHz and 5.0 GHz IEEE 802.11ac wireless, Bluetooth 5.0, BLE
Gigabit Ethernet
2 USB 3.0 ports; 2 USB 2.0 ports.
Raspberry Pi standard 40 pin GPIO header (fully backwards compatible with previous boards)
2 × micro-HDMI® ports (up to 4kp60 supported)
2-lane MIPI DSI display port
2-lane MIPI CSI camera port
4-pole stereo audio and composite video port
H.265 (4kp60 decode), H264 (1080p60 decode, 1080p30 encode)
OpenGL ES 3.1, Vulkan 1.0
Micro-SD card slot for loading operating system and data storage
5V DC via USB-C connector (minimum 3A*)
5V DC via GPIO header (minimum 3A*)
Power over Ethernet (PoE) enabled (requires separate PoE HAT)
Operating temperature: 0 – 50 degrees C ambient

#### MCU

* ESP32S3 - FreeRTOS
* Components: esp-dsp
* Comms: UART

### Motors

* 2 Motors, Big size, DC, water-proof

### Sensors/Modules

* 2 Lights
* GPS Module

### Batteries

* Long operation batteries (lithium based)

### Memory

* SD Card for storing data, images, videos

### Frame

* Could also be just plastic box
* Underwater viable
* Viable PSI for basic operation
* 2 MCU's positions
