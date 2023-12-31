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
# Getting the Value from a Variable
Accessing the value stored in a variable by using a pointer is called **indirection** because you are indirectly accessing the variable by means of the pointer
- With a pointer, the type doesn't need to tell the compiler how much memory is needed because all pointers are the same size!
- (*) is also called the _dereference_ operator
- When a pointer is dereferenced, the value at the address stored by the pointer is retrieved

# Different Uses of the Asterisk (*)
1. Pointer declaration
2. Dereference operator - (*) in front of the pointer variable means "the value stored at"

```cpp
// make a pointer to an unsigned short
unsigned short * pAge = 0;

// dereference
*pAge = 5;   // assign 5 to the value at pAge

```

# Pointers VS Address VS Variables
``` cpp
int x = 5;
int * pPointer = &x;
```
- x is declared to be an integer variable intialized with the value of 5
- pPointer is declared to be a pointer to an integer; it is initialized with the address of x
- The value at the address that pPointer holds is 5

# Manipulating Data by Using Pointers
- After the pointer is assigned the address, you can use that pointer to access the data in the variable being pointed to

https://github.com/komxun/Cpp-in-21-days-Part3/blob/9e6b63ca2538a7ada14fd281481590a06f77eb4a/Day%208%20-%20Pointers/using_Pointers.cpp#L4-L34
```
// output
myAge: 5   
*pAge: 5

Setting *pAge = 7...
*pAge: 7
myAge: 7

Setting myAge = 9...
myAge: 9
*pAge: 9
```
- When the value pointed at the address is reassigned  the value of the variable also changes
- When the value of the variable changes, the value obtained from pointing the address also changes (dereferencing)
