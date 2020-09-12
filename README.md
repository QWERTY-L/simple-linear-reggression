# simple-linear-reggression
A very simple linear regression algorithm designed in c++
Commands:

- end: exit the program. Example: `end`
- btrain (syntax: `btrain {int}`): trains the model for given amount of batches. Example: `btrain 4`
- eval (syntax: `eval (double)`): Evaluates `w * x + b`. Example:  `eval 3`
- edit (syntax: `edit (string)`): Edits the given item, you will be prompted on how to proceed. Example: `edit x`. Keywords: 'x', 'y'
- print (syntax: `print (string)`): Prints the given variable. Example: `print x`. Keywords: 'x', 'y', 'w', 'b', 'dw', 'db, 'samples'
