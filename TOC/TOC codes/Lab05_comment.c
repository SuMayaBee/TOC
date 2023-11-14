#include <stdio.h>
#include <string.h>

int main()
{
    const char *fileName = "CommentSource.c";
    const char *backSlash = "/*";
    const char *frontSlash = "*/";
    const char *doubleSlash = "//";
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Failed to open the file");
        return 1;
    }
    char line[256];
    int lineNumber = 1;
    int frontSlashLine = -1, backSlashLine = -2;
    while (fgets(line, sizeof(line), file))
    {
        frontSlashLine = -1, backSlashLine = -2;
        if (strstr(line, backSlash) != NULL)
        {
            printf("Line: %d has a backSlash\n", lineNumber);
            backSlashLine = lineNumber;
        }
        if (strstr(line, frontSlash) != NULL)
        {
            printf("Line: %d has a frontSlash\n", lineNumber);
            frontSlashLine = lineNumber;
        }

        lineNumber++;
        if (backSlashLine == frontSlashLine)
        {
            printf("This section is properly commented out\n");
        }
        if (backSlashLine != frontSlashLine && (strstr(line, backSlash) != NULL || strstr(line, frontSlash) != NULL))

        {
            printf("This section is not properly commented out\n");
        }
    }

    fclose(file);
    fopen(fileName, "r");
    lineNumber = 1;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, doubleSlash) != NULL)
            printf("Line: %d has a doubleSlash\n", lineNumber);
        lineNumber++;
    }

    fclose(file);
}