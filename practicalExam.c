#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

/* ===========================================================
   Q1. Write a C program that prompts the user to enter a 
       3-digit positive integer. Find the sum of first 
       and last digit.
   =========================================================== */
    int num, first, last, sum;
    printf("\nQ1: Enter a 3-digit number: ");
    scanf("%d", &num);

    last = num % 10;       
    first = num / 100;     
    sum = first + last;

    printf("First digit = %d, Last digit = %d\n", first, last);
    printf("Sum of first and last digit = %d\n", sum);


/* ===========================================================
   Q2. Develop a C program that reads a sentence from the user. 
       Create a function to count the occurrences of each 
       consonant in the sentence and display the counts.
   =========================================================== */
    char str[200];
    int freq[26] = {0};

    printf("\nQ2: Enter a sentence: ");
    getchar();  // clear input buffer
    fgets(str, sizeof(str), stdin);

    for(int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if(isalpha(ch) && !(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'))
            freq[ch - 'a']++;
    }

    printf("\nConsonant counts:\n");
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0)
            printf("%c : %d\n", i + 'a', freq[i]);
    }


/* ===========================================================
   Q3. Create a C program to check if a given number is 
       divisible by 3 and 5 both or not.
   =========================================================== */
    int n;
    printf("\nQ3: Enter a number: ");
    scanf("%d", &n);

    if(n % 3 == 0 && n % 5 == 0)
        printf("%d is divisible by both 3 and 5.\n", n);
    else
        printf("%d is NOT divisible by both 3 and 5.\n", n);


/* ===========================================================
   Q4. Write a C program that uses pointers to find the 
       sum of two 1D arrays.
   =========================================================== */
    int size;
    printf("\nQ4: Enter size of arrays: ");
    scanf("%d", &size);

    int a[size], b[size], sumArr[size];
    int *p1 = a, *p2 = b, *p3 = sumArr;

    printf("Enter elements of first array:\n");
    for(int i = 0; i < size; i++)
        scanf("%d", (p1 + i));

    printf("Enter elements of second array:\n");
    for(int i = 0; i < size; i++)
        scanf("%d", (p2 + i));

    for(int i = 0; i < size; i++)
        *(p3 + i) = *(p1 + i) + *(p2 + i);

    printf("Sum of arrays:\n");
    for(int i = 0; i < size; i++)
        printf("%d ", *(p3 + i));
    printf("\n");


/* ===========================================================
   Q5. Implement a C program to print the following pattern 
       using nested for loop:

   10 9 8 7 6
     9 8 7 6
       8 7 6
         7 6
           6
   =========================================================== */
    int start = 10, end = 6;
    printf("\nQ5: Pattern Printing\n");

    for(int i = 0; i <= start - end; i++) {
        for(int s = 0; s < i; s++)
            printf("  "); // spaces
        for(int j = start - i; j >= end; j--)
            printf("%d ", j);
        printf("\n");
    }

    printf("\n=========== End of Practical Programs ===========\n");

    return 0;
}
