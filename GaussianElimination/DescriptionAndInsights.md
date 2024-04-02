# Gaussian Elimination


# Programming Insights 
    [1]Given an function parameter with no global variable 
    void parameterName(dataType variableName[row][column], int row, int column);
    
    Question: Is the code snippet runs with no error? 

    Variable-length arrays (VLAs) are not allowed to be declared at file scope or with static storage duration, which includes function parameter lists. Therefore, the provided code snippet won't compile as-is because VLAs cannot be used as function parameters.
    
    Variable-Length Arrays(VLAs) - Are arrays size are determined during runtime. 
    
    #DO AN ACTIVE LEARNING
    Variable-Length Arrays (VLAs): These are arrays whose size is determined at runtime rather than compile-time. In C, VLAs are allowed, but they have certain restrictions.

    File Scope and Static Storage Duration: Variables declared at file scope (outside of any function) or with static storage duration (using the static keyword) have a fixed size determined at compile-time. VLAs cannot be declared at file scope or with static storage duration.

    Function Parameter Lists: When you declare a function in C, you provide a list of parameters inside parentheses. These parameters specify the type and number of arguments that the function expects to receive when it's called.

    Compilation Error: If you try to use VLAs as function parameters (i.e., specifying the size of an array using variables passed as parameters), the code won't compile. This is because the size of the array needs to be known at compile-time for the function's signature to be valid.

    So, to put it all together:

    The provided code snippet won't compile because it tries to use variable-length arrays (VLAs) as function parameters. VLAs cannot be declared in function parameter lists because their size needs to be known at compile-time, but VLAs have a size determined at runtime. Therefore, this usage is not allowed, and attempting to compile the code will result in a compilation error.