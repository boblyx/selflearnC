# List
Self learned example of creating a list of strings and implementing functions to initialize and add to it.
## What it does
- Initializes an empty struct `List`
- List struct contains:
    - the number of items
    - the memory size it is meant to occupy
    - the actual array of pointers that point to its children.
- Add to a List struct from a flexible array
- Call a function that:
    - Take a List struct object and append a new `char*` item at the end
    - Copy over the pointers from the input List struct object for each item already in the struct.
    - Add the new input char pointer at the end
    - Compute new memory sizes and number of items
    - Return the new object
- Then with this new object, loop through and print its items.

## Lessons learned
- Flexible array members must be declared last
- Get to get the number of items in a pointer array:
```c
sizeof(*array)/sizeof(*array_type)
```
- `sizeof` cannot be properly called from external functions as it will return `sizeof(**param)` instead of `sizeof(*param)`
- As such, if `sizeof` is needed, store it in a struct.
- Love the `malloc`. If `malloc` is not done properly, it will lead to severe issues in later parts of the code.

## Conclusions
- C is actually very fun to code in.
- Makes me appreciate low level stuff that is going on in higher level languages that likely has done most of the heavy lifting behind the scenes in C.
