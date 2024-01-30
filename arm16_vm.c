#include <string.h>
#include "gate_operation.h"
#include "operation.h"
#include "mnemonics.h"

void execute_file(const char* filename)
{
    FILE* file = fopen(filename, "r+");
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        // Remove the newline character
        line[strcspn(line, "\n")] = 0;

        // Print the line
        printf("%s\n", line);
    }

    fclose(file);
}

int main()
{
    // Execute the assembly instructions in the file
    execute_file("Arm_Assembly.txt");

    return 0;
}
