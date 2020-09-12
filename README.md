# simple-linear-reggression
A very simple linear regression algorithm designed in c++
Commands:

- end: exit the program. Example: `end`
- btrain (syntax: `btrain {int}`): trains the model for given amount of batches. Example: `btrain 4`
- eval (syntax: `eval (double)`): Evaluates `w * x + b`. Example:  `eval 3`
- edit (syntax: `edit (string)`): Edits the given item, you will be prompted on how to proceed. Example: `edit x`. Keywords: 'x', 'y'
- print (syntax: `print (string)`): Prints the given variable. Example: `print x`. Keywords: 'x', 'y', 'w', 'b', 'dw', 'db, 'samples'

## Common Keywords
- 'x' is the input part of the data
- 'y' is the output part of the data
- 'w' is the weight
- 'b' is the bias
- 'dw' is the (negative of) derivitive of the weight with respect to the loss function
- 'db' is the (negative of) derivitive of the bias with respect to the loss function
- 'samples' is the lenth of x (or y; they should be equal)
