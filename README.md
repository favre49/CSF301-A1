# CSF301-A1
Assignment for CS F301 Principles of Programming Languages

## Group Members

|Name|ID|
|---|---|
|Rahul Ganesh Prabhu|2018A7PS0193P|
|Shreyas Kera |2018A7PS1119P|
|Achyuth Anand Tadepalli|2018A7PS1117P|
|Raghurama Varma Gonela |2018A7PS1120P|

## Instructions to run

To compile, use `make`. This will create the executable `driver`. To run this executable, run `./driver`.

## Implementation details

* The source file is always in source.txt
* All outputs are in the format described in the problem description
* Since the type of a faulty expression (say, multiplication of boolean and real) is undefined, our implementation assumes the following):
  * If the operation is division, the output is always a real
  * If the operation is &&& or |||, the output is always a Boolean
  * The result of any other operation defaults to the type of the first expression
* Errors involving the wrong type being used as an operand suppresses errors about the two operands not being of the same type

## Source code
The source code can be found [on GitHub](www.github.com/favre49/CSF301-A1). This wil be made public 48 hours after submission deadline.
