# Homework #1
David McNeary
COMP 310
Section 16578-FA2022
10/20/2022

### Problem 1:
Omitted

### Problem 2:
a.) $\{a^ib^j : i\cdot j \text{ is even}\}$

> $(aa)^*b^* + a^*(bb)^*$

b.) $\{a^ib^j : i\text{ is even or }j\text{ is odd}\}$

> $(aa)^*b^* + a^*b(bb)^*$

c.) $\{a^ib^j : (i\cdot j) \% 2 = 1\}$

> $a(aa)^*b(bb)^*$

d.) $\{w\in \{a, b\}^* : \text{ the first and last letter in } w\text{ are different}\}$

> $(a(a + b)^*bb^*) + (b(a + b)^*aa^*)$

e.) $\{a^ib^ja^k : i+j \text{ even and }j+k\text{ odd}\}$

> $((aa)^*(bb)^*a(aa)^*) + (a(aa)^*b(bb)^*(aa)^*)$

<div style="page-break-after: always;"></div>

f.) $\{w\in\{a, b\}^∗ : w \text{ does not contain }3\text{ consecutive }b\text{s}\}$

> ![[images/graph_f.png|400]]

g.) $\{w\in\{a, b\}^∗ : n_a\% 3=0\}$

 > ![[images/graph_g.png|400]]

h.) $\{w \in \{a, b\}^∗ : w \text{ does not end with }ba\}$

> ![[images/graph_h.png|400]]

<div style="page-break-after: always;"></div>

i.) $\{w \in \{a, b\}^∗ : w \text{ contains an odd number of } b \text{s and at least 3 }a\text{s}\}$

> ![[images/graph_i.png|400]]

j.) $\{w \in \{a, b\}^∗ : \vert w\vert\ge 4\}$

> ![[images/graph_j.png|400]]

k.) $\{w \in \{a, b\}^∗ : w \text{ is not of the form } a^ib^j\}$

> ![[images/graph_k.png|400]]

<div style="page-break-after: always;"></div>

l.) $\{a^ib^ja^k : i+k\ne3\}$

> ![[images/graph_l.png|400]]

m.) $\{w \in \{a, b\}^∗ : w \text{ contains } aaa \text{ but not } bb\}$

> ![[images/graph_m.png|400]]

n.) $\{w \in \{a, b\}^∗ : w \text{ contains } abb \text{ but not } abbb\}$

> ![[images/graph_n.png|400]]

<div style="page-break-after: always;"></div>

o.) $\{w \in \{a, b\}^∗ : n_a = 3 \text{ and does not contain } aa\}$

> ![[images/graph_o.png|400]]

p.) $\{w \in \{a, b\}^∗ : w \text{ does not contain } aab\}$

> ![[images/graph_p.png|400]]

<div style="page-break-after: always;"></div>

q.) $\{a^ib^j : i+j\ge4\}$

> ![[images/graph_q.png|400]]

r.) $\{w\in\{a, b\}^∗ : n_a\% 2=0 \text{ and } n_b=3\}$

> ![[images/graph_r.png|400]]

s.) $\{w \in \{a, b\}^∗ : w \text{ does not end with } aabb\}$

> ![[images/graph_s.png|400]]

t.) $\{a^ib^j : (i + 2j) \% 3 = 0 \}$

> ![[images/graph_t.png|400]]

u.) $\{w \in \{a, b\}^∗ : \vert w\vert \le 6 \}$
> ![[images/graph_u.png|400]]

v.) $\{a^ib^j : i \ne 3 \text{ or } j \ne 3 \}$

> ![[images/graph_v.png|400]]

<div style="page-break-after: always;"></div>

w.)  $\{w \in \{a,b\}^* : (n_a - n_b) \% 3 = 1 \}$

> ![[images/graph_w.png|400]]

x.) $\{w \in \{a,b\}^* : w \text{ begins or ends with } aaa\}$

> ![[images/graph_x.png|400]]

<div style="page-break-after: always;"></div>

y.) $\{w \in \{a,b\}^* : \text{every } a \text{ is followed by a } b\}$

> ![[images/graph_y.png|400]]

<div style="page-break-after: always;"></div>

