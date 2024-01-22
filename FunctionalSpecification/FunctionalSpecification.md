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

### 2.1 Objective
This document outlines the functional specifications of a virtual processor in C capable of reading and executing assembly instructions.

### 1.2 Context
The virtual processor aims to provide an environment for the execution of programs written in assembly language, while emulating the key features of a physical processor.

## 2. Key Features

### 2.1 Execution of Assembly Instructions
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
