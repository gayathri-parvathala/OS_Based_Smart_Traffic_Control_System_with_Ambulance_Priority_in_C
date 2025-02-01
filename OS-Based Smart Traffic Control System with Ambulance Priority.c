#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_ROADS 4
#define NUM_TIME_SLOTS 10
#define GREEN_COLOR "\033[0;32m"
#define RED_COLOR "\033[0;31m"
#define RESET_COLOR "\033[0m"
void control_traffic(int roads[NUM_ROADS][NUM_TIME_SLOTS], int time_slots) {
    int green_road = -1;  
    int last_cycle_road = 0; 
    for (int t = 0; t < time_slots; t++) {
        printf("\r");
        int ambulance_detected = 0;
        for (int i = 0; i < NUM_ROADS; i++) {
            if (roads[i][t] == 1) {
                green_road = i;  
                for (int j = 0; j < NUM_ROADS; j++) {
                    if (j == green_road) {
                        printf(GREEN_COLOR "Road %d: GREEN  " RESET_COLOR, j + 1);
                    } else {
                        printf(RED_COLOR "Road %d: RED    " RESET_COLOR, j + 1);
                    }
                }
                ambulance_detected = 1;
                sleep(7);  
                break;  
            }
        }
        if (!ambulance_detected) {
            green_road = last_cycle_road;
            for (int i = 0; i < NUM_ROADS; i++) {
                if (i == green_road) {
                    printf(GREEN_COLOR "Road %d: GREEN  " RESET_COLOR, i + 1);
                } else {
                    printf(RED_COLOR "Road %d: RED    " RESET_COLOR, i + 1);
                }
            }
            last_cycle_road = (last_cycle_road + 1) % NUM_ROADS; 
            sleep(5);  
        }

        fflush(stdout);  
        sleep(1);  /
    }
    printf("\n"); 
}
int main() {
   
    int roads[NUM_ROADS][NUM_TIME_SLOTS] = {
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},  
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}   
    };
    int time_slots = NUM_TIME_SLOTS;
    control_traffic(roads, time_slots);
    return 0;
}