## Test Plan


| Author        | Loris DE MATTIA |
|---------------|------------ |
| Created       | 01/16/2024  |
| Last Modified | ...  |

---

<details>

<summary>📖 Table of content</summary>

- [Test Plan](#test-plan)
  - [Glossary](#glossary)
  - [Testing strategy](#testing-strategy)
    - [Smoke test](#smoke-test)
    - [Functionality Test](#functionality-test)
    - [Compatibility Testing](#compatibility-testing)
    - [Performance Testing](#performance-testing)
  - [Schedule](#schedule)
  - [Test Cases](#test-cases)
  - [Testing tools](#testing-tools)
    - [Hardware](#hardware)
    - [Software](#software)
  - [Issues Report](#issues-report)


</details>

---

This is the test plan for our version of virtual processor.

The purpose of these tests is to check that you can open and run a file .txt  with assembly code in it.

---

### Glossary

| Term | Definition |
|---|---|
| Smoke test | A smoke test is a quick and basic check or test performed to verify that it works on a fundamental level. A smoke test ensures that the main functionalities of a program or system are operational without delving into detailed or exhaustive testing. |
| Functional test | Functional testing is a process categorized as black-box testing. It constructs test cases based on the specified requirements of the software component under examination. |
| Regression test | A regression test is a check to ensure that recent changes to a software application haven't negatively impacted its existing functionalities. It helps catch unintended side effects or "regressions" that might occur when new features or updates are added. |
| Unit test | A unit test is a specific kind of testing conducted by developers on isolated components (units) of a software program. Developers create and execute unit tests to verify the correctness of individual functions or methods within the code. |
| Test case | A "test case" is a specific set of instructions or conditions that are designed to determine whether a software application, system, or component functions correctly under certain circumstances. It's a detailed scenario or situation used to verify that the software behaves as expected. |

---

### Testing strategy

The strategy that will be used to test the logiciel is to test it manually. The tester will have to test the virtual processor throughout the development phase and also afterwards in order to prevent the appearance of bugs and to be able to resolve them if there are any.

First, we'll run a smoke test to see if the basic functionality works. When the smoke test is successful, we will then perform a functional test to ensure all features work as expected. Then we will do a regression test after each new version to see if any new bugs appear.

---

#### Smoke test

This is a short description of the somke test we will perform

1. **Start the virtual processor** 
2. **Exit the virtual processor** 
3. **Open file** 
4. **Read file**

The purpose of these tests is to verify and confirm that the main features of our virtual processor work well.

#### Functionality Test

| Name of the test | Description |
| --- | --- |
| Open file | Check that the virtual processor can open the file correctly. |
| Read file | Check that the virtual processor correctly reads the file. |
| Read errors | Check whether the software can detect errors in the assembly code |
| Understanding error | Check that the software is capable of explaining and locating an error.


#### Compatibility Testing

| Test | Description |
| --- | --- |
| Processor compatibility | Test whether the software works on all types of computer. 


####  Performance Testing

| Test | Description |
| --- | --- |
| Load Testing | Evaluate the time it takes for the logiciel to initially load as well as the loading time. |
| Stress Testing | Push the locigiel to its limits to identify any breaking points. |

---

### Schedule

This section is dedicated to the progress of the testing phase, including smoke tests, functionality tests and bug reports. The logiciel will be tested throughout development and after each new version.

- Project timeline :
  
Start of the project : **_01/08/2024_**

Project deadline : **_02/23/2024_**


| Task | Start date | End date |
|------|------|----------|
| Report bugs | 01/17/2024 | 01/25/2024 |
| Unit test | 01/27/2024 | 02/22/2024 |
| Smoke testing | 02/04/2024 | 02/04/2024 |
| Production of documents | 01/16/2024 | 02/16/2024 |
| Start of the test on the working prototype | 01/26/2024 | 02/01/2024 |
| Functionality test | 02/02/2024 | 02/07/2024 |
| Regression test after each new version | 02/08/2024 | 02/14/2024 |

---

### Test Cases

During the testing phase, all the tests carried out will be stored in the " TestCases.md" file.

**Here is an example of a test case :**

| Test Case ID | 1 |
| --- | --- |
| Name | Name of the test |
| Description | Description of what should happen |
| Pre-conditions | What conditions must be met before starting the test |
| Steps | Step taken to obtain the expected result |
| Expected Result | Expected result after the test |
| Actual Result | Actual result after test |
| Status | Test status (To test, In testing, Tested) |
| Priority | The priority of the test (High, Medium, Low) |

---

### Testing tools

In order to test the logiciel, we will use several tools.

#### Hardware

We will run and test the virtual processor on different machines, we have 3 at our disposal, 2 of the machines were provided by the school: the Lenovo and the MacBook, the 3rd was provided by a member of our team.

Lenovo ThinkBook :
  - ThinkBook 14 G4 IAP
    - **Processor** : 12th Gen Intel® Core® i7-1255U   1.70 GHz
    - **RAM** : 16.0 GB
    - **System** : 64-bit operating system, x64-based processor
    - **Operating system** : Windows 11 Pro ( Version : 22H2 ) 
  
MacBook Air : 
  - MacBook Air 13″
    - **Processor** : Apple M1 chip
    - **RAM** : 8.0 GB
    - **Operating system** : macOS Ventura

Desktop computer : 
  - Lenovo High End
    - **Processor** : Intel® Core i9-12900F 16-Coeurs go to 5,10GHz Turbo
    - **RAM** : 32Go DDR5
    - **Operating system** : Windows 11


#### Software

We will use different software to run the logiciel, test it, report different bugs and resolve them.

- [GitHub](https://github.com) to report bugs.
- [Visual Studio Code](https://code.visualstudio.com/) ( version 1.84.2 ) to develop the logiciel and fix bugs.

---

### Issues Report

**Issue n°X**

**Date**

MM/DD/YYYY

**Description :**

**Actions performed :**

Actions performed to reproduce the bug

**Expected result :**

What should happen when the program works as expected

**Actual result :**

What actually happened

**Screenshot :**

(if it gives additional informations)
