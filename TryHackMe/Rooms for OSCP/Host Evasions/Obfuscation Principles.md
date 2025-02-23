
## Origins of Obfuscation

**Obfuscation**

- Primarily used to protection Intellectual Property. 

## Obfuscations Function for Static Evasion

**Obfuscating Data** 

- Array Transformation - Transforms arrays by splitting, folding, merging and flattening
- Data Encoding - Encodes data with mathematical functions or ciphers
- Data Procedurization - Subs static data with procedure calls
- Data Spliting/Merging - Distributes information of one variable into several new variables

Generally static signatures are weak, which should be the focus of obfuscation. 


## Object Concatenation 

**Concatenation** 

- An example of concatenation of data in Programming would be using the addition symbol to merge to data values

```python
var_a = 2 
var_b = 3
var_c = var_a + var_b
```

- When anti virus scan a programming document it will look for a variable's value, and the values hash. 
- By splitting a value in two the AV will not recognize the hash and move on. 
- Anything to change the hash of a value in code can be helped to obfuscate. 
  For example, adding non interpreted characters in certain programming languages can produce a different hash but the same value. 

## Obfuscation's Function for Analysis Deception 

**Obfuscation Methods**

- Junk Code - Useless code, code stubs
- Separation of Related Code - Separate related code  ? 
- Stripping Redundant Symbols - Remove debugging information, comments, helpful naming conventions
- Meaningless Identifiers - Mislead data with something else
- Implicit Controls - Convert explicit instructions to implicit instructions ?
- Dispatcher Based Controls - Determines the next block to be executed during runtime
- Probabilistic Control Flows - Control flows with same semantics but different syntax
- Bogus Control Flows - Control flows that do nothing

## Code Flow and Logic 

- Control Flow - Determines how a program will execute or proceed with logic
- CFG - Control Flow Graph
- Using arbitrary logic can confuse malware analyzers
## Arbitrary Control Flow Patterns 

- Arbitrary control flow patterns can leverage math, logic and complex algorithms to mislead an analyst
- Predicates - Decision making of an input function to return true or false
- Opaque Predicates - Known input and output
- Collatz Conjecture - If two arithmetic operations are repeated they will return one from every positive integer

## Protection and Stripping Identifiable Information 

