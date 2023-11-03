//
// Created by laphv on 8/26/2023.
//

#include "loadTemp.h"

    char accountTemp[PATH_MAX];

    int getAccountTemp()
    {
        char filename[] = "database\\Temp.txt";
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            perror("Error opening file");
            return -1;
        }

        if (fseek(file, 0, SEEK_END) != 0) {
            perror("Error seeking file");
            fclose(file);
            return -1;
        }

        long fileSize = ftell(file);
        if (fileSize == -1) {
            perror("Error getting file size");
            fclose(file);
            return -1;
        }

        if (fileSize == 0) {
            fclose(file);
            return 1;
        }

        if (fseek(file, 0, SEEK_SET) != 0) {
            perror("Error seeking file");
            fclose(file);
            return -1;
        }

        if (fgets(accountTemp, PATH_MAX, file) == NULL) {
            perror("Error reading line from file");
            fclose(file);
            return -1;
        }

        fclose(file);
        return 0;
    }