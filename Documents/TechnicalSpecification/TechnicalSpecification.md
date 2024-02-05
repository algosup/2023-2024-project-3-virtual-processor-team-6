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

<br>

# Table of Contents

- [Technical specification | team 6](#technical-specification--team-6)
- [Table of Contents](#table-of-contents)
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
  - [2.1 Folder structure](#21-folder-structure)
  - [2.2 Directory and Naming Convention](#22-directory-and-naming-convention)
    - [2.2.1 Directory Structure](#221-directory-structure)
    - [2.2.2 Naming Conventions](#222-naming-conventions)
    - [2.2.3 Formatting conventions](#223-formatting-conventions)
    - [2.2.3.1 Identation](#2231-identation)
    - [2.2.3.2 Braces](#2232-braces)
    - [2.2.3.3 Line Length](#2233-line-length)
    - [2.2.3.4 Blank Lines](#2234-blank-lines)
    - [2.2.3.5 Comments](#2235-comments)
  - [2.3 Assembly Language Design](#23-assembly-language-design)
    - [2.3.1 Immediate Value Storage into a Register](#231-immediate-value-storage-into-a-register)
    - [2.3.2 Register-to-Register Value Copying](#232-register-to-register-value-copying)
    - [2.3.3 Memory Value Read from the Address Stored in a Register](#233-memory-value-read-from-the-address-stored-in-a-register)
    - [2.3.4 Register Value Stored into Memory at the Address Contained in Another Register](#234-register-value-stored-into-memory-at-the-address-contained-in-another-register)
    - [2.3.4 Comparison of Register Contents](#234-comparison-of-register-contents)
    - [2.3.5 Unconditional Jump to a Label](#235-unconditional-jump-to-a-label)
    - [2.3.6 Conditional Jump Instructions](#236-conditional-jump-instructions)
    - [2.3.7 Subroutine Call and Return:](#237-subroutine-call-and-return)
    - [2.3.8 Basic Arithmetic Operations: Addition, Subtraction, Multiplication, and Division:](#238-basic-arithmetic-operations-addition-subtraction-multiplication-and-division)
    - [2.3.9 Basic Logical Operations: OR, AND, XOR, and NOT](#239-basic-logical-operations-or-and-xor-and-not)




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
- **Integrated Development Environment (IDE)**: __Visual Studio Code__ is the recommended IDE for its features and ease of use.
  - It's important to ensure that the __C/C++ for Visual Studio Code__ extension is installed to enhance C/C++ development within Visual Studio Code. 


### 1.4.2 Setup and Installation

(to do)

### 1.4.3 Execution

(to do )

# 2.Project Infrastructure

## 2.1 Folder structure

## 2.2 Directory and Naming Convention

The directory structure and naming conventions play a crucial role in maintaining a well-organized and easily navigable project. Adhering to consistent conventions ensures clarity and enhances collaboration among team members.

### 2.2.1 Directory Structure

The project directory should be organized logically, separating source code, documentation, and other relevant files. All the code will be written in C language and we will use the C18 standard.

### 2.2.2 Naming Conventions
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

### 2.2.3 Formatting conventions 

Consistent code formatting is essential for improving code readability and maintaining a uniform coding style across the project. Adhering to a set of formatting conventions ensures that the codebase remains coherent and facilitates collaboration among team members.

### 2.2.3.1 Identation

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

### 2.2.3.2 Braces

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

### 2.2.3.3 Line Length

Limit lines to a reasonable length (e.g., **80-120 characters**) to prevent horizontal scrolling and improve readability. Break long expressions or statements into multiple lines when necessary.

Example :

```c
int result = addNumbers(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
```

### 2.2.3.4 Blank Lines

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

### 2.2.3.5 Comments

Include descriptive comments to explain complex sections of code, provide context, or document the purpose of functions and variables. Follow a consistent style for comments, such as starting with **// for single-line comments** and using __/* */ for multi-line comments__.

Example:

```c
// This is a single-line comment

/*
 * This is a multi-line comment
 * providing additional details.
 */
 ```

 ## 2.3 Assembly Language Design
 
 ### 2.3.1 Immediate Value Storage into a Register

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



