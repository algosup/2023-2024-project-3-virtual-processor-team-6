# 2023-2024-project-3-virtual-processor-team-6

# Overview

Welcome to our project! 
The primary objective of this endeavor is to design and implement a virtual processor along with an interpreter tailored for executing assembly code specifically designed for this processor. The entire project will be crafted using the plain, portable C language, and it will adhere to the principle of relying solely on the C standard libraries, avoiding any external libraries for enhanced portability.


- - -


## How to Run the Program with bash

To run our program, follow these steps:

Certainly! Here's some advice on how to clone the repository:

1. **Cloning the Repository**: Use the `git clone` command to clone the repository to your local machine. Open a terminal or command prompt and navigate to the directory where you want to store the project.

   ```bash
   git clone https://github.com/algosup/2023-2024-project-3-virtual-processor-team-6.git
   ```

2. **Navigate to the Directory**: Once the cloning process is complete, navigate into the source directory of the cloned repository using the `cd` command.

   ```bash
   cd scr
   ```

3. **Modify the Assembly Code**: Users can customize the assembly code they wish to run on our virtual processor by editing the `Arm_Assembly.txt` file located in the `src` directory. Open the file using a text editor of your choice.

   Modify the assembly code in this file according to your requirements and save the changes.

4. **Compile the Code:** Before running the program, you might need to compile it. If necessary, compile the `arm16_vm.c` program using a C compiler. For example, if you're using GCC, you can compile it with the following command:
   ```bash
   gcc src/arm16_vm.c -o arm16_vm
   ```

5. **Execute the Program:** After compilation (if needed), execute the program by running the compiled executable. If you compiled with GCC in the previous step, you can run the program with:
   ```bash
   ./arm16_vm
   ```

These steps should successfully launch the program and allow you to interact with it. If you encounter any issues, refer to the project's documentation or reach out to our support team for assistance.


### How to Run the Program with GitHub Desktop

1. **Clone the Repository**: Open GitHub Desktop application and sign in to your GitHub account. Click on the "File" menu and select "Clone Repository". In the dialog that appears, choose the repository `2023-2024-project-3-virtual-processor-team-6`. Select the destination path on your local machine and click "Clone".

2. **Modify the Assembly Code**: Navigate to the cloned repository directory on your local machine. Locate the `Arm_Assembly.txt` file within the `src` directory. Open this file using a text editor of your choice and make the necessary modifications to the assembly code according to your requirements. Save the changes.

3. **Run the Program**: GitHub Desktop includes a feature called "C/C++ Runner: Run File" which allows users to directly run C/C++ files. Navigate to the `src` directory in GitHub Desktop. Find the `arm16_vm.c` file and click on it to open. Once opened, look for the "C/C++ Runner: Run File" button located in the top-right corner of the editor window. Click on this button to compile and run the `arm16_vm.c` file.

4. **Execute the Program**: After clicking the "C/C++ Runner: Run File" button, the program will be compiled and executed. You can interact with the virtual processor and execute the modified assembly code directly from GitHub Desktop.


- - -


### Documentation

- **[Functional Specification](Documents/FunctionalSpecification/FunctionalSpecification.md)**: This document outlines the functional requirements and specifications of the project, detailing what the software should do from a user's perspective.

- **[Technical Specification](Documents/TechnicalSpecification/TechnicalSpecification.md)**: The technical specification document provides an overview of the architecture, design, and technical requirements of the project, explaining how the system will be implemented.

- **[Test Plan](QA/Test_plan.md)**: The test plan defines the testing strategy, including test cases and procedures, to ensure the quality and reliability of the software.

- **[Project Charter](Management/ProjectCharter/ProjectCharter.md)**: The project charter establishes the project's objectives, scope, stakeholders, and resources, providing a high-level overview of the project's goals and constraints.


- - -


### Project Team

| **Photo** | **Name** | **Role** | **Links** |
|:---:|---|:---:|---|
| <img src="https://ca.slack-edge.com/T06BRJXQJLT-U06BB6L4QHM-gd2bfd349a46-512" width="75px" height="75px"> | Michel RIFF | Project Manager | <a href="https://www.linkedin.com/in/michel-riff-693007293/" target="_blank">LinkedIn</a><br><a href="https://github.com/MichelRiff" target="_blank">GitHub</a> |
| <img src="https://ca.slack-edge.com/T06BRJXQJLT-U06C4BPFBLZ-g10c7c642461-512" width="75px" height="75px"> | Raphael DESCAMPS | Program Manager | <a href="https://www.linkedin.com/in/rapha%C3%ABl-descamps-201112293/" target="_blank">LinkedIn</a><br> <a href="https://github.com/Raphaeldcp" target="_blank">GitHub</a> |
| <img src="https://ca.slack-edge.com/T06BRJXQJLT-U06BB6L2087-g852fc97e876-512" width="75px" height="75px"> | Habi CAILLEAU | Technical Leader | <a href="https://www.linkedin.com/in/habi-cailleau-3b72b5293/" target="_blank">LinkedIn</a><br> <a href="https://github.com/habicll" target="_blank">GitHub</a> |
| <img src="https://ca.slack-edge.com/T06BRJXQJLT-U06BK3PNCGN-g034e0d2085c-512" width="75px" height="75px"> | Vivien Bistrel TSANGUE CHOUNGOU | Junior Software Engineer | <a href="https://www.linkedin.com/in/bistrel-tsangue-603635261/" target="_blank">LinkedIn</a><br> <a href="https://github.com/Bistrel2002" target="_blank">GitHub</a> |
| <img src="https://ca.slack-edge.com/T06BRJXQJLT-U06BNQ7V0Q5-gdc3a8fc938e-512" width="75px" height="75px"> | Lucas AUBARD | Junior Software Engineer | <a href="https://www.linkedin.com/in/lucas-aubard-596b37251/" target="_blank">LinkedIn</a><br> <a href="https://github.com/LucasAub" target="_blank">GitHub</a> |
| <img src="https://ca.slack-edge.com/T06BRJXQJLT-U06BU6CGEMS-g9eed23df27b-512" width="75px" height="75px"> | Loris DE MATTIA SEGALAT | Quality Assurance | <a href="https://www.linkedin.com/in/loris-demattia-a27125293/" target="_blank">LinkedIn</a><br> <a href="https://github.com/Loriisss" target="_blank">GitHub</a>|
