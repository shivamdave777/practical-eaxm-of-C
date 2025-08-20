#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Q1: Sum of first and last digit of a 3-digit number
void sumFirstLastDigit() {
    int num, first, last, sum;
    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    last = num % 10;
    first = num / 100;
    sum = first + last;

    printf("Sum of first and last digit = %d\n", sum);
}

// Q2: Count consonants in a sentence
void countConsonants() {
    char str[200];
    int count[26] = {0};
    printf("Enter a sentence: ");
    getchar(); // to clear input buffer
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            if (!(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')) {
                count[ch - 'a']++;
            }
        }
    }

    printf("Consonant counts:\n");
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0)
            printf("%c = %d\n", i+'a', count[i]);
    }
}

// Q3: Divisible by 3 and 5
int isDivisibleBy3And5(int num) {
    return (num % 3 == 0 && num % 5 == 0);
}
void checkDivisibility() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isDivisibleBy3And5(num))
        printf("%d is divisible by both 3 and 5.\n", num);
    else
        printf("%d is NOT divisible by both 3 and 5.\n", num);
}

// Q4: Sum of 2 arrays using pointers
void sumArrays() {
    int n;
    printf("Enter size of arrays: ");
    scanf("%d", &n);
    int a[n], b[n], sum[n];
    int *p=a, *q=b, *r=sum;

    printf("Enter elements of first array:\n");
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    
    printf("Enter elements of second array:\n");
    for (int i=0; i<n; i++) scanf("%d", &b[i]);

    for (int i=0; i<n; i++)
        *(r+i) = *(p+i) + *(q+i);

    printf("Sum array: ");
    for (int i=0; i<n; i++)
        printf("%d ", sum[i]);
    printf("\n");
}

// Q5: Pattern printing
void printPattern() {
    for (int i = 0; i < 5; i++) {
        for (int s = 0; s < i; s++) printf("  "); // spaces
        for (int j = 10 - i; j >= 6; j--) printf("%d ", j);
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n===== Practical Exam Menu =====\n");
        printf("1. Sum of first and last digit of 3-digit number\n");
        printf("2. Count consonants in a sentence\n");
        printf("3. Check divisibility by 3 and 5\n");
        printf("4. Sum of two arrays using pointers\n");
        printf("5. Print number pattern\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: sumFirstLastDigit(); break;
            case 2: countConsonants(); break;
            case 3: checkDivisibility(); break;
            case 4: sumArrays(); break;
            case 5: printPattern(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}
