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

### 1.1 Document information 

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
| "Language" | | 
| "Assembly" | Low-level language for direct processor programming. |
| "C" | The C language is a high-level, efficient and portable programming language, originally developed for UNIX. |
| "Virtual Processor" | The term "virtual processor" refers to a simulated processing unit in a virtualized computing environment. |
| "IDE" | An IDE (Integrated Development Environment) combines code editing, compilation, and debugging tools in a single interface for efficient development. |
| "GCC" | GCC, or GNU Compiler Collection, is a set of open-source compilers for various languages, providing cross-platform compatibility and code optimization. |
| "Register"| |
| "Label" | | 

### 2.2 Project Overview 

Our team was tasked with creating a virtual
processor and an interpreter for running assembly
code on that processor.

### 2.3 Project Definition. 

The project involves creating a virtual processor
and an interpreter to run assembly code on that
processor. The development will be in plain,
portable C language, utilizing only C standard
libraries and avoiding external libraries. The
recommended tools include using gcc as a compiler
and Visual Studio Code as the IDE.

- #### Goals of this Project
    
    The primary goal of our team for this project
    is to design, implement, and deliver a virtual
    processor in the C programming language capable
    of interpreting and executing assembly language
    instructions. The virtual processor should
    emulate key functionalities of a physical
    processor, including the execution of
    arithmetic operations, data transfers, jumps,
    and effective management of registers and
    virtual memory.

- #### Our objectives
    
    <b>Assembly Language Support:</b>

    Develop a virtual processor that supports a
    specific subset of the assembly language, with
    a focus on essential instructions commonly used
    in low-level programming.

    <b>Execution Accuracy:</b>

    Ensure the virtual processor accurately
    interprets and executes assembly language
    instructions, maintaining compatibility with
    established conventions and standards.

    <b>User Interface:</b>

    Implement a command-line interface (CLI) to
    facilitate user interaction, allowing for the
    loading, execution of assembly programs. The
    CLI should provide relevant information about
    the processor's state and memory usage.

    <b>Register and Memory Management:</b>

    Design the virtual processor to effectively
    manage registers for temporary data storage and
    intermediate results. Simulate virtual memory
    to store program instructions and data, with
    the capability to load and save programs.

    <b>Interrupt Handling:</b>

    Implement a mechanism for handling
    interruptions, encompassing both software and
    hardware interruptions. The virtual processor
    should respond appropriately to interrupt
    signals.

    <b>Performance and Portability:</b>

    Achieve acceptable performance for the execution of moderate-sized assembly programs. Ensure the source code's portability, allowing compatibility with various operating systems.

    <b>Security Measures:</b>

    Incorporate security measures to prevent buffer overflow attacks and ensure the secure execution of programs. Ensure proper isolation between different executing processes.

### 2.4 Project Roles 

As defined by the project owner (ALGOSUP), the team is arranged in the following way :

| Role | Description | Name |
|---|---|---|
| Project Manager | Is in charge of organization, planing and budgeting.<br>Keep the team motivated.  | Michel Riff |
| Program Manager | Makes sure the project meets expectation.<br>Is in charge of design.<br>Is responsible for writing the Functional Specifications | Raphaël Descamps |
| Tech Lead | Makes the technical decision in the project.<br>Translates the Functional Specification into Technical Specifications.<br> Does code review. | Habi Cailleau |
| Software Engineer | Writes the code.<br>Writes documentation<br>Participate in the technical design. | Lucas Aubard |
| Software Engineer | Writes the code.<br>Writes documentation<br>Participate in the technical  | Vivien Bistrel Tsangue |
| Quality Assurance |  Tests all the functionalities of a product to find bugs and issue.<br>Document bugs and issues.<br>Write the test plan.<br>Check that issues have been fixed.| Loris De Mattia Segalata |


<br></br>

### 2.5 StakeHolders 

| Stakeholder | Might have/find an interest in... |
|---|---|
| Franck JEANNIN | Having the student learn assembly and C  |
| ALGOSUP Students | Learning assembly and getting experience about programming |

### 2.6 Project Plan 
 
Milestone :  

 <img src="../FunctionalSpecification/Pictures/Milestone.png" alt="a yellow ball with a mouth">

<br></br>

Assumptions/Constraints : 

| Assumptions |
|---|
|  |
|  |
|  |

| Constraints |
|---|
| We have to code in C |
|  |
|  |

<br></br> 

## 4. Functional Requirements 

### 4.1 Virtual Processor and languages Overview 

#### 4.1.2 Context : 

The idea of creating a virtual processor dates back
to the early days of computing when researchers and
developers sought ways to simulate the behavior of
a real processor in a controlled environment. The
initial emulations of processors were developed to
test software on different hardware architectures
without the need for physical access to each type
of processor.

The need for virtual processors became more
pronounced with the evolution of computer
architectures and the emergence of distributed
systems, virtual machines, and isolated execution
environments.


#### 4.1.3 Assembly Language : 

Assembly language, often referred to as assembly
code, is a low-level language specific to a
particular hardware architecture. Each assembly
language instruction typically corresponds to a
machine instruction, making it conducive to direct
programming of the processor. Programmers use
assembly language to write more efficient programs
by fully leveraging the hardware's capabilities.

However, assembly language can be challenging to
learn and maintain due to its close connection to
the underlying hardware architecture. Nevertheless,
it provides precise control over the hardware,
making it essential for developing embedded
systems, device drivers, and other low-level
software.

#### 4.1.4 C Language : 

The C language, created by Dennis Ritchie in the
early 1970s, is a higher-level programming language
compared to assembly language. It offers a higher
level of abstraction from the hardware, allowing
programmers to write portable and easily
understandable code while maintaining efficiency
close to that of assembly language.

It is an imperative and procedural language,
providing features such as memory management
through pointers, bit manipulation, and the ability
to code critical portions in assembly language for
fine optimization.

#### 4.1.3 Our Assembly Language 

| Instruction | Objective | 
|---|---|
| "ADD" | Takes two numbers, adds them together and stores the result in a register. |
| "AND" | |

### 4.2 Virtual processor

#### 4.2.1 Instruction Set

Let's define a solid set of assembly instructions
that our virtual processor will comprehend. We need
the basics – arithmetic operations, logical
maneuvers, and instructions to shuffle data in and
out of memory. Essentially, anything fundamental
for a processor to do its job.

#### 4.2.2 Register File

Our processor needs a set of internal registers to
keep things organized during computation. Let's lay
out the purpose and limits of each register, like a
choreography for our processor dance.

#### 4.2.3 Instruction Execution

Imagine each assembly instruction as a script. We
need to decide how our virtual processor reads,
understands, and acts upon these scripts. So, let’s
outline the steps for fetching, decoding, and
executing each instruction. It's like teaching our
processor a well-rehearsed routine.

#### 4.2.4 Memory

Our processor needs a memory system – a mental
space to store data and instructions. Let's sketch
out how this memory works: the addressing method,
its size, and the steps for loading and storing
data. It's like building a mental filing cabinet
for our processor's thoughts.

#### 4.2.5 Interrupts

Sometimes our processor needs to take a break for
important tasks – that's where interrupts come in.
Let's design a system for managing these
interruptions, deciding their types, priority, and
how our processor responds when it gets a tap on
the virtual shoulder.

### 4.4 Assembly interpreter

### 4.5 User Interface (Optional)

### 4.6 Technical constraints

## 5. Non Functional Requirement