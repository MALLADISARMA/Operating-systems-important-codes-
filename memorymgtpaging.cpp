#include <stdio.h>

int main() {
    int numPages, pageSize, logicalAddress;
    
    // User input
    printf("Enter number of pages: ");
    scanf("%d", &numPages);
    printf("Enter page size: ");
    scanf("%d", &pageSize);
    printf("Enter logical address: ");
    scanf("%d", &logicalAddress);
    
    // Calculate number of bits required for page offset and page number
    int offsetBits = 0;
    int temp = pageSize;
    while (temp > 1) {
        temp /= 2;
        offsetBits++;
    }
    int pageNumBits = 0;
    temp = numPages;
    while (temp > 1) {
        temp /= 2;
        pageNumBits++;
    }
    
    // Extract page number and offset from logical address
    int pageNumber = logicalAddress >> offsetBits;
    int offset = logicalAddress & ((1 << offsetBits) - 1);
    
    // Check if page number is valid
    if (pageNumber >= numPages) {
        printf("Error: Page number exceeds maximum!\n");
        return 1;
    }
    
    // Calculate physical address
    int physicalAddress = (pageNumber * pageSize) + offset;
    
    // Output
    printf("Page Number: %d\n", pageNumber);
    printf("Offset: %d\n", offset);
    printf("Physical Address: %d\n", physicalAddress);
    
    return 0;
}
