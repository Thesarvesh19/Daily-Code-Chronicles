Problem: Construct Product Matrix

This problem asks to create a new matrix where each element is the product of all elements in the given matrix except itself. The result should be taken modulo 12345.

Approach

We cannot directly multiply all elements and divide because:

Division is not safe with modulo
There can be zero values

So we use a better approach:

Convert the 2D matrix into a 1D array
Create a prefix product array
prefix[i] = product of all elements before index i
Create a suffix product array
suffix[i] = product of all elements after index i
For each position:
result[i] = prefix[i] * suffix[i] % 12345
Convert the result back into a 2D matrix
Time Complexity

O(n * m)

Space Complexity

O(n * m)

Languages Implemented
Python
Java
Notes
Always take modulo at each multiplication
Do not use division
In Java, use long to avoid overflow
