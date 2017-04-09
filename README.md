# bxBam
indexed file format for barcoded BAMs with API for converting and accessing alignment records

## Table of contents
* [Installation](#installation)
* [Examples](#examples)

## Installation

```R
## install packages via devtools::install_github().
library(devtools)
install_github("KhagayN/bxBamTesting") ## this will change to mskilab/bxBam shortly.
```

## Examples

```R
## via functions available in package.
library(bxBam)
ls.str('package:bxBam')
```

```R
## generate index file given a BAM file.
bxBam('path_to_bam_file')
```
