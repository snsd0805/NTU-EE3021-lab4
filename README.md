# NTU-EE3021-lab3 (BLE Central (GATT client) Programming)

## Members
- R12922A01 王廷郡
- R11944078 林資融


## Lab Requirements (From NTU Cool)
```
====basic problem====

In this BLE project, treat your STM32 as a server and RPi as a client. You
need to build a GATT accelerator service in your STM32 with two main
characteristics: (a) the 3-axis acceleration values and (b) the accelerator
sampling frequency. Your RPi can assign a sampling frequency for the STM32
accelerator via writing to GATT characteristic_b.

Each time when your STM32 samples acceleration data, the GATT characteristic_a
is updated by new values and the STM32 notifies the new values to RPi.

In STM32, please meet the requirements with RTOS by creating TASK_BLE and 
TASK_ACC. TASK_BLE is in charge of the basic BLE event handling for GAP
connection, GAP disconnection, GATT write requests, etc. TASK_ACC is
responsible for reading the accelerator values with the assigned frequency
and notifying RPi.
 

p.s. the 3-axis acceleration values should be real data sampled from LSM6DSM
 instead of the simulated values.

=================

 

====option problem_A====

Use another STM32 board. Replace the RPi client with STM32 client.

===================

 


====option problem_B==== (optional personal report)

Students can choose content that is relevant to the class of this week, less
repetitive with the assignment, and meaningful to conduct experiments on their
own, and write a report on the experimental content and results.

===================

```
