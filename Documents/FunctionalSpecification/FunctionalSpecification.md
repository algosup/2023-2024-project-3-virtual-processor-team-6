# Functional Specifiactions | Team 6 

<br>
<details>
<summary> Table of Contents </summary>

- [Functional Specifiactions | Team 6](#functional-specifiactions--team-6)
  - [1. Document handling](#1-document-handling)
    - [1.1 Document information](#11-document-information)
    - [1.2 Document Approval](#12-document-approval)
  - [2. Introduction](#2-introduction)
    - [2.1 Glossary](#21-glossary)
    - [2.2 Project Overview](#22-project-overview)
    - [2.3 Project Definition.](#23-project-definition)
      - [2.3.1 Goals of this Project](#231-goals-of-this-project)
      - [2.3.2 Our objectives](#232-our-objectives)
    - [2.4 Project Roles](#24-project-roles)
    - [2.5 Project Representatives](#25-project-representatives)
    - [2.7 Project Plan](#27-project-plan)
      - [2.7.1 Retro Planning](#271-retro-planning)
      - [2.7.2 Milestone](#272-milestone)
      - [2.7.3 Porject Constraints](#273-porject-constraints)
  - [3. Functional Requirements](#3-functional-requirements)
    - [3.1 Virtual Processor and languages Overview](#31-virtual-processor-and-languages-overview)
      - [3.1.2 Context](#312-context)
      - [3.1.3 Assembly Language](#313-assembly-language)
      - [3.1.4 C Language](#314-c-language)
      - [3.1.3 Our Assembly Language](#313-our-assembly-language)
      - [3.1.4 Characteristic Syntax](#314-characteristic-syntax)
    - [3.2 Virtual processor](#32-virtual-processor)
      - [3.2.1 Instruction Set](#321-instruction-set)
      - [3.2.2 Register](#322-register)
      - [3.2.3 Instruction Execution](#323-instruction-execution)
      - [3.2.4 Memory](#324-memory)
      - [3.2.5 Interrupts](#325-interrupts)
    - [3.3 Interpréteur d'Assembleur](#33-interpréteur-dassembleur)
      - [3.3.1 Analyse Syntaxique](#331-analyse-syntaxique)
      - [3.3.2 Exécution](#332-exécution)
      - [3.3.3 Gestion des Erreurs](#333-gestion-des-erreurs)
    - [3.4 User Interface](#34-user-interface)
      - [3.4.1 Assembly Language Program Input](#341-assembly-language-program-input)
        - [Example Assembly Program File:](#example-assembly-program-file)
      - [3.4.2 Runtime Display](#342-runtime-display)
      - [3.4.3 Error Handling](#343-error-handling)
  - [4. Non Functional Requirement](#4-non-functional-requirement)

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
| "Language" | A set of symbols and rules for instructing computers. | 
| "Assembly" | Low-level language for direct processor programming. |
| "C" | The C language is a high-level, efficient and portable programming language, originally developed for UNIX. |
| "Virtual Processor" | The term "virtual processor" refers to a simulated processing unit in a virtualized computing environment. |
| "IDE" | An IDE (Integrated Development Environment) combines code editing, compilation, and debugging tools in a single interface for efficient development. |
| "GCC" | GCC, or GNU Compiler Collection, is a set of open-source compilers for various languages, providing cross-platform compatibility and code optimization. |
| "Register"     | A small, fast storage location in the CPU for temporary data and quick operations. |
| "Label"        | A symbolic name in code used to mark positions, often the target of jumps or branches. |
| "Interpreter"  | A program that directly executes code without prior compilation, translating and executing it line by line. |
| "IP" | Instruction Pointer, a register that holds the memory address of the next instruction to be executed. |
| "SP" | Stack Pointer, a register that holds the memory address of the top of the stack. |
| "LR" | Link Register, a register used to store the return address when calling subroutines or functions. |
| "PC" | Program Counter, a register that holds the memory address of the current instruction being executed. |

### 2.2 Project Overview 

Our team was tasked with creating a virtual
processor and an interpreter for running and interpreting an assembly code on that virtual processor. Also creating a virtual system in order to see that the assembly program is actually running, and displaying text in a virtual terminal, that can be accessed from the assembly code.

### 2.3 Project Definition. 

The project involves creating a virtual processor
and an interpreter to run and interprete an assembly code. The development will be in plain, portable C language, utilizing only C standard libraries and avoiding external libraries. The
recommended tools include using gcc as a compiler
and Visual Studio Code as the IDE.

#### 2.3.1 Goals of this Project
    
The primary goal of our team for this project is to have a meeting with the team members to invent assembly instructions and discuss how we are going to implement them.

Secondly, we have to write all the documents, both functional specification and technical specification. We also need to delve into the project's phase.

Thirdly, we enter the implementation phase of the project.

Fourthly, we have to test all the different functions of the implemented code and compare with the desired results.

Finally, make sure that the code works properly and deliver the project on time

####  2.3.2 Our objectives
    
<b>Assembly Language Support:</b>

Develop a virtual processor that supports a simple assembly language, with a focus on essential instructions commonly used in low-level programming.

<b>Interpreter: </b>

The interpreter will return error messages find out during execution, for example, if there is an error at the level “add: R1 ” Here we can see that we will have an error as we just having a single register that is the destination register as such the interpreter will send an error message specifying at what line we have an error

<b>Execution Accuracy:</b>

Ensure the virtual processor accurately
interprets and executes assembly language instructions, maintaining compatibility with established conventions and standards.

<b>User Interface:</b>

Implement an virtual system to facilitate user interaction, allowing for the
loading, execution of assembly programs. The virtual system should provide relevant information about the assembly .

<b> Architecture: </b>

Architecture: To implement our assembly code, we will inspire ourselves from the ARM 16-bit architecture and the LC3 architecture 16-bit too, as both of them are closely similar in their implementation.

<b>Register and Memory Management:</b>

Design the virtual processor to effectively manage registers for temporary data storage and
intermediate results in 16 bits. Store and Load, jump, call, copy, compute operations, and compare program instructions and data.

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

As defined by the project owner (ALGOSUP), the team is organized in the following way :

| Role | Description | Name |
|---|---|---|
| Project Manager | Is in charge of organization, planing and budgeting.<br>Keep the team motivated.  | Michel Riff |
| Program Manager | Makes sure the project meets expectation.<br>Is in charge of design.<br>Is responsible for writing the Functional Specifications | Raphaël Descamps |
| Tech Lead | Makes the technical decision in the project.<br>Translates the Functional Specification into Technical Specifications.<br> Does code review. | Habi Cailleau |
| Software Engineer | Writes the code.<br>Writes documentation<br>Participate in the technical design. | Lucas Aubard |
| Software Engineer | Writes the code.<br>Writes documentation<br>Participate in the technical  | Vivien Bistrel Tsangue |
| Quality Assurance |  Tests all the functionalities of a product to find bugs and issue.<br>Document bugs and issues.<br>Write the test plan.<br>Check that issues have been fixed.| Loris De Mattia Segalata |

### 2.5 Project Representatives

### 2.7 Project Plan 

#### 2.7.1 Retro Planning  

<img src="../FunctionalSpecification/Pictures/RetroPlanning.png" alt="a yellow ball with a mouth">
 
#### 2.7.2 Milestone   

<img src="../FunctionalSpecification/Pictures/Milestone.png" alt="a yellow ball with a mouth">

<br></br>

#### 2.7.3 Porject Constraints

| Constraints |
|---|
| We have to code in C. |
| We can't use any external library beside C standard libraries. |
| We have to create an assembly with basic instructions. |

<br></br> 

## 3. Functional Requirements 

### 3.1 Virtual Processor and languages Overview 

#### 3.1.2 Context  

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


#### 3.1.3 Assembly Language  

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

#### 3.1.4 C Language  

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

#### 3.1.3 Our Assembly Language 

| Instruction | Objective | 
|---|---|
| "ADD" | Takes two numbers, adds them together and stores the result in a register. |
| **"SUB"** |Subtracts the second number from the first and stores the result in a register.|
| **"DIV"** |Divides the first number by the second and stores the result in a register.|
| **"MUL"** |Multiplies two numbers and stores the result in a register.|
| **"CPY"** |Copies the value from one register to another.|
| **"CMP"** |Compares two numbers and sets flags in the status register based on the result.|
| **"OR"** | Performs a bitwise OR operation on two numbers and stores the result in a register.|
| **"XOR"** |Performs a bitwise XOR operation on two numbers and stores the result in a register.|
| **"JMP"** |Jumps to a specified memory address or label.|
| **"NOR"** |Performs a bitwise NOR operation on two numbers and stores the result in a register.|
| **"LOAD"** | Loads a value from memory into a register.|
| **"STORE"** |Stores the value from a register into memory.|
| **"JE"** |Jumps to a specified memory address or label if the result of the last comparison was equal.|
| **"CALL"** |Calls a subroutine or function at a specified memory address.| 
| **"RET"** | Returns from a subroutine or function.|

Voici ci-dessus toutes les instructions que notre assembly sera composé. Ce sont les instructions basique de l'assembly normal. 

#### 3.1.4 Characteristic Syntax 

Here is an example of what should be written in the command prompt of our virtual processor to execute one or more instructions:

**ADD: R1, 1 , 4**

"ADD" = Instruction

R1 = Register number 1

1 = value 1

2 = value 2

Instruction Objective = Add 1 to 2, then store the result in the register named R1. 


### 3.2 Virtual processor

#### 3.2.1 Instruction Set

As described in the table above in section 3.1.3, we have decided to select the basic instructions of the assembly language to avoid getting lost. Furthermore, the chosen instructions are those that allow arithmetic operations, logical maneuvers, and instructions to shuffle data in and out of memory. Essentially, anything fundamental for a processor to do its job.


#### 3.2.2 Register

Our processor needs a set of internal registers to
keep things organized during computation. Let’s lay
out the purpose and limits of each register, like a
choreography for our processor dance.

Our virtual processor will be based on 16 bits, so we’ll have a total of 16 registers ranging from (R1 to R12, and we will have R_IP, (also known as Intra-Procedure-call scratch register), R_SP, (also known as Stack Pointer) R_LR, (also known as Link Register), R_PC, (also known as program counter) ). 

#### 3.2.3 Instruction Execution

Imagine each assembly instruction as a script. We
need to decide how our virtual processor reads,
understands, and acts upon these scripts. So, let’s
outline the steps for fetching, decoding, and
executing each instruction. It's like teaching our
processor a well-rehearsed routine.


il va ouvrir un fichier texte pour ensuite lire le code qui y est ecrit en assemby pour ensuite dectecter si il y a une erreur ou elle est situer et sur quel ligne. 

#### 3.2.4 Memory

Our processor needs a memory system – a mental
space to store data and instructions. Let's sketch
out how this memory works: the addressing method,
its size, and the steps for loading and storing
data. It's like building a mental filing cabinet
for our processor's thoughts. 

#### 3.2.5 Interrupts

Sometimes our processor needs to take a break for
important tasks – that's where interrupts come in.
Let's design a system for managing these
interruptions, deciding their types, priority, and
how our processor responds when it gets a tap on
the virtual shoulder.


### 3.3 Interpréteur d'Assembleur

L'interpréteur d'assembleur est chargé d'analyser et d'exécuter les programmes écrits en langage d'assemblage destinés au processeur virtuel. Il veille à ce que le programme respecte la syntaxe et la sémantique définies à la section 3.2 et fournit un mécanisme d'exécution efficace.

#### 3.3.1 Analyse Syntaxique

L'interpréteur commence par analyser le programme en langage d'assemblage fourni par l'utilisateur. Il suit les règles syntaxiques définies et tokenize le programme en le décomposant en instructions individuelles, opérandes et étiquettes. Le processus d'analyse identifie le type de chaque instruction et valide l'utilisation correcte des opérandes.

#### 3.3.2 Exécution

Une fois le programme en langage d'assemblage analysé, l'interpréteur entre dans la phase d'exécution. Il itère à travers chaque instruction, effectue l'opération spécifiée et met à jour l'état du processeur virtuel en conséquence. L'exécution inclut les étapes clés suivantes :

- **Chargement de Valeurs Immédiates :**
  - L'interpréteur gère les instructions impliquant le chargement de valeurs immédiates dans des registres.

  ```assembly
  LOAD R1, 42    ; Charge la valeur immédiate 42 dans le registre R1
  ```

- **Opérations sur les Registres :**
  - Les instructions pour copier des valeurs entre les registres et effectuer des opérations arithmétiques ou logiques sont exécutées.

  ```assembly
  ADD R2, R1, R3 ; Ajoute les valeurs dans les registres R1 et R2 et stocke le résultat dans R3
  ```

- **Accès à la Mémoire :**
  - L'interpréteur lit ou écrit à des adresses mémoire en fonction du contenu des registres.

  ```assembly
  LD R4, [R2]    ; Charge la valeur à l'adresse mémoire spécifiée par R2 dans le registre R4
  ST R3, [R4]    ; Stocke la valeur du registre R3 à l'adresse mémoire spécifiée par R4
  ```

- **Sauts Conditionnels :**
  - L'interpréteur gère les sauts, qu'ils soient inconditionnels ou conditionnels en fonction des résultats de comparaison.

  ```assembly
  CMP R3, R4     ; Compare les valeurs dans les registres R3 et R4
  JE LABEL1      ; Sauter à LABEL1 si le résultat de la comparaison est égal (JNEQ peut être implémenté par inversion de la condition)
  ```

- **Appels de Sous-routines et Retours :**
  - L'interpréteur gère les appels et les retours de sous-routines.

  ```assembly
  CALL SOUS_ROUTINE ; Appeler une sous-routine
  RET            ; Retourner d'une sous-routine
  ```

- **Intégration du Débogueur :**
  - Pendant l'exécution, l'interpréteur peut afficher des informations de débogage, telles que l'instruction en cours, le compteur de programme, et le contenu des registres.

- **Gestion des Appels Systèmes Virtuels :**
  - Si un appel système virtuel est rencontré, l'interpréteur interagit avec le terminal virtuel ou effectue l'action spécifiée.

#### 3.3.3 Gestion des Erreurs

L'interpréteur inclut des mécanismes de gestion des erreurs robustes pour détecter et signaler les erreurs de syntaxe, les erreurs sémantiques ou les erreurs d'exécution pendant l'exécution du programme. Des messages d'erreur clairs et des retours d'information informatifs aident les utilisateurs à identifier et à résoudre les problèmes dans leurs programmes en langage d'assemblage.

---

N'hésitez pas à ajuster le contenu en fonction de la conception spécifique de votre interpréteur et des fonctionnalités supplémentaires que vous prévoyez d'inclure.


### 3.4 User Interface

The user interface for the virtual processor system consists of both the assembly language program input and the runtime display of information during program execution. The goal is to provide a seamless and informative experience for users interacting with the system.

#### 3.4.1 Assembly Language Program Input

Users interact with the virtual processor system by providing assembly language programs through text files. The format of these files follows the specifications outlined in section 3.2, adhering to the defined assembly language syntax. To facilitate ease of use, consider providing a sample template or guidelines for creating assembly programs.

##### Example Assembly Program File:

```assembly
; Sample Assembly Program
LOAD R1, 42      ; Load immediate value 42 into register R1
ADD R2, R1, R3   ; Add values in registers R1 and R2 and store the result in R3
CMP R3, R4       ; Compare values in registers R3 and R4
JNEQ LABEL1      ; Jump to LABEL1 if the comparison result is not equal
...

LABEL1:          ; Define a label for conditional jumps
...
```

#### 3.4.2 Runtime Display

During the execution of an assembly program, the virtual processor system provides real-time information to the user, aiding in debugging and understanding the program flow. The following elements are displayed:

- **Registers:** Display the contents of registers, updating after each instruction execution.
  
  ```
  Registers:
  R1: 42
  R2: 0
  R3: 42
  ...
  ```

- **Memory:** Optionally, display the state of memory, especially when reading or writing to memory addresses.

  ```
  Memory:
  0x00: 42
  0x04: 0
  0x08: 0
  ...
  ```

- **Virtual Terminal Output:** If a virtual system call is implemented for displaying text in a virtual terminal, show the output of the virtual terminal.

  ```
  Virtual Terminal Output:
  Hello, World!
  ```

#### 3.4.3 Error Handling

The user interface should also handle errors gracefully, providing meaningful messages for syntax errors, semantic errors, or runtime errors during program execution. Clear error messages will assist users in identifying and resolving issues in their assembly programs.

## 4. Non Functional Requirement
