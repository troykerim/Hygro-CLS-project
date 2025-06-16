# Hygro CLS Project

## Overview

This embedded systems project uses Vivado IP integrator and Xilinx SDK/Vitis to interface with two Digilent Pmods:
- **PmodHYGRO**: Captures temperature and humidity from the environment via I²C.
- **PmodCLS**: Displays the sensor readings on a 16x2 LCD using SPI.

The system is implemented on a Zynq-7000 SoC (Zybo Z7-10), combining both hardware and software components. The design utilizes IP blocks to handle peripheral interfaces and communication protocols.

---

## Hardware


| Zybo Z7-20 Board | PmodHYGRO | PmodCLS |
|------------------|-----------|---------|
| ![Zybo Z7](images/Digilent_Zybo_Z7-20.jpg) | ![PmodHYGRO](images/PmodHYGRO.png) | ![PmodCLS](images/Pmod_CLS.png) |

---

## Block Design

| Vivado Block Design |
|---------------------|
| ![Block Design](images/Hygro_CLS_blockdesign.png) |

---

## Results
### CLS LCD Output

![CLS Output](images/CLS_output.jpg)

This shows the PmodHYGRO and PmodCLS connected to the Zybo Z7-10. The LCD displays the live temperature in Fahrenheit and the relative humidity.

---

### Vitis Serial Terminal Output

![Vitis Terminal](images/Vitis_Serial_terminal.png)

In addition to displaying the values on the CLS LCD, the system logs the temperature and humidity over UART to the Vitis serial terminal once per second for debugging and monitoring purposes.



## Future Work

- [ ] Add video demo.
- [ ] Add screenshots.
- [ ] Add additional features:
  - Add Fahrenheit/Celsius toggle via button
  - Display min/max values
- [ ] Create alternate version using RTL/HDL (without Vivado IP integrator):
  - Use I²C and UART modes for CLS Pmod (instead of SPI)

---

## Requirements

- Zybo Z7-10 FPGA board
- Digilent PmodCLS 
- Digilent PmodHYGRO 
- Vivado + Vitis (2020.2 or later recommended)