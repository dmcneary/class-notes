# Textbook Notes - Chapter 2

## 2.1 - Introduction

The linguistics of computations are slightly different from human language. We can program in high-level programming lnaguages like Java or C++, which are compiled down to Assembly...which can further be "assembled" into machine language.

Machine language (and different flavors of Assembly) consists of instructions, and a vocabulary of instructions forms an instruction set.

The textbook chooses to focus on MIPS, which has displayed elegance since the 1980s. Other dialects, like ARM and x86, are very similar in their syntax to MIPS, with their individual idiosyncracies.

This similarity results from nearly universal core principals that govern hardware technology and design. This is no coincidence - simplicity at the minimization of cost and maximization of performance has always been the common goal of computer designers.

The *stored-program concept* is central to the modern era of computing - the idea that instructions and data can be represented and stored as numbers.

## 2.2 Operations of the computer hardware

The following commands use the MIPS assembly language notation.

### Mathematics
The main function of a computer is to compute - this, arithmetic is essential. 

#### Addition and Substraction

The `add` instruction takes 3 parameters: the storage location for the sum, and two operands:

`add a, b, c # This adds b + c and stores the result in a`

The instruction must contain exactly 3 variables - thus, for a sum of multiple values, each step must be carried out individually.

`add a, b, c   # The sum of b and c is placed in a`
`add a, a, d   # The sum of b, c, and d is now in a`
`add a, a, e   # The sum of b, c, d, and e is now in a`

Similarly, `sub` will compute differences and also takes a storage parameter first in the instruction:

`sub a, b, c # The difference of b - c is stored in a`

Naturally, 3 operands will likely be used in a typical addition/subtraction computation. Thus, to keep hardware designs as simple as possible, 3 parameters are used every time. This displays one of three guiding principles of hardware design: *simplicity favors regularity.*

MIPS operands:
| Name | Example | Description |
| --- | --- | --- |
| Register (qty: 32) | $s0..$s7, $t0..$t9, $zero, $a0..$a3, $v0..$v1, $gp, $fp, $sp, $ra, $at | Fast locations for data. In MIPS, data must be in registers to perform arithmetic, register $zero always equals 0, and register $at is reserved by the assembler to handle large constants. |
| Memory (qty: 2^30 words) | Memory[0], Memory [4], ...., Memory[4294967292] | Accessed only by data transfer instructions. MIPS uses byte addresses, so sequential word addresses differ by 4. Memory holds data structures, arrays, and spilled registers. |

See table 2.2.2 in the textbook for instructions which utilize these operands.

## 2.3 - Operands of the computer hardware

