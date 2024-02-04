# Technical specification | team 6 

<br>

| Document Type | Specification |
|---|---|
| Document Owner | Habi CAILLEAU |
| Issue date | 09/02/2024 |
| Document Name | Technical Specification|

<br>

| Role | Name | Signature | Date |
|---|---|---|---|
| Project Manager | Michel Riff |  | 30/01/2024 |
| Program Manager | Raphaël Descamps|  |30/01/2024 |
| Tech Lead | Habi Cailleau | ✅ | 30/01/2024 |
| Software Developer | Lucas Aubard |  | 30/01/2024 |
| Software Developer | Vivien Bistrel Tsangue | | 30/01/2024|
| Quality Assurance | Loris De Mattia Segalat |  | 30/01/2024 |

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


| Term                     | Definition                                                                                                                                                          |
|--------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Operand                  | A value or data on which an operation is performed by an instruction in a computer program.                                                                           |
| Low-Level Language        | A programming language that provides minimal abstraction from the computer's architecture, often closely related to machine code.                                   |
| Virtual Processor        | A simulated or emulated computing unit that executes instructions in a virtual environment, mimicking the behavior of a physical processor.                       |
| Logical Operations       | Operations that manipulate binary values using logical operators like OR, AND, XOR, and NOT.                                                                         |
| Naming Convention        | A set of rules or guidelines for choosing the names of variables, functions, and other entities in a program to enhance readability and maintainability.            |
| Immediate Value           | A constant value specified directly within the program's code rather than being loaded from memory, often used for quick data initialization or arithmetic operations.|
| Compiler                 | A program that translates high-level source code written in a programming language into machine code or an intermediate code.                                          |
| Debugger                 | A tool or program used for identifying and fixing errors in software by allowing developers to inspect program state, set breakpoints, and step through code execution.|
| C                        | A general-purpose, procedural programming language known for its efficiency and close-to-hardware capabilities.                                                    |
| System Call               | A request made by a program to the operating system or kernel for specific operating system services, often required for tasks like I/O operations or memory management. |
| Emulation                | The process of imitating the behavior of one system on another, allowing the second system to execute software or use peripheral devices designed for the first.|
| Unit Tests               | Small, isolated tests designed to verify the correctness of individual units or components of a software system.                                                     |
| Operating System         | Software that manages computer hardware, software resources, and provides various services for computer programs.                                                    |
| Arithmetic Operations    | Basic mathematical operations such as addition, subtraction, multiplication, and division.                                                                          |
| Visual Studio Code       | A source-code editor developed by Microsoft that provides support for various programming languages and features such as debugging and version control.            |
| RAM                      | Random Access Memory, a type of computer memory that is used to store data that is being actively used or processed by a computer.                                     |
| Conditional Jump         | An instruction that causes the program to jump to a different section of code based on the evaluation of a specified condition.                                      |
| Register                 | A small, high-speed storage location within the processor used for holding temporary data and operands during execution.                                               |
| Syntactical Errors        | Mistakes in the structure or syntax of a program that violate the rules of the programming language, preventing successful compilation or interpretation.             |
| Interpreter              | A program that translates and executes high-level source code, typically line by line, without the need for a separate compilation step.                           |
| GCC                      | GNU Compiler Collection, a set of compilers and tools for programming languages, including C.                                                                      |
| Instruction              | A basic operation or command in a computer program's machine language, typically representing a single operation of the processor.                                    |
| Subroutine               | A reusable and self-contained block of code that performs a specific task, often called by other parts of the program.                                                 |
| Semantic Validity         | The correctness of the meaning and intent of a program's code, ensuring that it adheres to the rules and logic of the programming language.                          |





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
- **C Compiler**: The project is developed in plain, portable C language, and a C compiler is necessary. __GCC__ (GNU Compiler Collection) is recommended for this purpose.
Integrated 
- **Integrated Development Environment (IDE)**: __Visual Studio Code__ is the recommended IDE for its features and ease of use.
  - It's important to ensure that the __C/C++ for Visual Studio Code__ extension is installed to enhance C/C++ development within Visual Studio Code. 


### 1.4.2 Setup and Installation

(to do)

### 1.4.3 Execution

(to do )

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

### 2.3.2.2 Braces

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

### 2.3.2.3 Line Length

Limit lines to a reasonable length (e.g., **80-120 characters**) to prevent horizontal scrolling and improve readability. Break long expressions or statements into multiple lines when necessary.

Example :

```c
int result = addNumbers(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
```

### 2.3.2.4 Blank Lines

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

### 2.3.2.5 Comments

Include descriptive comments to explain complex sections of code, provide context, or document the purpose of functions and variables. Follow a consistent style for comments, such as starting with **// for single-line comments** and using __/* */ for multi-line comments__.

Example:

```c
// This is a single-line comment

/*
 * This is a multi-line comment
 * providing additional details.
 */
 ```