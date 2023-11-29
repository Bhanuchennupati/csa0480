#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 20

struct File {
    char filename[MAX_FILENAME_LENGTH];
};

struct Directory {
    struct File files[MAX_FILES];
    int fileCount;
};

void initializeDirectory(struct Directory *dir) {
    dir->fileCount = 0;
}

void displayFiles(struct Directory *dir) {
    printf("Files in the directory:\n");
    for (int i = 0; i < dir->fileCount; i++) {
        printf("%s\n", dir->files[i].filename);
    }
}

void addFile(struct Directory *dir, const char *filename) {
    if (dir->fileCount < MAX_FILES) {
        strcpy(dir->files[dir->fileCount].filename, filename);
        dir->fileCount++;
        printf("File %s added to the directory.\n", filename);
    } else {
        printf("Directory is full. Cannot add more files.\n");
    }
}

void deleteFile(struct Directory *dir, const char *filename) {
    int found = 0;
    for (int i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i].filename, filename) == 0) {
            found = 1;
            for (int j = i; j < dir->fileCount - 1; j++) {
                strcpy(dir->files[j].filename, dir->files[j + 1].filename);
            }
            dir->fileCount--;
            printf("File %s deleted from the directory.\n", filename);
            break;
        }
    }

    if (!found) {
        printf("File %s not found in the directory.\n", filename);
    }
}

int main() {
    struct Directory singleLevelDirectory;
    initializeDirectory(&singleLevelDirectory);

    int choice;
    char filename[MAX_FILENAME_LENGTH];

    do {
        printf("\nSingle-Level Directory Operations:\n");
        printf("1. Display Files\n");
        printf("2. Add File\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFiles(&singleLevelDirectory);
                break;
            case 2:
                printf("Enter filename to add: ");
                scanf("%s", filename);
                addFile(&singleLevelDirectory, filename);
                break;
            case 3:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                deleteFile(&singleLevelDirectory, filename);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

