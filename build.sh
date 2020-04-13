#!/bin/bash -e

module load gcc/7.4.0/1 spectrum-mpi
mpicxx helloMPI.c -o helloMPI
