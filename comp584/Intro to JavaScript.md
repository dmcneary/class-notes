
JavaScript in a singlethreaded programming language; unlike Java or Go, code generally runs line-by-line and JS natively does not support concurrency. Despite this restriction, JS is easier to understand because most code will run predictably, as it is written.

## Basic Rules
JavaScript is case-sensitive - variable and function names must be referenced using the correct case as it was assigned originally. The convention for variable names is usually in camelCase, though snake_case and CAPS are used as well occasionally.

Whitespace is not parsed as a structural element, though indentation and line breaks are still important to maintain readability. As well, semi-colons are not required for code to compile, but are still recommended for readability. Comments are available and encouraged, for documenting code.

JavaScript is usually included in an HTML document by using a `script` tag inside the `body` element. 

## Primitives
### Strings
Strings are defined literally by using either double quotes, single quotes, or backticks. Strings are concatenated by either using the `+` operator; template literals (defined using backticks) can have string variables directly inside the definition (i.e. `"Hello" + name` versus `Hello ${name}`)
### Numbers
Numeric data is stored in a single Number object, a double precision floating point type. 
### Booleans
