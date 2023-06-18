# Cpp-in-21-days-Part3

The advantage of C++ is that it can manipulate computer memory directly by using pointers. This makes C++ the language of choice for embedded and real-time applications!

# What is a Pointer?
- A pointer is a variable that holds a memory address
- Each variable has an address and is located in a unique location (address) in memory
- When you declare a variable, the compiler determines how much memory to allow based on the variable type

For example: the address of short shortVar=5 is 0012FF7C, the address of long longVar=65535 is 0012FF78

# Storing a Variable's Address in a Pointer
- Even without knowing the specific address, you can store a variable's address in a pointer:
```cpp
int *pAge = 0;
```
This declares pAge to be a pointer to an int and pAge is holding the address of an integer
- A pointer whose value is zero is called a _null pointer_
- All pointers, when they are created, should be initialized to something.
- A pointer that is not initialized is called a _wild pointer_ be cause you have no idea what it is pointing to (very dangerous!)

``` cpp
unsigned short int howOld = 50;   // making a variable
unsigned short int * pAge = 0;    // make a pointer and initializes it to zero (the * indicates pAge is a pointer)
pAge = &howOld;                   // assigns the address of howOld to the pointer pAge (& is the address-of operator)

// Shorter version
unsigned short int howOld2 = 50;       // make a variable
unsigned short int * pAge2 = &howOld2; // make pointer to howOld2
```
