# Technical specification | team 6 

<br>

| Document Type  | Specification           |
| -------------- | ----------------------- |
| Document Owner | Habi CAILLEAU           |
| Issue date     | 09/02/2024              |
| Document Name  | Technical Specification |

<br>

| Role               | Name                    | Signature | Date       |
| ------------------ | ----------------------- | --------- | ---------- |
| Project Manager    | Michel Riff             |           | 30/01/2024 |
| Program Manager    | Raphaël Descamps        |           | 30/01/2024 |
| Tech Lead          | Habi Cailleau           | ✅         | 30/01/2024 |
| Software Developer | Lucas Aubard            |           | 30/01/2024 |
| Software Developer | Vivien Bistrel Tsangue  |           | 30/01/2024 |
| Quality Assurance  | Loris De Mattia Segalat |           | 30/01/2024 |

---
<br>
<details>
<summary> Table of Contents </summary>
<br>

- [Technical specification | team 6](#technical-specification--team-6)
- [1. Introduction](#1-introduction)
  - [1.1 Document objectives \& clarification](#11-document-objectives--clarification)
  - [1.2 Overview](#12-overview)
    - [1.2.1 Purpose](#121-purpose)
    - [1.2.2 Scope](#122-scope)
    - [1.2.3 Out of Scope](#123-out-of-scope)
  - [1.3 Glossary](#13-glossary)
  - [1.4 Implementation](#14-implementation)
    - [1.4.1 Requirements](#141-requirements)
      - [1.4.1.1 Hardware requirements](#1411-hardware-requirements)
      - [1.4.1.2 Software requirements](#1412-software-requirements)
    - [1.4.2 Setup and Installation](#142-setup-and-installation)
    - [1.4.3 Execution](#143-execution)
- [2.Project Infrastructure](#2project-infrastructure)
  - [2.1 Directory and Naming Convention](#21-directory-and-naming-convention)
    - [2.1.1 Directory Structure](#211-directory-structure)
    - [2.1.2 Naming Conventions](#212-naming-conventions)
    - [2.1.3 Formatting conventions](#213-formatting-conventions)
    - [2.1.3.1 Identation](#2131-identation)
    - [2.1.3.2 Braces](#2132-braces)
    - [2.1.3.3 Line Length](#2133-line-length)
    - [2.1.3.4 Blank Lines](#2134-blank-lines)
    - [2.1.3.5 Comments](#2135-comments)
  - [2.2 Folder structure](#22-folder-structure)
  - [2.3 Assembly Language Design](#23-assembly-language-design)
    - [2.3.1 Storing an immediate Value Storage into a Register](#231-storing-an-immediate-value-storage-into-a-register)
    - [2.3.2 Register-to-Register Value Copying](#232-register-to-register-value-copying)
    - [2.3.3 Memory Value Read from the Address Stored in a Register](#233-memory-value-read-from-the-address-stored-in-a-register)
    - [2.3.4 Register Value Stored into Memory at the Address Contained in Another Register](#234-register-value-stored-into-memory-at-the-address-contained-in-another-register)
    - [2.3.4 Comparison of Register Contents](#234-comparison-of-register-contents)
    - [2.3.5 Unconditional Jump to a Label](#235-unconditional-jump-to-a-label)
    - [2.3.6 Conditional Jump Instructions](#236-conditional-jump-instructions)
    - [2.3.7 Subroutine Call and Return:](#237-subroutine-call-and-return)
    - [2.3.8 Basic Arithmetic Operations: Addition, Subtraction, Multiplication, and Division:](#238-basic-arithmetic-operations-addition-subtraction-multiplication-and-division)
    - [2.3.9 Basic Logical Operations: OR, AND, XOR, and NOT](#239-basic-logical-operations-or-and-xor-and-not)
- [dont forget to add our assembly language](#dont-forget-to-add-our-assembly-language)
- [3.Technical specification](#3technical-specification)
  - [3.1 Interpreter](#31-interpreter)
    - [3.1.1 Error Handling Mechanism](#311-error-handling-mechanism)
      - [3.1.1.1 Technical Execution Process :](#3111-technical-execution-process-)
      - [3.1.1.2 Error Handling](#3112-error-handling)
      - [3.1.1.3 Output Handling](#3113-output-handling)
      - [3.1.1.4 Examples](#3114-examples)
  - [3.2 Assembler](#32-assembler)
    - [3.2.1 Assembler Functionality](#321-assembler-functionality)
    - [3.2.1.1 Parsing](#3211-parsing)
    - [3.2.1.2 Symbol Table](#3212-symbol-table)
    - [3.2.1.3 Translation](#3213-translation)
    - [3.2.1.4 Error Handling](#3214-error-handling)
    - [3.2.1.5 Optimization (Optional)](#3215-optimization-optional)
</details>
<br>



# 1. Introduction

## 1.1 Document objectives & clarification
Before reading the document, let's clarify the purpose of the technical specification. 

The aim of this document is to reframe the Functional Requirements, elucidating the project's features, scope, and objectives, into explicit instructions. These directives act as a roadmap for both the development and quality assurance teams, steering them towards the successful accomplishment of their objectives.

I recommend you to read the Functional Specification before proceeding, you can access it via this [link]( https://github.com/algosup/2023-2024-project-3-virtual-processor-team-6/blob/main/Documents/FunctionalSpecification/FunctionalSpecification.md ).

The goal of the Technical is to help engineers from making uninformed decisions and to avoid misunderstandings. While the Functional Requirements address the "What/Why" aspect, the Technical Requirements delve into the "How" of the project.

## 1.2 Overview

The project emphasizes the creation of a robust and versatile platform that adheres to simplicity and reliability principles. Executed in plain, portable C language, the project restricts the use of external libraries to C standard libraries. The recommended tools for development include the gcc compiler and Visual Studio Code as the Integrated Development Environment (IDE).

### 1.2.1 Purpose

The primary purpose of this project is to engineer a virtual processor capable of interpreting and executing assembly code efficiently. By providing a reliable and flexible platform, the project aims to support the development and testing of assembly programs within a controlled environment. The purpose encompasses the creation of a minimal assembly language, the development of a corresponding interpreter, and the establishment of a user-friendly interface for program execution and debugging.



### 1.2.2 Scope

The project's scope includes the following key components:

- Design and Implementation of Minimal Assembly Language:

    - Creation of a minimal assembly language featuring essential instructions such as immediate value storage, register manipulation, memory access, conditional and unconditional jumps, subroutine handling, and fundamental arithmetic and logical operations.
- Development of C Program:

    - Implementation of a C program capable of interpreting and executing assembly programs.
    - Ensuring semantic validity and detecting syntactical errors in assembly programs.
- Virtual System Call:

    - Creation of a virtual system call for text display in a virtual terminal, accessible from assembly code.
- Debugger and Register Display:

    - Implementation of a built-in debugger within the C program.
    - Capability to display register contents during program execution.



### 1.2.3 Out of Scope

Certain aspects are explicitly excluded from the project's scope:

- External Libraries:

    - The project will not utilize external libraries beyond the C standard libraries.
- Tool Recommendations:

    - While gcc is recommended as the compiler and Visual Studio Code as the IDE, the project does not mandate exclusive use of these tools. Other compilers and IDEs are permissible.
- Platform-Specific Considerations:

    - Platform-specific considerations are considered out of scope, and the project does not delve into specific optimizations or features tailored to particular operating systems.
- Advanced Features:

    - Broader system-level optimizations or advanced features beyond the specified instructions are not within the project's defined boundaries. The focus is on the fundamental functionalities outlined in the assembly language and interpreter requirements.


## 1.3 Glossary


| Term                  | Definition                                                                                                                                                               |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Operand               | A value or data on which an operation is performed by an instruction in a computer program.                                                                              |
| Low-Level Language    | A programming language that provides minimal abstraction from the computer's architecture, often closely related to machine code.                                        |
| Virtual Processor     | A simulated or emulated computing unit that executes instructions in a virtual environment, mimicking the behavior of a physical processor.                              |
| Logical Operations    | Operations that manipulate binary values using logical operators like OR, AND, XOR, and NOT.                                                                             |
| Naming Convention     | A set of rules or guidelines for choosing the names of variables, functions, and other entities in a program to enhance readability and maintainability.                 |
| Immediate Value       | A constant value specified directly within the program's code rather than being loaded from memory, often used for quick data initialization or arithmetic operations.   |
| Compiler              | A program that translates high-level source code written in a programming language into machine code or an intermediate code.                                            |
| Debugger              | A tool or program used for identifying and fixing errors in software by allowing developers to inspect program state, set breakpoints, and step through code execution.  |
| C                     | A general-purpose, procedural programming language known for its efficiency and close-to-hardware capabilities.                                                          |
| System Call           | A request made by a program to the operating system or kernel for specific operating system services, often required for tasks like I/O operations or memory management. |
| Emulation             | The process of imitating the behavior of one system on another, allowing the second system to execute software or use peripheral devices designed for the first.         |
| Unit Tests            | Small, isolated tests designed to verify the correctness of individual units or components of a software system.                                                         |
| Operating System      | Software that manages computer hardware, software resources, and provides various services for computer programs.                                                        |
| Arithmetic Operations | Basic mathematical operations such as addition, subtraction, multiplication, and division.                                                                               |
| Visual Studio Code    | A source-code editor developed by Microsoft that provides support for various programming languages and features such as debugging and version control.                  |
| RAM                   | Random Access Memory, a type of computer memory that is used to store data that is being actively used or processed by a computer.                                       |
| Conditional Jump      | An instruction that causes the program to jump to a different section of code based on the evaluation of a specified condition.                                          |
| Register              | A small, high-speed storage location within the processor used for holding temporary data and operands during execution.                                                 |
| Syntactical Errors    | Mistakes in the structure or syntax of a program that violate the rules of the programming language, preventing successful compilation or interpretation.                |
| Interpreter           | A program that translates and executes high-level source code, typically line by line, without the need for a separate compilation step.                                 |
| GCC                   | GNU Compiler Collection, a set of compilers and tools for programming languages, including C.                                                                            |
| Instruction           | A basic operation or command in a computer program's machine language, typically representing a single operation of the processor.                                       |
| Subroutine            | A reusable and self-contained block of code that performs a specific task, often called by other parts of the program.                                                   |
| Semantic Validity     | The correctness of the meaning and intent of a program's code, ensuring that it adheres to the rules and logic of the programming language.                              |
|Chunk parsing          |Chunk parsingrefers to the process of dividing the binary data representing the assembly code into fixed-size chunks, typically 32 bits each. These chunks are then sequentially processed by the interpreter.                                                                                                                                                         |
|Memory allocation      |Memory allocation involves reserving and assigning memory space to store the instructions and associated data during the execution of the assembly code.                  |
|Tokenization           | Tokenization is the process of breaking down a sequence of characters or text into smaller meaningful units called tokens                                                |


## 1.4 Implementation 
    
### 1.4.1 Requirements

In order to successfully implement the virtual processor and assembly code interpreter, a set of hardware and software requirements must be satisfied. These requirements ensure a stable and efficient environment for the development and execution of the project.

#### 1.4.1.1 Hardware requirements

To run the virtual processor and assembly interpreter effectively, you need the following hardware specifications that are normally inside a computer :

- Processor: A modern multicore processor with sufficient computing power.
- Memory (RAM): A minimum of 8 GB RAM to support the execution of the virtual processor and interpreter.
- Storage: Adequate storage space for storing the project files and assembly programs.

#### 1.4.1.2 Software requirements
The software requirements are essential for creating, compiling, and executing the assembly code on the virtual processor. It is recommended to have the following software installed:

- **Operating System**: Any modern and widely-used operating system, such as Windows, Linux, or macOS.
- **C Compiler**: The project is developed in plain, portable C language, and a C compiler is necessary. [GCC](https://gcc.gnu.org/install/download.html) (GNU Compiler Collection) is recommended for this purpose.
Integrated 
- **Integrated Development Environment (IDE)**: [Visual Studio Code](https://code.visualstudio.com) is the recommended IDE for its features and ease of use.
  - It's important to ensure that the [C/C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp) extension is installed to enhance C/C++ development within Visual Studio Code. 


### 1.4.2 Setup and Installation

<br>

To set up the virtual processor interpreter on your local machine, please follow these steps:

<br>

1. Clone the Repository:
    - Open a terminal or Command Prompt on your machine.
    - Execute the following command to clone the repository:

```bash
git clone https://github.com/algosup/2023-2024-project-3-virtual-processor-team-6
```

<br>

2. Navigate to the Project Directory:
    - Move into the cloned repository directory:

```bash
cd 2023-2024-project-3-virtual-processor-team-6
```
<br>

3. Installation with Visual Studio Code:
    - Open Visual Studio Code on your Windows machine.
    - Click on "File" > "Clone Repository."
    - In the URL tab, enter the following URL:



```bash
https://github.com/algosup/2023-2024-project-3-virtual-processor-team-6.git
```

   - Click "Clone" and then navigate to "Repository" > "Open in Visual Studio Code." 

<br>

By following these steps, you will have successfully cloned the repository and set up the virtual processor project on your Windows machine using Visual Studio Code. Feel free to reach out if you encounter any issues or require further assistance.

<br>




### 1.4.3 Execution

After successfully installing the virtual processor interpreter on your Windows machine, follow these steps to execute the assembly programs:

1. Open Visual Studio Code:
    - Launch Visual Studio Code on your Windows machine.

<br>

2. Load Assembly Program:
    - Open the assembly program file (with a .asm extension) that you want to run using Visual Studio Code.

<br>

3. Run the Program:
    - Within Visual Studio Code, locate the "Run" or "Execute" option. This may be present in the toolbar or accessible through a specific command.

<br>


By following these steps, you can load and execute assembly programs within Visual Studio Code on your Windows environment. If you encounter any issues or have specific instructions for running programs, refer to the project documentation or seek guidance from our team.

<br>

# 2.Project Infrastructure


## 2.1 Directory and Naming Convention

The directory structure and naming conventions play a crucial role in maintaining a well-organized and easily navigable project. Adhering to consistent conventions ensures clarity and enhances collaboration among team members.

### 2.1.1 Directory Structure

The project directory should be organized logically, separating source code, documentation, and other relevant files. All the code will be written in C language and we will use the C18 standard.

### 2.1.2 Naming Conventions
Implementing and adhering to consistent naming conventions significantly enhances code readability and maintainability. The developers should adopt the following naming conventions:

- Files:

    - Use meaningful names for source code files, following a **camelCase or snake_case convention.**
    - Example: `virtualProcessor.c`, `assemblyInterpreter.h`

- Directories:

    - Use **lowercase letters and underscores** for directory names.
    - Example: `src/assembly`, `tests/unit_tests`
    - 
- Variables and Functions:

    - Use **camelCase** for variable and function names.
    - Example: `loadImmediateValue`, `executeInstruction`
  
- Constants:

    - Use **uppercase letters and underscores** for constant names.
    - Example: `MAX_MEMORY_SIZE`, `DEFAULT_TIMEOUT`
    - 
- Labels and Labels for Jumps:

    - Use **meaningful and descriptive labels** in assembly language.
    - Example: `start_loop`, `end_program`


<br>
By adhering to these directory and naming conventions, the project maintains a clean and organized structure, promoting collaboration and code clarity.


### 2.1.3 Formatting conventions 

Consistent code formatting is essential for improving code readability and maintaining a uniform coding style across the project. Adhering to a set of formatting conventions ensures that the codebase remains coherent and facilitates collaboration among team members.

### 2.1.3.1 Identation

We use indentation with **four spaces per level**. This allow us to avoid using tabs for indentation.

Example :
```c
void exampleFunction() {
    if (condition) {
        // Code block
        for (int i = 0; i < 5; ++i) {
            // ...
        }
    }
}
```

### 2.1.3.2 Braces

Place opening braces **on the same line as the statement or declaration they belong to**. Closing braces should be **on a new line, aligned with the corresponding opening brace**.

Example :
```c
void anotherFunction() {
    while (condition) {
        // Code block
        if (nestedCondition) {
            // ...
        }
    }
}
```

### 2.1.3.3 Line Length

Limit lines to a reasonable length (e.g., **80-120 characters**) to prevent horizontal scrolling and improve readability. Break long expressions or statements into multiple lines when necessary.

Example :

```c
int result = addNumbers(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
```

### 2.1.3.4 Blank Lines

Use blank lines to **separate logical sections** within functions or between different functions. This enhances visual clarity and organization.

Example:

```c
void functionOne() {
    //...

}


void functionTwo() {
    //...

}
```

### 2.1.3.5 Comments

Include descriptive comments to explain complex sections of code, provide context, or document the purpose of functions and variables. Follow a consistent style for comments, such as starting with **// for single-line comments** and using __/* */ for multi-line comments__.

Example:

```c
// This is a single-line comment

/*
 * This is a multi-line comment
 * providing additional details.
 */
 ```

## 2.2 Folder structure



 ## 2.3 Assembly Language Design
 
 ### 2.3.1 Storing an immediate Value Storage into a Register

Allows loading a constant value directly into a register, providing quick data initialization :

```asm
MOV R1, #10   ; Move the immediate value 10 into register R1
```

**Explanation** : The ``MOV`` (Move) instruction transfers the immediate value 10 into register ``R1``. This operation is useful for initializing registers with fixed values.

### 2.3.2 Register-to-Register Value Copying

Facilitates the transfer of data between registers, allowing for efficient data manipulation within the processor :

```asm
MOV R2, R1   ; Copy the content of register R1 into register R2
```

**Explanation** : The ``MOV`` instruction copies the content of register ``R1`` into register ``R2``. This operation is crucial for moving data between different registers.

### 2.3.3 Memory Value Read from the Address Stored in a Register

Involves reading a value from memory by accessing the location specified by the address stored in a register :

```asm
LDR R3, [R2]   ; Load the value from the memory address stored in register R2 into register R3
```

**Explanation** : The ``LDR`` (Load) instruction fetches the value from the memory address stored in register ``R2`` and loads it into register ``R3``. This operation is essential for reading data from specific memory locations.

### 2.3.4 Register Value Stored into Memory at the Address Contained in Another Register

Storing a register value into memory requires specifying both the source register containing the data and the destination address stored in another register :

```asm
STR R4, [R3]   ; Store the content of register R4 into the memory address stored in register R3
```

**Explanation** : The ``STR`` (Store) instruction writes the content of register ``R4`` into the memory address specified by register ``R3``. This operation is essential for updating values in memory.

### 2.3.4 Comparison of Register Contents 

The comparison instruction evaluates the contents of two registers, setting appropriate flags or status bits based on the result :

```asm
CMP R1, R2   ; Compare the contents of registers R1 and R2
```

**Explanation** : The ``CMP`` instruction compares the values in registers ``R1`` and ``R2``. The result influences subsequent conditional branching based on the comparison.

### 2.3.5 Unconditional Jump to a Label

Unconditional jumps enable altering the program flow without any condition. A label specifies the target location :

```asm
JMP start_loop   ; Unconditionally jump to the label 'start_loop'
```

**Explanation** : The ``JMP`` (Jump) instruction unconditionally transfers control to the label '``start_loop``'. This operation is useful for creating loops or redirecting program execution.


### 2.3.6 Conditional Jump Instructions

Conditional jumps provide flexibility based on the evaluation of specific conditions. The following instructions cover various conditions :

- Equal (``JE``):
```asm
JE equal_label   ; Jump to 'equal_label' if the previous comparison result indicates equality
```

- Not Equal (``JNE``):
```asm
JNE not_equal_label   ; Jump to 'not_equal_label' if the previous comparison result indicates inequality
```

- Jump if Less Than (``JL``):
```asm
JL less_than_label   ; Jump to 'less_than_label' if the value in the first register is less than the second
```

- Jump if Greater Than (``JG``):
```asm
JG greater_than_label   ; Jump to 'greater_than_label' if the value in the first register is greater than the second
```

- Greater Than or Equal To (``JGE``):
```asm
JGE greater_equal_label   ; Jump to 'greater_equal_label' if the value in the first register is greater than or equal to the second
```

- Less Than or Equal To (`JLE`):
```asm
JLE less_equal_label   ; Jump to 'less_equal_label' if the value in the first register is less than or equal to the second
```
- Jump if Not Zero (``JNZ``):
```asm
JNZ not_zero_label   ; Jump to 'not_zero_label' if the previous comparison result indicates a non-zero condition

```

- Jump if Zero (``JZ``):
```asm
JZ zero_label   ; Jump to 'zero_label' if the previous comparison result indicates a zero condition

```


- Jump if Not Greater Than or Equal To (``JNGE``):
```asm
JNGE not_greater_equal_label   ; Jump to 'not_greater_equal_label' if the value in the first register is not greater than or equal to the second
```

- Jump if Not Less Than or Equal To (``JNLE``):
```asm
JNLE not_less_equal_label   ; Jump to 'not_less_equal_label' if the value in the first register is not less than or equal to the second

```

**Explanation** : These conditional jump instructions evaluate specific conditions based on the result of the previous comparison. If the condition is met, they jump to the specified label.

### 2.3.7 Subroutine Call and Return:

Subroutine calls and returns support modular programming, allowing code reuse :

```asm
CALL subroutine   ; Call the subroutine at the 'subroutine' label
...
...
RET               ; Return from the subroutine
```

The ``CALL`` instruction invokes the subroutine at the '``subroutine``' label. The ``RET`` (Return) instruction later brings control back to the calling point.

### 2.3.8 Basic Arithmetic Operations: Addition, Subtraction, Multiplication, and Division:

Involves manipulating numeric values through basic arithmetic operations :

```asm
ADD R5, R3, R4   ; Add the contents of registers R3 and R4 and store the result in register R5

SUB R6, R1, R2   ; Subtract the contents of register R2 from R1 and store the result in register R6

MUL R7, R3, R4   ; Multiply the contents of registers R3 and R4 and store the result in register R7

DIV R8, R1, R2   ; Divide the contents of register R1 by R2 and store the result in register R8
```

**Explanation** : These arithmetic operations perform addition, subtraction, multiplication, and division, respectively. Each operation involves specified source and destination registers.

### 2.3.9 Basic Logical Operations: OR, AND, XOR, and NOT

Logical operations manipulate binary values, providing the foundation for Boolean algebra :

```asm
AND R9, R1, R2   ; Perform bitwise AND operation between registers R1 and R2, store result in R9

ORR R10, R3, R4  ; Perform bitwise OR operation between registers R3 and R4, store result in R10

EOR R11, R1, R2  ; Perform bitwise XOR operation between registers R1 and R2, store result in R11

MVN R12, R3      ; Perform bitwise NOT operation on register R3 and store the result in R12
```

**Explanation** :
- AND Operation (``AND``): Bitwise AND between the contents of registers R1 and R2. The result is stored in register R9.
  
- OR Operation (``ORR``): Bitwise OR between the contents of registers R3 and R4. The result is stored in register R10.
  
- XOR Operation (``EOR``): Bitwise XOR between the contents of registers R1 and R2. The result is stored in register R11.
  
- NOT Operation (``MVN``): Bitwise NOT on the contents of register R3. The result is stored in register R12.

**Additional Explanation** : Logical operations manipulate individual bits in binary representations.

- AND Operation (``AND``): Sets each bit to 1 if both corresponding bits of the operands are 1.
  
- OR Operation (``ORR``): Sets each bit to 1 if at least one corresponding bit of the operands is 1.
  
- XOR Operation (``EOR``): Sets each bit to 1 if the corresponding bits of the operands are different.
  
- NOT Operation (``MVN``): Flips each bit, changing 1s to 0s and vice versa




# dont forget to add our assembly language 

# 3.Technical specification

## 3.1 Interpreter 

An interpreter is a program that directly executes the instructions in a high-level language, without converting it into machine code. In programming, we can execute a program in two ways. Firstly, through compilation and secondly, through an interpreter. The common way is to use a compiler so that's what we gonna do.


### 3.1.1 Error Handling Mechanism

The interpreter component of the virtual processor is responsible for executing assembly language instructions and managing the execution flow. It comprises several key phases:


- Lexical Analysis: This initial phase involves tokenizing the assembly code, breaking it down into a sequence of lexemes or tokens, each representing a fundamental unit of the assembly language, such as instructions, labels, operands, and directives.

- Syntax Analysis: Following lexical analysis, the syntax analysis phase parses the tokenized assembly code to ensure it conforms to the grammar rules of the assembly language. This phase checks for syntactic correctness, including the proper arrangement of tokens and adherence to language syntax.

- Semantic Analysis: Semantic analysis focuses on validating the meaning and context of the assembly code. It verifies that the instructions and operands used in the code are semantically valid and compatible with the processor architecture.

- Execution Engine: Once the assembly code passes through the lexical, syntax, and semantic analysis phases, it enters the execution engine. Here, the interpreter sequentially executes each valid instruction, updating the processor state and memory as necessary. The execution engine also handles control flow instructions like jumps, calls, and returns.

- Output and Debugging: During execution, the interpreter generates output based on the program's behavior. This output may include the results of arithmetic or logical operations, intermediate values, or program status information. Additionally, the interpreter provides debugging information to assist developers in identifying and resolving issues in the assembly code.

#### 3.1.1.1 Technical Execution Process :

The execution process of the interpreter involves several steps:

1. Read Binary File: The interpreter starts by reading the binary file containing the assembly code instructions.

2. Chunk Parsing: It parses the binary data in fixed-size chunks, typically 32 bits each, corresponding to one instruction.

3. Memory Allocation: For each chunk, the interpreter allocates memory to store the instruction and its associated data.

4. Opcode Extraction: It extracts the opcode from the first segment of the chunk, determining the type of operation to perform.

5. Operand Parsing: Depending on the opcode, the interpreter parses the subsequent segments of the chunk to identify operands, such as registers, memory addresses, or immediate values.

6. Execution: With the opcode and operands identified, the interpreter executes the instruction accordingly. This involves performing arithmetic, logical, or control flow operations.

7. Looping: The interpreter repeats this process until it reaches the end of the binary file, processing each chunk sequentially.

In summary, the interpreter's comprehensive analysis and execution phases ensure the accurate and efficient execution of assembly code on the virtual processor, making it a critical component of the system.




```
Technical Execution Process
 _____________________________
|                             |
|   Read Binary File          |
|_____________________________|
              |
              v
 _____________________________
|                             |
|   Chunk Parsing              |
|_____________________________|
              |
              v
 _____________________________
|                             |
|   Memory Allocation         |
|_____________________________|
              |
              v
 _____________________________
|                             |
|   Opcode Extraction         |
|_____________________________|
              |
              v
 _____________________________
|                             |
|   Operand Parsing           |
|_____________________________|
              |
              v
 _____________________________
|                             |
|   Execution                 |
|_____________________________|
              |
              v
 _____________________________
|                             |
|   Looping                   |
|_____________________________|


```

#### 3.1.1.2 Error Handling
The interpreter incorporates robust error handling mechanisms to detect and report errors encountered during assembly code execution. Error handling includes the following stages:

1. Error Detection: The interpreter detects errors such as invalid syntax, semantic inconsistencies, or runtime issues during execution.

2. Error Reporting: When an error is detected, the interpreter generates informative error messages containing details about the error type, location, and potential causes.

3. Error Handling Module: An error handling module receives error messages from the interpreter and processes them accordingly. It may log errors to a file, display them in the user interface, or take other appropriate actions based on the severity and type of error.


#### 3.1.1.3 Output Handling
The interpreter generates output during execution, providing insights into the behavior of the assembly code. Output handling includes the following steps:

1. Execution Phase: During execution, the interpreter produces output based on the program's behavior, such as computed values, memory contents, or program status.

2. Output Generation: The interpreter formats and generates output based on the execution phase, presenting relevant information to the user or other components of the system.

3. Debugging Information: Alongside regular output, the interpreter may also provide debugging information to assist developers in understanding the program's behavior, identifying errors, and optimizing performance.

These textual descriptions complement the diagrams, providing a comprehensive overview of the interpreter's functionality and operation.

#### 3.1.1.4 Examples 

- Invalid Syntax Error:

    - Description: The interpreter encounters assembly code that does not conform to the syntax rules of the language.
    - Example: Missing operand in an instruction.
    - Error Message: "``SyntaxError: Missing operand at line 42.``"

- Semantic Error:

    - Description: The interpreter identifies an operation that is syntactically correct but semantically invalid or inconsistent.
    - Example: Trying to perform a division operation with a register containing zero.
    - Error Message: "``SemanticError: Division by zero at line 23.``"

- Runtime Error:

    - Description: An error occurs during the execution of the program due to unforeseen circumstances, such as accessing an invalid memory address or attempting an unsupported operation.
    - Example: Attempting to access memory beyond the allocated space.
    - Error Message: "``RuntimeError: Invalid memory access at address 0x12345678.``"

- File I/O Error:

     -Description: An error occurs while attempting to read or write to a file, such as a missing file or insufficient permissions.
     -Example: Trying to open a nonexistent binary file.
    - Error Message: "``FileIOError: Unable to open file 'program.bin' for reading.``"

- Invalid Instruction Error:

    - Description: The interpreter encounters an opcode that is not recognized or supported by the processor architecture.
    - Example: Encountering an unknown opcode during opcode extraction.
    - Error Message: "``InvalidInstructionError: Unsupported opcode '0xFF' at line 10.``"

- Memory Allocation Error:

    - Description: The interpreter fails to allocate memory for storing instructions or data.
    - Example: Insufficient memory available for allocating a new chunk.
    - Error Message: "``MemoryAllocationError: Unable to allocate memory for new chunk.``"

These examples demonstrate various types of errors that the interpreter might encounter during execution. Each error is accompanied by an informative error message indicating the type of error and its location within the code, facilitating debugging and troubleshooting.


## 3.2 Assembler 

### 3.2.1 Assembler Functionality

### 3.2.1.1 Parsing
The parsing stage of the assembler involves breaking down the input assembly code into meaningful tokens such as instructions, operands, labels, and comments. This process includes:

- Tokenization: Breaking the input text into tokens based on whitespace and delimiters.

- Identification of Instructions: Recognizing mnemonic instructions and validating their correctness.
  
- Operand Parsing: Identifying and parsing operands, which may include registers, memory addresses, immediate values, or labels.
  
- Label Detection: Identifying labels and associating them with memory addresses.

### 3.2.1.2 Symbol Table
The assembler maintains a symbol table to manage labels and their corresponding memory addresses. Key functionalities include:

- Symbol Insertion: Storing labels along with their memory addresses in the symbol table.

- Symbol Resolution: Resolving symbolic references to memory addresses during translation.

- Error Handling: Detecting duplicate labels or conflicting symbols and reporting errors accordingly.

### 3.2.1.3 Translation

The translation stage involves converting assembly instructions into machine code. This process includes:

- Opcode Generation: Mapping mnemonic instructions to their corresponding machine code representations.

- Operand Encoding: Encoding operands according to the instruction format and addressing modes.

- Symbol Resolution: Resolving symbolic references to memory addresses using the symbol table.

- Output Generation: Generating machine code output for each instruction.

### 3.2.1.4 Error Handling

The assembler performs comprehensive error handling to detect and report syntax errors, semantic errors, and other issues. Key functionalities include:

- __Syntax Error Detection__ : Identifying syntax errors such as invalid instructions, missing operands, or incorrect syntax.
  
Example :

```bash
Input Assembly Code:
MOV R1, R2  # Missing operand
```
Error Message:

```mathematica
Syntax Error: Missing operand for MOV instruction at line 1
```
<br>

- __Semantic Error Detection__: Detecting semantic errors such as invalid operand types or conflicting symbols.
  
Example :
```bash
Input Assembly Code:
ADD R1, #5  # Operand type mismatch
```

Error message :

```mathematica
Semantic Error: Invalid operand type for ADD instruction at line 1
```
<br>

- __Error Reporting__: Providing informative error messages indicating the nature and location of the error to aid debugging.


Example :
```bash
Input Assembly Code:
DIV R1, R2  # Division by zero
```

Error message : 

```mathematica
Error: Division by zero detected at line 1
```
<br>

- __Graceful Recovery__: Attempting to recover from errors to continue processing subsequent instructions if possible.
  
Example : 

```bash
Input Assembly Code:
MOV R1, R2
ADD R1, #5  # Invalid instruction
MOV R2, #10
```

Error message :

```mathematica
Error: Invalid instruction detected at line 2
```
In this example, the interpreter detects an invalid instruction at line 2. Despite the error, it gracefully recovers by continuing to process subsequent instructions. Therefore, the execution of the remaining valid instructions (MOV R2, #10) can proceed without interruption...

### 3.2.1.5 Optimization (Optional)

Optionally, the assembler may include optimization techniques to improve the efficiency of generated machine code. This could involve instruction reordering, constant folding, or other optimizations to enhance performance...