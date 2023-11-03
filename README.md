# Upper Triangular Matrix Manipulation (Q1)

This C++ program allows you to work with upper triangular matrices. Upper triangular matrices are square matrices in which all elements below the main diagonal are zero.

## Program Functions

1. **Allocate and Deallocate 2D Arrays**: The program provides functions to allocate and deallocate 2D arrays.

2. **Allocate and Deallocate Upper Triangular Matrices**: Functions are available to allocate and deallocate upper triangular matrices efficiently.

3. **Input from Console**: You can input upper triangular matrices from the console. The program checks whether the input matrix is upper triangular and converts it into an upper triangular representation.

4. **Input from File**: You can also input two upper triangular matrices from a file. The program checks if the matrices in the file are upper triangular.

5. **Matrix Operations**:
   - Addition: Add two upper triangular matrices of the same order.
   - Multiplication: Multiply two upper triangular matrices of the same order.
   - Row Manipulation: You can swap rows or delete rows in the upper triangular matrix.

# String manipulation (Q2)

This C++ code defines several functions for string manipulation and a simple menu-driven program. Here's a brief explanation of what each function does:

1. **`strsize`**: Calculates the length of a C-style string and returns the number of characters.

2. **`StringConcatenate`**: Concatenates two C-style strings (`str1` and `str2`) into a single string. It dynamically allocates memory for the new concatenated string.

3. **`CompressString`**: Removes duplicate characters from a string, effectively compressing it. It dynamically allocates memory for the compressed string.

4. **`ReverseSentence`**: Reverses the characters in a string and returns the reversed string. It dynamically allocates memory for the reversed string.

5. **`pluralWords`**: Takes an array of singular words and converts them into their plural forms based on various English language pluralization rules. It uses dynamic memory allocation to store the plural forms.

6. **`menu`**: Implements a simple menu-driven interface to interact with the above functions. It allows you to concatenate strings, compress a string, reverse a string, and obtain plural forms of words.

The program runs until the user chooses to exit (option 0) and provides interactive functionality for the specified operations.

Please note that there are multiple memory allocations and deallocations in these functions, which can be error-prone and may lead to memory leaks if not handled carefully.

