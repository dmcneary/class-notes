# Textbook Notes - Chapter 1

## 1.1 - Introduction

3 main classes of computers:
- Personal computers
- Severs
- Embedded systems

Supercomputers are lumped into the "servers" category, as they are usually accessed by multiple people at once, and are generally purpose built around solving a specific set of problems or computations.

Embedded systems are generally built for a single task or program -  a thermostat, for example.

The current "PostPC" era describes the proliferation of personal mobile devices (*PMDs*) and encapsulates a different set of conventions for design limitations (battery life, network access).

*Cloud computing* paradigms are quickly taking over the role of traditional servers. Warehouse-scale computers (*WSCs*) like those owned by Amazon are built for serve thousands of clinets, who rent space on the server to deliver content or compute power. Software as a service (*SaaS*, hosted on servers built to scale to massive multiple & simultaneous client usage, is quickly replacing conventional local installation of applications.

### Table of data sizes

| Decimal | Abbreviation | Value | Binary term | Abbreviation | Value  | % Larger |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| kilobyte | KB | 1000<sup>1</sup> | kibibyte | KiB |2<sup>10</sup> | 2% |
| megabyte | MB | 1000<sup>2</sup> | mebibyte | MiB |2<sup>20</sup> | 5% |
| gigabyte | GB | 1000<sup>3</sup> | gibibyte | GiB |2<sup>30</sup> | 7% |
| terabyte | TB | 1000<sup>4</sup> | tebibyte | TiB |2<sup>40</sup> | 10 |
| petabyte | PB | 1000<sup>5</sup> | pebibyte | PiB |2<sup>50</sup> | 13 |
| exabyte | EB | 1000<sup>6</sup> |	exbibyte | EiB |2<sup>60</sup> | 15 |
| zettabyte | ZB | 1000<sup>7</sup> | zebibyte | ZiB |2<sup>70</sup> | 18 |
| yottabyte | YB | 1000<sup>8</sup> | yobibyte | YiB |2<sup>80</sup> | 21 |
| ronnabyte | RB | 1000<sup>9</sup> | robibyte | RiB |2<sup>90</sup> | 24 |
| queccabyte | QB | 1000<sup>10</sup> |	quebibyte | QiB |2<sup>1000</sup> | 24 |

### Factors of program performance

| Component | How this component affects performance |
| :---: | :--- |
| **Algorithm* | Determines both the number of source-level statements and the number of I/O operations executed |
| **Programming language, compiler, and architecture* | Determines the number of computer instructions for each source-level statement |
| **Processor and memory system* | Determines how fast instructions can be executed |
| **I/O system (hardware and operating system)* | Determines how fast I/O operations may be executed |

## 1.2 - 7 Great Ideas in Computer Design

1. **Use abstraction to simplify design**
Lower-level details are hidden to offer a simpler model at higher levels
2. **Make the common case fast**
Tends to enhance performance better than optimizing the rare case
3. **Performance via parallelism**
Since the dawn of computing, computer architects have offered designs that get more performance by performing operations in parallel
4. **Performance via pipelining**
Moves multiple operations through hardware units that each do a piece of an operation, akin to water flowing through a pipeline
5. **Performance via prediction**
In some cases it can be faster on average to guess and start working rather than wait until you know for sure, assuming that the mechanism to recover from a misprediction is not too expensive and your prediction is relatively accurate.
6. **Hierarchy of memories**
Memory speed often shapes performance, capacity limits the size of problems that can be solved, and the cost of memory today is often the majority of computer cost
7. **Dependability via redundancy**
Since any physical device can fail, we make systems dependable by including redundant components that can take over when a failure occurs and to help detect failures

## 1.3 - Below the program

**Systems software:** Software that provides services that are commonly useful, including operating systems, compilers, loaders, and assemblers. 
- Handling basic input and output operations
- Allocating storage and memory
- Providing for protected sharing of the computer among multiple applications using it simultaneously

**Operating system:** Supervising program that manages the resources of a computer for the benefit of the programs that run on that computer. 

**Compiler:** A program that translates high-level language statements into assembly language statements. 

The easiest signals for computers to understand are on and off, and so the computer alphabet is just two letters. Just as the 26 letters of the English alphabet do not limit how much can be written, the two letters of the computer alphabet do not limit what computers can do. The two symbols for these two letters are the numbers 0 and 1, and we commonly think of the computer language as numbers in base 2, or binary numbers.

**Binary digit:** Also called a bit. One of the two numbers in base 2 (0 or 1) that are the components of information. 

**Instruction:** A command that computer hardware understands and obeys.

**Assembler:** A program that translates a symbolic version of instructions into the binary version. 

**Assembly language:** A symbolic representation of machine instructions. 

**Machine language:** A binary representation of machine instructions. 

Assembly (and for certain, machine language) can be very hard to read and understand, so modern programmers usually program code in "high-level" languages like C++ or Java. These more recognizable languages are (usually) compiled down to Assembly, which is them assembled into binary machine code.
