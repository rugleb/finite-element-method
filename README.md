# Finite element method

[![Build Status](https://travis-ci.com/rugleb/finite-element-method.svg?branch=master)](https://travis-ci.com/rugleb/finite-element-method)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## About

The finite element method ([wiki](https://en.wikipedia.org/wiki/Finite_element_method)), is a numerical method for solving problems of engineering and mathematical physics.  
Typical problem areas of interest include structural analysis, heat transfer, fluid flow, mass transport, and electromagnetic potential.  

Specifically, this program solves the problem of approximation of the equation at a given site in the presence of boundary conditions.  

The program solves the equation by the finite element method, compares the result with the analytical solution and writes the data to a file.  

## Compile & running

```bash
./compile.sh && cd build && ./app.out
```

## Output

```bash
Linear solution:
---- Max error: 1.2%
Cube solution:
---- Max error: 1.2%
```
