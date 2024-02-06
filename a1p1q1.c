#include <stdio.h>
#include <string.h>

// Define the PCB structure
struct PCB {
        int integerMember;
        char charArrayMember[20]; // Example character array member
        // Add other members as needed
};

int main() {
        // Declare a variable of type PCB
        struct PCB pcb;

        // Use memset to initialize pcb to all zeros
        memset(&pcb, 0, sizeof(struct PCB));

        // Now, pcb is initialized to all zeros
        // You can access and use the members of pcb as needed

        return 0;
}
