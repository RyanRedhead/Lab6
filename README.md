Lab 6
==================
#Purpose

The purpose of this lab was to use pulse-width modulation from the MSP430 to control the speed and direction of the robot's DC motors.

#Hardware Schematic

![Alt Text](https://github.com/RyanRedhead/Lab6/blob/master/Prelab.JPG?raw=true)

![Alt Text](https://github.com/RyanRedhead/Lab6/blob/master/Robot.JPG?raw=true)

#Debugging

Debugging for this lab was rather easy once Dr Coulston explained how to do it. I wasn't getting the output I originally assumed and used the o-scope to test each wire from the MSP430 to make sure it output what I wanted it to.

#Testing Methedology/Results

To find the right duty cycle to run the motors at I first found the stall current. Since the current could not exceed 1 A, I measured several other duty cycle currents.

| Duty Cycle (%)  |  Current (A) |
|---|---|
| 50  |  0.48 |
| 60  |  0.58 |
| 70  |  0.71 |
| 80  |  0.78 |


I choose a duty cycle of 60% for forward and reverse movement.

I then wired up the robot to match my prelab and the code worked.

I have two independent signals to each motor and I choose to drive it like a car. I could have it turn like a tank by changing the direction of a motor.

##Required Functionality

I sent functionality to Dr York via email.

I since then changed the functionality file to include functions for the movements. This would made controlling the speeds and times easier. For the difference in small and large turns i increased the delay cycles command.

#Observations/Conclusions

The code in this lab will help with the next two labs for basic robotic movements.

##Documentation
I used http://www.tablesgenerator.com/markdown_tables to create the duty cycle table.

Dr Coulston helped me understand how to use the o-scope for debugging and explained to me his diagrams on the whiteboards.
