# DNA to Amino Acid Exon Finder

## Project Overview

This project is a C program that translates DNA sequences to RNA, converts RNA codons to amino acids, and identifies exon regions in the genetic sequence by comparing RNA and amino acid sequences.

--- 

## Key Features

DNA to RNA Translation: Converts DNA bases (A, T, G, C) to RNA (U, A, C, G).

RNA to Amino Acid Mapping: Converts RNA codons to amino acids using genetic code.

Exon Identification: Finds the exact positions of exon regions in DNA by aligning RNA and amino acid sequences.

---

## Key Functions

dna_to_rna() – Translates DNA base to RNA base.

converter() – Converts RNA codon to amino acid.

stop_codon_index() – Finds the position of the stop codon in RNA.

last_amino() – Finds the last amino acid in the input sequence.

test_exon() – Checks for the correct exon alignment.

len() – Calculates the length of the exon.

---

## How to Run

Compile and run the program:

```
gcc main.c -o exon_finder
./exon_finder
```

Input:

First line: DNA sequence (A, T, G, C), ends with .

Second line: Amino acid sequence (single characters), ends with .

Output:

Exon positions as four integers (start and end positions of two exon regions), or NONE if no exons are found.

---

## Sample Output

```
12 45 67 98
```

OR

```
NONE
```

---

## Dependencies

C Compiler (gcc)

---

## Contact

Feel free to reach out for questions or contributions!
