# ⏱ Time-Based Device Control System using LPC2148

## 📘 Overview

This embedded system project implements a *Time-Based Device Control (On/Off)* mechanism using the *LPC2148 ARM7 microcontroller. It allows users to view and set real-time clock (RTC) values and schedule device operation through a **4x4 keypad* and *16x2 LCD* interface. Devices (e.g., LEDs) are turned ON or OFF based on scheduled times.

This type of project is useful in home automation, agriculture watering systems, industrial machine control, etc.

---

## 🎯 Objectives

- Display current *date* and *time* on LCD using RTC.
- Allow *user interaction via keypad* to set date/time and schedule.
- Let the user configure *ON time* and *OFF time* for device.
- Automatically control device (LED) based on the schedule.

---

## 🧰 Hardware Requirements

- 🧠 LPC2148 Microcontroller
- 📟 16x2 LCD
- 🔢 4x4 Matrix Keypad
- 💡 LED (Device)
- 🔘 Switch (Mode Selector)
- 🔌 USB-UART Converter / DB-9 Cable

---

## 💻 Software Requirements

- ⚙ Embedded C (Keil / VS Code)
- 🚀 Flash Magic (for loading program into LPC2148)
- 🧪 Optional: Proteus or any simulation tool

---

## 📊 Block Diagram


+------------+       +--------+        +-----------+
|  4x4 Keypad| ----> | LPC2148| <----> |    LCD    |
+------------+       +--------+        +-----------+
                           |
                      +----------+
                      |   LED    |
                      +----------+

---

## 🔄 Workflow

1. **Initialization**  
   - Initialize RTC, LCD, Keypad, GPIO, and other peripherals.

2. **RTC Display**  
   - Continuously display real-time date and time on the LCD.

3. **Switch Press Detection**  
   - Enter edit mode to change time or configure on/off schedule.

4. **Device Control Logic**  
   - If `current_time >= on_time && current_time <= off_time`:  
     👉 Turn **ON** the device  
   - Else:  
     👉 Turn **OFF** the device  

---

## 🧑‍💻 User Interface on LCD

### 📋 Main Menu (On Switch Press)


1. E.TIME  
2. E.ONOFF TIME  
3. EXIT


### 🕰 Edit RTC Time Menu


1. HOUR  
2. MINUTE  
3. SECOND  
4. DAY  
5. DATE  
6. MONTH  
7. YEAR  
8. EXIT


### ⚙ Edit ON/OFF Time Menu


1. DEVICE ON TIME  
2. DEVICE OFF TIME  
3. EXIT
---

## ✅ Test Cases

- Ensure all user inputs are *validated* (e.g., 0–23 for hours, 0–59 for minutes).
- RTC updates should reflect immediately on LCD.
- Device should turn ON/OFF correctly based on set schedule.
- Check input boundary cases and invalid inputs.
