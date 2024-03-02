#include <stdio.h>
#include <stdlib.h>
#include "CA.h"
#include "state.h"

int get_distance_random (int l, int r, int count);



// Global variables
unsigned int speed = 0;
unsigned int distance = 0;
unsigned int threshold = 50;

// Global pointer to function
void (*CA_state)();

state_define(CA_waiting) {
    // State name
    enum CA_State state_id = waiting;
    // State action
    speed = 0;
    // Generate random distance
    distance = get_distance_random(45, 55, 1);

    // Check event
    (distance <= threshold) ? (CA_state = state(CA_waiting)) : (CA_state = state(CA_driving));
    printf("Waiting state: distance = %d speed = %d\n", distance, speed);
}

state_define(CA_driving) {
    // State name
    enum CA_State state_id = driving;
    // State action
    speed = 30;
    // Generate random distance
    distance = get_distance_random(45, 55, 1);

    // Check event
    (distance <= threshold) ? (CA_state = state(CA_waiting)) : (CA_state = state(CA_driving));
    printf("Driving state: distance = %d speed = %d\n", distance, speed);
}

int get_distance_random(int l, int r, int count) {
    int i, rand_num;
    for (i = 0; i < count; i++) {
        rand_num = (rand() % (r - l + 1)) + l;
    }
    return rand_num;
}
