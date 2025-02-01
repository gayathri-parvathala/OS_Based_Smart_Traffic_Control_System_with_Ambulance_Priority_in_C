# OS_Based_Smart_Traffic_Control_System_with_Ambulance_Priority_in_C
OS-Based Smart Traffic Control System with Ambulance Priority
**Project Overview**
This project simulates a smart traffic control system that uses operating system concepts such as priority scheduling and round-robin scheduling to manage traffic flow. The system dynamically adjusts the traffic light sequence, prioritizing roads with ambulances to ensure smooth and safe passage. If no ambulance is detected, the traffic light follows a round-robin cycle to ensure fairness for all roads.

**OS Concepts Used**
- **Priority Scheduling:**

When an ambulance is detected on any road, the traffic light for that road is immediately turned green, overriding the default traffic light cycle. The green light remains for a fixed time to allow the ambulance to pass safely.
- **Round Robin Scheduling:**

In the absence of an ambulance, the system uses a round-robin scheduling algorithm to manage traffic. Each road gets a fixed amount of green light time (5 seconds) in a cyclical order, ensuring that all roads get equal attention.

**New Keywords Used**
- **#define:**

Purpose: Used to define constant values that are substituted throughout the program at compile time. For example, NUM_ROADS and NUM_TIME_SLOTS are defined as constants to represent the number of roads and time slots, respectively.

- **sleep():**

Purpose: Pauses the execution of the program for a specified amount of time, simulating the passage of time between traffic light changes.
Example:

sleep(7);  // Keeps the light green for 7 seconds when an ambulance is detected
- **printf("\r"):**

Purpose: Clears the current line in the terminal output. It is used here to refresh the traffic light display in real-time during each time slot.
Example:

printf("\r");  // Clears the current line and resets output for the new cycle
- **fflush(stdout):**

Purpose: Ensures that the buffered output is immediately written to the screen. It’s used here to immediately display the traffic light changes without waiting for a newline character or buffer flush.
Example:

fflush(stdout);  // Ensures the traffic light states are printed immediately
- **ANSI Escape Codes:**

Purpose: Used for changing text color in the terminal output, enhancing the visualization of the traffic light states. The code uses green for green lights and red for red lights.
Example:
#define GREEN_COLOR "\033[0;32m"

#define RED_COLOR "\033[0;31m"

#define RESET_COLOR "\033[0m"

**Key Features of the Code**
-**Real-Time Traffic Light Management:**

The system uses the sleep() function to simulate the passage of time, with each time slot corresponding to a second. The traffic lights change dynamically based on ambulance detection and default scheduling.
Color-Coded Traffic Lights:

The traffic lights are represented with colors using ANSI escape codes. Roads with green lights are shown in green, while others are shown in red.
Ambulance Detection & Priority:

The system checks for the presence of an ambulance (represented by 1 in the array) during each time slot. When an ambulance is detected on a road, that road’s light turns green, and the other roads remain red for a duration of 7 seconds.
Round Robin Traffic Light Cycle:

When no ambulance is detected, the program follows a round-robin approach, switching between roads. Each road is given 5 seconds of green light, ensuring all roads are fairly managed.
Efficient Time Slot Simulation:

The program simulates a maximum of 10 time slots, where each time slot represents 1 second. This allows for dynamic updates to the traffic light sequence, mimicking real-time traffic control.
Example Output
When running the program, the system will display the current state of the traffic lights:

## Example Output

When running the program, the system will display the current state of the traffic lights:

- **Road 1:** GREEN (represented in green color)
- **Road 2:** RED
- **Road 3:** RED
- **Road 4:** RED

If an ambulance is detected on a road, the output will immediately reflect the change in the traffic light for that road.

Ambulance detected on Road 1! Road 1 light turns GREEN.

If an ambulance is detected on a road, the output will immediately reflect the change in the traffic light for that road:

Ambulance detected on Road 4! Road 4 light turns GREEN


If an ambulance is detected on a road, the output will immediately reflect the change in the traffic light for that road:

Ambulance detected on Road 1! Road 1 light turns GREEN.

This project effectively implements key OS concepts like priority scheduling and round-robin scheduling for managing traffic lights. By prioritizing roads with ambulances, the system ensures that emergency vehicles can pass through traffic efficiently. The round-robin scheduling ensures fairness for all roads when no ambulances are detected, maintaining smooth traffic flow across the system.
