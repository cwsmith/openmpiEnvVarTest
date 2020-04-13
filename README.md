# openmpiEnvVarTest

Demonstration of environment variables not being passed from the job script to
processes launched by Spectrum mpirun.

This behavior becomes an issue for large applications that read multiple
environment variables, depend on `LD_LIBRARY_PATH` for finding libraries
at runtime, use OpenMP environment settings, etc. .

## contents

build.sh - build script
helloMPI.c - hello world source code
LICENSE - legal stuff
README.md - this file
runAimos.sh - slurm run script calling mpirun
submitAimos.sh - slurm submission command... in a script

## build and run

On AiMOS:

```
./build.sh
# run the hello world program on two nodes, four processes per node
# the second argument is the path to the script passed to sbatch
./submitAimos.sh 2 ./runAimos.sh
```

You should see the following output (in some order) in the `slurm-####.out`
file:

```
ranks 8
rank 0 cake 42
rank 2 cake 42
rank 4 cake (null)
rank 6 cake (null)
rank 5 cake (null)
rank 7 cake (null)
rank 1 cake 42
done
rank 3 cake 42
```

Note, that processes on the first node see the variable but on the second node
it is unset.

## some mitigations

- Use the openmpi deprecated `-x cake=42` arg
- Instead of passing the executable (`helloMPI`) directly to mpirun, instead
  pass the following to launch a shell, set the var, then run the executable
  `/bin/bash -c "export cake=42; ./helloMPI"`
