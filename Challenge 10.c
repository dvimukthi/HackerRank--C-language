
//Printing Pattern Using Loops


#include <stdio.h>
#include <stdlib.h>

int* book; //This stores the total number of books in each shelf.

int** page;// This stores the total number of pages in each book of each shelf. The rows represent the shelves and the columns represent the books.

int main() 
{

    int n;
    scanf("%d", &n);
    
    int len = n*2 - 1;
    
    for(int i=0;i<len;i++)
    {
        
        for(int j=0;j<len;j++)
        {
            
            int min = i < j ? i : j;
            min = min < len-i ? min : len-i-1;
            min = min < len-j-1 ? min : len-j-1;
            printf("%d ", n-min);
        }
        
        printf("\n");
        
    }
    
    return 0;
    
}
