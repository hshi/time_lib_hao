#ifdef MPI_HAO
#include<mpi.h>
#endif

#include "time_hao.h"

void time_hao_test();

int main(int argc, char** argv)
{
 int rank=0;

#ifdef MPI_HAO
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

 if(rank==0)
 {
  time_hao_test();
 }

#ifdef MPI_HAO
 MPI_Finalize();
#endif

 return 0;
}
