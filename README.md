# Line Follower Robot

## Overview

The **Line Follower Robot** is an autonomous robotic vehicle designed to follow a predefined path using infrared (IR) sensors.

The robot continuously detects the position of a black line on a contrasting surface and adjusts the speed and direction of its motors accordingly.

The project demonstrates basic concepts of **embedded systems, sensor interfacing, motor control, and autonomous navigation**.

---

## How It Works

Five IR sensors are placed at the front of the robot to detect the line.

The Arduino reads the sensor outputs and determines whether the robot needs to:

- Move forward
- Turn left
- Turn right
- Make a sharp turn
- Stop

The Arduino controls the two DC motors through an **L298N motor driver**.

```text
          IR SENSOR ARRAY
        S1 S2 S3 S4 S5
             │
             ▼
        Arduino Uno
             │
             ▼
        L298N Driver
          │       │
          ▼       ▼
     Left Motor  Right Motor
