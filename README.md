# Simpletron

## Overview
Simpletron is a simulated computer system designed as part of a semester project for the Programming Languages course at UNESP. It is inspired by the educational example in the book *Como Programar em C* by Deitel & Deitel (1992). The system allows users to input and execute programs using a simplified assembly-like language.

## Features
- **Custom Instructions**: Includes additional operations such as exponentiation, increment, decrement, zeroing, and modulo.
- **Memory Management**: Supports a memory size of 100 locations.
- **Input Options**: Users can input programs manually or load them from predefined text files.
- **Error Handling**: Detects and handles errors like division by zero and accumulator overflow.
- **Program Execution**: Executes instructions sequentially with branching and halting capabilities.

## How to Use
1. **Run the Program**: Compile and execute the `main.c` file.
2. **Choose Input Method**:
   - Enter the program manually.
   - Load a program from one of the provided `.txt` files.
3. **Execute the Program**: The Simpletron will process the instructions and display the results.

## Instruction Set
The Simpletron supports the following instructions:
- **Input/Output**:
  - `READ (10)`: Reads a value into memory.
  - `WRITE (11)`: Outputs a value from memory.
- **Memory Operations**:
  - `LOAD (20)`: Loads a value into the accumulator.
  - `STORE (21)`: Stores the accumulator value into memory.
- **Arithmetic Operations**:
  - `ADD (30)`, `SUBTRACT (31)`, `DIVIDE (32)`, `MULTIPLY (33)`, `EXPONENTIATION (34)`, `MODULO (38)`.
- **Accumulator Operations**:
  - `INCREMENT (35)`, `DECREMENT (36)`, `ZERO (37)`.
- **Control Flow**:
  - `BRANCH (40)`, `BRANCHNEG (41)`, `BRANCHZERO (42)`, `HALT (43)`.

## Predefined Programs
The following example programs are included in the project:
- **mostrarMaiorValor.txt**: Finds the largest value.
- **fatorial.txt**: Calculates the factorial of a number.
- **verificarSeEPrimo.txt**: Checks if a number is prime.
- **calcularResto.txt**: Computes the remainder of a division.
- **calcularPotencia.txt**: Calculates the power of a number.
- **custom.txt**: Placeholder for user-defined programs.

## Example Usage

### Example 1: Calculating Factorial
To calculate the factorial of a number, use the `fatorial.txt` program:
1. Run the Simpletron program.
2. Select the option to load a program from a file.
3. Choose `fatorial.txt` from the list.
4. Enter the number for which you want to calculate the factorial when prompted.
5. The result will be displayed after execution.

### Example 2: Checking if a Number is Prime
To check if a number is prime, use the `verificarSeEPrimo.txt` program:
1. Run the Simpletron program.
2. Select the option to load a program from a file.
3. Choose `verificarSeEPrimo.txt` from the list.
4. Enter the number to check when prompted.
5. The program will output whether the number is prime.

### Example 3: Custom Program
You can create your own program by editing `custom.txt`:
1. Write your program using the Simpletron instruction set.
2. Save the file.
3. Run the Simpletron program and select `custom.txt` to execute your custom program.

## Example Code Inputs

Below is an example of a Simpletron program to calculate the factorial of a number:

```
+1099  // Read the input number into memory location 99
+2099  // Load the number from memory location 99 into the accumulator
+2198  // Store the accumulator value into memory location 98 (used as a counter)
+3700  // Zero the accumulator
+3500  // Increment the accumulator (set it to 1)
+2197  // Store the value 1 into memory location 97 (used for the result)
+3700  // Zero the accumulator
+3500  // Increment the accumulator (set it to 1)
+3198  // Subtract the counter value (memory location 98) from the accumulator
+4217  // Branch if zero to memory location 17 (end of loop)
+2097  // Load the current result from memory location 97
+3398  // Multiply it by the counter value (memory location 98)
+2197  // Store the new result back into memory location 97
+2098  // Load the counter value from memory location 98
+3600  // Decrement the counter
+2198  // Store the decremented counter back into memory location 98
+4006  // Branch unconditionally to memory location 06 (start of loop)
+1197  // Write the final result from memory location 97
+4300  // Halt the program
```

This program reads a number, calculates its factorial, and outputs the result.

## File Structure
- `main.c`: The main program file containing the Simpletron implementation.
- `.txt` files: Predefined programs for testing and demonstration.

## Requirements
- A C compiler (e.g., GCC).
- Basic understanding of assembly-like programming.

## How to Compile and Run
1. Compile the program:
   ```bash
   gcc -o simpletron main.c -lm
   ```
2. Run the executable:
   ```bash
   ./simpletron
   ```

## License
This project is for educational purposes and is part of the coursework for the Programming Languages class at UNESP.

## Author
Pedro Alonso Oliveira dos Santos  
Supervised by Prof. Dr. Rogério Eduardo Garcia  
UNESP - Universidade Estadual Paulista "Júlio de Mesquita Filho"  
2024 - FCT UNESP
