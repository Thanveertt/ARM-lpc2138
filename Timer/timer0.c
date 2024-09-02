#include <lpc213x.h>

void main()
{
    IO0DIR = ~0;             // Configure Port 0 as output
    T0TCR = 2;               // Reset Timer 0
    T0TCR = 1;               // Start Timer 0
    T0CTCR = 0;              // Set Timer 0 in Timer Mode (counts PCLK cycles)
    T0PR = 24999999;         // Set Prescaler Register to create a 1-second delay
    T0TC = 0;                // Reset Timer Counter
    T0PC = 0;                // Reset Prescale Counter

    while(1)                 // Infinite loop
    {
        if (T0TC % 2 == 0)   // Check if Timer Counter is even
        {
            IO0SET = ~0;     // Set all pins of Port 0 to high
        }
        else
        {
            IO0CLR = ~0;     // Clear all pins of Port 0 (set to low)
        }
    }
}
