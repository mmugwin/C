#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include "interrupts.h"

volatile int countdown = 0;
volatile bool interrupt_thread_active = false;

void* countdown_thread(void* arg){    
    printf("Countdown thread started.\n");
    while (countdown > 0) {
        printf("%d seconds remaining...\n", countdown);
        sleep(1);
        countdown--;
    }
    printf("Countdown has finished!\n");

    // Reset the countdown and interrupt thread status
    countdown = 0;
    interrupt_thread_active = false;
    return NULL;
}

void setup_interrupt_thread(){    
    pthread_t thread;
    pthread_create(&thread, NULL, countdown_thread, NULL);
    pthread_detach(thread);
    interrupt_thread_active = true;
}

void handle_input(){    
    char input;
    read(STDIN_FILENO, &input, sizeof(char));
    if(!interrupt_thread_active) {
        if(input == 'p') {
            countdown = 10;
            printf("Handling interrupt for p. Starting countdown from 10 seconds...\n");
            setup_interrupt_thread();
        } else if (input == 'w') {
            countdown = 5;
            printf("Handling interrupt for w. Starting countdown from 5 seconds...\n");
            setup_interrupt_thread();
        }
    }
}
