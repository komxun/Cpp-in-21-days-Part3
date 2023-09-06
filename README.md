# Cpp-in-21-days-Part3


Table of contents
=================

<!--ts-->
  * [Pointer](#what-is-a-pointer)
      * [Storing a Variable's address in a pointer](#storing-a-variables-address-in-a-pointer)
      * [Pointers VS Address VS Variables](#pointers-vs-address-vs-variables)
  * [Free Store (Heap)](#free-store-heap)
      * [`new`](#allocating-space-with-new)
      * [`delete`](#the-class-member-access-operator--)
  * [`->` operator](#the-class-member-access-operator--)
  * [`this` pointer](#this-pointers)
  * [`const` pointer](#const-pointers)
  * [`&` References](#references)
      * [Returning Multiple Values](#returning-multiple-values)
      * [Passing a `const` pointer](#passing-a-const-pointer)
  * [The Copy Constructor](#the-copy-constructor)
  * [Operator Overloading](#operator-overloading)
<!--te-->





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
- A pointer that is not initialized is called a _wild pointer_ because you have no idea what it is pointing to (very dangerous!)

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

# Free Store (Heap)
![image](https://github.com/komxun/Cpp-in-21-days-Part3/assets/133139057/683ac868-8ba6-4399-bb5b-edbf6514d5e3)

Free store is the remaining memory apart from Stack, Code, Global namespace, and Registers memories.
- The free store is NOT cleaned until your program ends !
- If you neglect to free the memory allocated on free store, it can build up over time and cause the system to crash

## Allocating space with `new`
- You allocate memory on the free store by using `new`
``` cpp
unsigned short int *pPointer;
pPointer = new unsigned short int;

// In one line
unsigned short int *pPointer = new unsigned short int;
// pPointer now points to an unsigned short int on the free store
```
## Claiming memory back with `delete`
- You must free the allocated memory back to the system when you are finished with it
- `delete` returns the memory to the free store
- If a pointer variable is pointing to memory on the free store and the pointer goes out of
scope, you can no longer access that memory. This is called **memory leak**
- For every time in your program that you call `new`, there should be a call to `delete` !

# The class member access operator (`->`) 
- The indirection operator (`->`) is applied to **pointer** to access the member data and functions.
https://github.com/komxun/Cpp-in-21-days-Part3/blob/31fdff9bff2d997efa98f92dc3f1ec6f98a7467d/Day%208%20-%20Pointers/Accessing_Member_Data_of_Object_on_FreeStore.cpp#L17-L26

# `this` Pointers
- Every class member has the `this` pointer
- `this` pointer points to "this" individual **object**
- The compiler already takes care of creating and deleting the `this` pointer
https://github.com/komxun/Cpp-in-21-days-Part3/blob/31fdff9bff2d997efa98f92dc3f1ec6f98a7467d/Day%208%20-%20Pointers/Using_the_this_Pointer.cpp#L3-L15

# `const` Pointers
```cpp
const int * pOne;  // a pointer to a constant integer
int * const pTwo;  // a constant pointer to an integer
const int * const pThree  // a constant pointer to a constant integer 
```
- pOne : the value that is pointed to can't be changed
- pTwo : pTwo pointer can't point to anything else, but the integer can be changed
- pThree : the value that is pointed to can't be changed, and pThree pointer can't point to anything else

# References
- Reference MUST always be initialized to something when created
- References act as a synonym for their target
- Anything you do to the references is really done to the target
- Reference variables cannot be reassigned -- doing so will update the reference and its target's value
``` cpp
int x;
int &rSomeRef = x;

Cat &rCatRef = Cat; // WRONG !!
```
## Returning Multiple Values
- Functions can only return one value
- One way to solve this problem is to passing by reference

https://github.com/komxun/Cpp-in-21-days-Part3/blob/31fdff9bff2d997efa98f92dc3f1ec6f98a7467d/Day%209%20-%20References/Passing_by_References.cpp#L2-L27


## Passing a `const` pointer
- Although passing a pointer to function is more efficient, it is dangerous - it exposes the original object to change.
- The solution is to pass a pointer to a `const` object
https://github.com/komxun/Cpp-in-21-days-Part3/blob/31fdff9bff2d997efa98f92dc3f1ec6f98a7467d/Day%209%20-%20References/Passing_Pointer_to_Constant_Object.cpp#L56-L62


# The Copy Constructor
- All copy constructors take 1 parameter: a reference to an object of the same class
```cpp
Cat(const Cat & theCat);
```
Default copy constructor = shallow copy

**Shallow copy** : pointers in both objects end up pointing to the same memory! -> problem!
If the original object's destructor frees this memory and the new object is still pointing to the memory, a stray pointer has been created!

**Deep copy** : the values allocated on the heap is copied to a newly allocated memory -> custom create the copy constructors

![image](https://github.com/komxun/Cpp-in-21-days-Part3/assets/133139057/9f1fcf52-d8aa-47ae-8bd1-d66656f5a6d8)


https://github.com/komxun/Cpp-in-21-days-Part3/blob/2d9b4424651160e16e72660483d612cfadea965b/Day%2010%20-Advanced%20Functions/Copy_Constructors.cpp#L28-L44

- Any `Cat` object can access private member variables of any other `Cat` object; however, it is good programming practice to use public accessor methods when possible!



# Operator Overloading
The built-in operators, e.g. + - / * ++, can be added to C++ classes as well 
## Making an operator with Function
This method works, but it is cumbersome to use!
```cpp
// Ex: Defining an increment operator for a class
class Counter
{
  public:
    void Increment() {++itsVal;}
  private:
    int itsVal;
};
```
## Overloading Prefix Operator
Prefix operators can be overloaded by declaring functions with the form:
`returnType operator op ()`
```cpp
// Ex: Overloading operator++
class Counter
{
  public:
    void operator++ () {++itsVal;}
  private:
    int itsVal;
};
```
Example:
https://github.com/komxun/Cpp-in-21-days-Part3/blob/e525830d0dbd75382d50a078c887a70dadf1f4ac/Day%2010%20-Advanced%20Functions/Overloading_operator%2B%2B.cpp#L5-L31

Here, the ++ operator returns nothing (void). This program increments the value and and only update object `i`.
Since it returns void, you can't assign this incremented value to a new object

For example:
```cpp
Counter a = ++i;    // Not happening since the defined ++ operator does not return a Counter object!
```
### Returning Types in Overloaded Operator Functions
#### Method 1a: Create a temporary object - use the class's method to update the value and return it
To return some type from the overloaded operator, one approach is to create a **temporary object**, use the class method, and then return that.

https://github.com/komxun/Cpp-in-21-days-Part3/blob/e525830d0dbd75382d50a078c887a70dadf1f4ac/Day%2010%20-Advanced%20Functions/Return_temporary_Object.cpp#L5-L28

#### Method 1b: Create a temporary object - use a **custom constructor** to initialize the updated value and return it
From the previous method, a custom constructor can be used to initialize the value when the temporary is created.
https://github.com/komxun/Cpp-in-21-days-Part3/blob/e525830d0dbd75382d50a078c887a70dadf1f4ac/Day%2010%20-Advanced%20Functions/Returning_Nameless_temporary_object.cpp#L5-L30

#### Method 2: Use the `this` pointer
- This method returns the dereferenced pointer pointed to the current object which is incremented
- The value returned is a Reference of an object to avoid the creation of an extra temporary object
- It is constant because the value should not be changed

https://github.com/komxun/Cpp-in-21-days-Part3/blob/e525830d0dbd75382d50a078c887a70dadf1f4ac/Day%2010%20-Advanced%20Functions/this_pointer.cpp#L4-L24

## Overloading Postfix Operator
``` cpp
// Postfix example
a = x++;
// ^This is equivalent to
a2 = x2;
x2 = x2 + 1;
```
# Overloading Binary Mathematical Operators
- Prefix and postfix are unary operators: it operates on only 1 object
- Mathematical operators are binary: they take 2 objects (e.g. + - * /)

## Overloading Binary Operators with Function
- (unnatural method)
https://github.com/komxun/Cpp-in-21-days-Part3/blob/2d9b4424651160e16e72660483d612cfadea965b/Day%2010%20-Advanced%20Functions/Add_function.cpp#L5-L39

## Overloading operator+
- (better method)
https://github.com/komxun/Cpp-in-21-days-Part3/blob/2d9b4424651160e16e72660483d612cfadea965b/Day%2010%20-Advanced%20Functions/Overloading_Addition_operator.cpp#L5-L39


