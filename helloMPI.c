#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc, char**argv) {
  MPI_Init(&argc, &argv);
  int rank = 0;
  int worldsz = 0;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &worldsz);
  if(!rank) printf("ranks %d\n", worldsz);
  const char* cake = getenv("cake");
  printf("rank %d cake %s\n", rank, cake);
  // run a non-trivial mpi function as a sanity check {
  int* in = (int*) malloc(100*sizeof(int));
  int* out = (int*) malloc(100*sizeof(int));
  MPI_Allreduce(in,out,100,MPI_INT,MPI_MAX,MPI_COMM_WORLD);
  // }
  if(!rank) printf("done\n");
  free(in);
  free(out);
  MPI_Finalize();
}
