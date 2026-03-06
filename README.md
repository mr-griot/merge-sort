# merge-sort


# Merge Sort in C – How the Code Works

This repository contains a C program that implements **Merge Sort** for sorting arrays of integers. The program allows the user to enter a custom array size (up to 10 million) and prints only the first 100 elements of the array before and after sorting.

---

## How the Code Works

### 1. User Input

The program starts by asking the user to enter the size of the array:

```c
printf("Enter array size (1 to 10000000): ");
scanf("%d", &n);