### Problem 3:
#### DFA 1:
Accepted:
- $baaab$
- $abaaaab$
- $abaabbaaaababb$
- $baaaaaaabb$
- $abbaabbaaaabb$

Rejected:
- $aaa$
- $abbaaaba$
- $abab$
- $baab$
- $abba$

This DFA accepts words which end with the substring $baaaa^*bb^*$ - that is, words which end with a substring containing 3 or more $a$'s sandwiched between a $b$ on the left and one or more $b$'s on the right.

#### DFA 2:
Accepted: 
- $aba$
- $abb$
- $ba$
- $bb$
- $bba$

Rejected: 
- $aabaa$
- $baabaa$
- $aaa$
- $abbab$
- $abab$

This DFA accepts words which end with either $bb$ or $ba$.

#### DFA 3:
Accepted:
- $\lambda$
- $aabb$
- $abab$
- $aabbaababa$
- $babababa$
- $bbaabababbaa$

Rejected:
- $aba$
- $ba$
- $babab$
- $bbaabbaaa$
- $a$

This DFA accepts words with even numbers of $a$'s and even numbers of $b$'s, consecutive or not.

<div style="page-break-after: always;"></div>

### Problem 4:
#### NFA 1:
Accepted: 
- $b$
- $bab$
- $babab$
- $baaabaabababbbb$
- $bbbbbbbb$

Rejected:
- $a$
- $baba$
- $bbbbba$
- $babbbbba$
- $baaaaaaaba$

This NFA accepts all words which end in $b$.

<div style="page-break-after: always;"></div>

### Problem 5:
#### NFA 1:
> ![[images/graph5-1.png|400]]

#### NFA 2:
> ![[images/graph5-2.png|400]]

#### NFA 3:
> ![[images/graph5-3.png|400]]

#### NFA 4:
> ![[images/graph5-4.png|400]]

#### NFA 5:
> ![[images/graph5-5.png|400]]

<div style="page-break-after: always;"></div>

### Problem 6
1.) $a^*[bb^*a(ba)^*a][bb^*a(ba)^*a]^*(a^*b)^*b^*$

2.) $aa^*b^* + b[(a+b)(a+b)^*b]^* +aa^*b(a+b)a^*$

3.) $a(a+b)b^* + [a(a+b)b^* + ba^*b^*]ab^*a[a(a+b)b^* + ba^*b^*] + ba^*b^*$

<div style="page-break-after: always;"></div>

### Problem 7
#### Grammar 1:
> ![[images/graph7-1.png|400]]

#### Grammar 2:
> ![[images/graph7-2.png|400]]

<div style="page-break-after: always;"></div>

### Problem 8:
#### DFA 1:
$S\rightarrow aS\space\vert\space bA$
$A\rightarrow aC\space\vert\space bA$
$B\rightarrow aD\space\vert\space bA$
$C \rightarrow aB\space\vert\space bA$
$D\rightarrow aD\space\vert\space bE$
$E\rightarrow aD \space\vert\space bE \space\vert\space \lambda$

#### DFA 2:
$S\rightarrow aA\space\vert\space bB$
$A\rightarrow aA\space\vert\space bB\space\vert\space\lambda$
$B\rightarrow aA\space\vert\space bA\space\vert\space\lambda$

#### DFA 3:
$S \rightarrow aA \space\vert\space bC$
$A \rightarrow aD\space\vert\space bD$
$B\rightarrow aS\space\vert\space bB$
$C\rightarrow aC\space\vert\space bD$
$D\rightarrow aB\space\vert\space bD\space\vert\space\lambda$

<div style="page-break-after: always;"></div>

### Problem 9:
#### DFA 1:
> ![[images/graph9-1.png|400]]

#### DFA 2:
> ![[images/graph9-2.png|400]]

<div style="page-break-after: always;"></div>

### Problem 10:
#### RegEx 1:
> ![[images/graph10-1.png|400]]

#### RegEx 2:
> ![[images/graph10-2.png|400]]

<div style="page-break-after: always;"></div>

#### RegEx 3:
> ![[images/graph10-3.png|400]]

#### RegEx 4:
> ![[images/graph10-4.png|400]]

### Problem 11:
Omitted

### Problem 12:
Omitted

### Problem 13:
Omitted



