#ifndef INTERRUPTS_H
#define INTERRUPTS_H

void* countdown_thread(void* arg);
void interrupt_handler(int signum);
void setup_interrupt_thread();
void handle_input();

#endif