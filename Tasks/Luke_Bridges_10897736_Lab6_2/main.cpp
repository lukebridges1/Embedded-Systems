#include "mbed.h"
// main() runs in its own thread in the OS

DigitalOut led(LED1);  //LED for visual feedback

#define STACK SIZE 4   //Size of stack 
int stack[STACK_SIZE]; //Stack array
int top = 0;           //Stack pointer

void push(int value){
    if (top >= STACK_SIZE) {
        printf("Error: stack Full\n");
        return;
    }                        //HANDLE STACK FULL CASE 
    stack[top] = value;
    top++;
                            //PUSH VALUE ONTO STACK AND INCREMENT TOP
}

int pop(){
    if (top <= 0){
         printf("Error: Stack Empty\n");
         return -1;                   //HANDLE STACK EMPTY CASE
    }
    top--;
    return stack[top];                        //DECREMENT TOP AND RETURN VALUE 
}

void display_top() {
    if (top <= 0) {
        printf("Stack is Empty\n");
        return;               //HANDLE STACK EMPTY CASE
    }
    printf("Top of stack = %d\n", stack[top - 1]);
                 //DISPLAY THE TOP VALUE 
}

int main(){
    printf(Stack Test Start...\n);       //Push first value
                //Push second value 

    display top();  //Display top value after pushing
                    //Pop the top value 
    display top();  //Display new top value after popping

    while(1){
        led = !led; //Blink LED
        wait_us(0.5) //wait half a second
    }


}
