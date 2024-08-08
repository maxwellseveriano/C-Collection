#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3

void LRU(int pages[], int n, int capacity) {
    int frame[MAX_FRAMES], lastUsed[MAX_FRAMES], frameCount = 0, pageFaults = 0;
    int i, j, k;

    for (i = 0; i < n; ++i) {
        bool isPageExists = false;
        int replaceIndex = 0;
        
        // Check if page already exists in frames
        for (j = 0; j < frameCount; ++j) {
            if (frame[j] == pages[i]) {
                isPageExists = true;
                lastUsed[j] = i; // Update last used time
                break;
            }
        }

        if (!isPageExists) {
            if (frameCount < capacity) {
                frame[frameCount] = pages[i];
                lastUsed[frameCount] = i;
                frameCount++;
            } else {
                // Find the least recently used page
                int min = lastUsed[0];
                replaceIndex = 0;
                for (j = 1; j < frameCount; ++j) {
                    if (lastUsed[j] < min) {
                        min = lastUsed[j];
                        replaceIndex = j;
                    }
                }
                // Replace the least recently used page
                frame[replaceIndex] = pages[i];
                lastUsed[replaceIndex] = i;
            }
            pageFaults++;
        }

        printf("Pages in frames after page %d: ", pages[i]);
        for (k = 0; k < frameCount; ++k) {
            printf("%d ", frame[k]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 3, 5, 2, 4, 1, 7, 4, 6, 8};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity =3;

    LRU(pages, n, capacity);

    return 0;
}
