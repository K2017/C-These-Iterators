# C-These-Iterators
A simple iterator library for the C language.

Have you ever been bored of constantly writing out specialised for-loops to iterate through a normal array, or maybe a custom datatype you've written?

Stay bored no more!
With a few simple macros you can quickly and easily create a custom iterator for any datatype you want!



# Usage

Say you have a struct for an array of integers (a little contrived, but bear with me):
```c
typedef struct IntArray IntArray; // forward declaration

struct IntArray {
  int *arr;
  unsigned int size;
};
```
Figure 1. IntArray.h, Unmodified struct

And now you'd like to be able to iterate through this array whithout having to worry about size, or bounds checking at all. C-These-Iterators provides a few macros to help out with this.
```c
#include <c_iter/iter.h>

typedef struct IntArray IntArray; // forward declaration

decl_iterator(IntArray, int *) // create an iterator for my type, iterating over int pointers

struct IntArray {
  int *arr;
  unsigned int size;
  
  iterator_field(IntArray); // create a field for my iterator accessible through my type
};
```
Figure 2. IntArray.h, now with iterator declarations

Using pointers to `int`s in our declaration allows us to make the structure's content mutable as we iterate through it. You can also create an immutable iterator by specifying `int` instead.

Now you need to define the iterator's behaviour in a corresponding .c file. You do this by specifying overrides for each corresponding iterator function, the syntax works like this:
```c
override('function name', 'MyType', 'ReturnType') {
  _function body_
}
```

The following iterator methods must be defined by you: `begin`, `end`, `current`, `next`, `prev`. The `reset` method is defined automagically. The `begin`, `end`, and `current` methods must be defined with the same return type as the type declared for the iterator, i.e. `int *`. The rest must use `void` as the return type.

The way you write each function body is entirely up to you, depending on how you want the iterator to behave. Here is an example set of methods for our `IntArray`:
```c
#include "IntArray.h"

override(next, IntArray, void) {
  self->val += 1;
}

override(prev, IntArray, void) {
  self->val -= 1;
}

override(begin, IntArray, int *) {
  return self->stl->arr;
}

override(end, IntArray, int *) {
  return self->stl->arr + self->stl->size - 1;
}

override(current, IntArray, int *) {
  return self->val;
}
```
Figure 3. IntArray.c, specifying iterator overrides

Using the override macro provides the function body with a reference (read: pointer) to the iterator named `self`, through which you can access the struct itself using `self->stl`. You can then modify or read anything in the struct in order to define your iterator's behaviour.

Once you have these methods defined, you can define the iterator itself (doing so will require you to include stdlib.h for malloc):
```c
#include "IntArray.h"
#include <stdlib.h>

...  // iterator overrides

def_iterator(IntArray, int *)
```

And that's basically all there is to it.

When you create your struct in your program you'll also want to create the iterator for it. You can do this as follows, continuing with the `IntArray` example:
```c
IntArray *iarray = malloc(sizeof(IntArray));

iarray->size = 5;  // whatever value you want

iarray->arr = malloc(iarray->size * sizeof(int));

make_iterable(IntArray, iarray);
```
Figure 4. Creating an iterable `IntArray`

Now of course you'll probably want a convenient way to create your struct with the iterator all at once at this point. Luckily the STL part of library provides a few helper macros for that!

In IntArray.h you can declare a constructor for your type using `stl_decl_new`, which can be found in STL_utils.h. The constructor will have the name `newT` where `T` is the name of your type:
```c
#include <c_stl/STL_util>

...  // struct + iterator declaration

stl_decl_new(IntArray, unsigned int size);
```

Then in the corresponding .c file you'd use `stl_def_new` with the same arguments to define your constructor:
```c

...  // iterator definition

stl_def_new(IntArray, int size) {
  _construct type_
}
```

An example constructor for `IntArray`:
```c
stl_def_new(IntArray, unsigned int size) {
  IntArray *iarray = malloc(sizeof(IntArray));

  iarray->size = size;

  iarray->arr = malloc(size * sizeof(int));

  make_iterable(IntArray, iarray);
  
  return iarray;
}
```

## Disclaimer
This readme is incomplete, and this library is still under active development. Installation instructions will be added soon, but right now I would not recommend using this in production code until it has been fully tested.
