# Functional Specifiactions | Team 6 

---

<br>
<details>
<summary> Table of content </summary>

- [Functional Specifications | Team 6]
(#functional-specifications--team-4)
    - [Table of content](#Table of content)
    

</details>
</br>

---
## 1. Document handling 
| Document Type | Specification |
|---|---|
| Document Owner | Raphaël Descamps |
| Issue date | 30/01/2024 |
| Document Name | Functional-Specification|


### 1.2 Document Approval

| Role | Name | Signature | Date |
|---|---|---|---|
| Project Manager | Michelle Riff | ✅ | 30/01/2023 |
| Program Manager | Raphaël Descamps| ✅ |30/01/2023 |
| Tech Lead | Habi Cailleau | ✅ | 11/13/2023 |
| Software Developer | Lucas Aubard | ✅ | 30/01/2023 |
| Software Developer | Vivien Bistrel Tsangue |✅ | 30/01/2023|
| Quality Assurance | Loris De Mattia Segalat | ✅ | 30/01/2023 |


## 2. Introduction

### 2.1 Glossary

| Term used | Definition |
|---|---|
| "Team" | ALGOSUP team 6 (2023-2024 - Project 3) |
| "Assembly" | Low-level language for direct processor programming. |
| "C" | Le langage C est un langage de programmation haut niveau, efficace et portable, initialement développé pour UNIX. |
| "Virtual Processor" | Le terme "virtual processor" fait référence à une unité de traitement simulée dans un environnement informatique virtualisé. |


### 2.2 Goals of this Project
The primary goal of this project is to design, implement, and deliver a virtual processor in the C programming language capable of interpreting and executing assembly language instructions. The virtual processor should emulate key functionalities of a physical processor, including the execution of arithmetic operations, data transfers, jumps, and effective management of registers and virtual memory.

### 2.3 Our objectives

<b>Assembly Language Support:</b>

Develop a virtual processor that supports a specific subset of the assembly language, with a focus on essential instructions commonly used in low-level programming.

<b>Execution Accuracy:</b>

Ensure the virtual processor accurately interprets and executes assembly language instructions, maintaining compatibility with established conventions and standards.

<b>User Interface:</b>

Implement a command-line interface (CLI) to facilitate user interaction, allowing for the loading, execution, and debugging of assembly programs. The CLI should provide relevant information about the processor's state and memory usage.

<b>Register and Memory Management:</b>

Design the virtual processor to effectively manage registers for temporary data storage and intermediate results. Simulate virtual memory to store program instructions and data, with the capability to load and save programs.

<b>Interrupt Handling:</b>

Implement a robust mechanism for handling interruptions, encompassing both software and hardware interruptions. The virtual processor should respond appropriately to interrupt signals.

<b>Performance and Portability:</b>

Achieve acceptable performance for the execution of moderate-sized assembly programs. Ensure the source code's portability, allowing compatibility with various operating systems.

<b>Extensibility:</b>

Design the virtual processor to be extensible, allowing for the straightforward addition of new instructions and features as needed.

<b>Security Measures:</b>

Incorporate security measures to prevent buffer overflow attacks and ensure the secure execution of programs. Ensure proper isolation between different executing processes.

## 3. Key Features

### 3.1 Execution of Assembly Instructions
The virtual processor must be capable of reading, interpreting, and executing assembly instructions. Supported instructions include, but are not limited to, arithmetic operations, data transfers, conditional and unconditional jumps.

### 2.2 Register Management
The virtual processor must include a set of registers to store temporary data and intermediate results. Register management should adhere to the standard calling convention.

### 2.3 Virtual Memory
The virtual processor must simulate virtual memory for storing program instructions and data. It should be capable of loading and saving programs to and from memory.

### 2.4 Interrupt Handling
The virtual processor should handle interruptions, including both software and hardware interruptions. It must appropriately respond to interrupt signals.

## 3. User Interface

### 3.1 Supported Assembly Language
The virtual processor must support a specific subset of the assembly language. Detailed documentation for this assembly language must be provided.

### 3.2 Command-Line Interface (CLI)
The virtual processor should have a command-line interface allowing users to load, execute, and debug assembly programs. This interface should also provide information about the processor and memory state.

## 4. Non-Functional Requirements

### 4.1 Performance
The virtual processor should achieve acceptable performance for the execution of moderate-sized assembly programs.

### 4.2 Portability
The source code of the virtual processor should be portable and compatible with different operating systems.

### 4.3 Extensibility
The virtual processor should be designed to facilitate the addition of new instructions and features.

## 5. Security Requirements

### 5.1 Buffer Overflow Prevention
The virtual processor should be designed to prevent buffer overflow attacks and ensure the security of program execution.

### 5.2 Process Isolation
The virtual processor should ensure proper isolation between different executing processes.
