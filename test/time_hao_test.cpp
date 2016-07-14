#include <iostream>
#include <cmath>
#include "time_hao.h"

#ifdef MPI_HAO
#include <mpi.h>
#endif

using namespace std;

void time_class_test()
{
    size_t flag=0;
   
    Timer_hao timer;
    if(abs(timer.seconds-0)>1e-12) flag++;
    if(timer.timing_flag!=0) flag++;
   
    Timer_hao timer_sec(3.0);
    if(abs(timer_sec.seconds-3.0)>1e-12 ) flag++;
    if(timer_sec.timing_flag!=0) flag++;
   
    Timer_hao timer_secp(timer_sec);
    if(abs(timer_secp.seconds-3.0)>1e-12 ) flag++;
    if(timer_secp.timing_flag!=0) flag++;
   
    timer_secp=timer;
    if(abs(timer_secp.seconds-0.0)>1e-12 ) flag++;
    if(timer_secp.timing_flag!=0) flag++;
   
    if(flag==0) cout<<"PASSED! Time class passed the test!"<<endl;
    else cout<<"Warning!!!!Time class failed the test!"<<endl; 
}


void time_init_end_test()
{
    Timer_hao timer;
    timer.init();
    cout<<"Timing..."<<endl;;
   
    clock_t start_time = clock();
    clock_t sec=2;
    clock_t end_time = sec * CLOCKS_PER_SEC + start_time;
    while(clock() != end_time);
   
    timer.end();
    //timer.print_init();
    //timer.print_end();
    //timer.print_accumulation();
    
    if(lround(timer.seconds)==sec) cout<<"PASSED! Time init and Time end passed the test!"<<endl;
    else cout<<"Warning!!!!Time init and Time end failed the test!"<<endl;
}


void second_to_tm_test()
{
    double seconds=446582.0;
    struct tm timeinfo=second_to_tm(seconds);
    size_t flag=0;
    if(timeinfo.tm_mday!=5) flag++;
    if(timeinfo.tm_hour!=4) flag++;
    if(timeinfo.tm_min!=3)  flag++;
    if(timeinfo.tm_sec!=2)  flag++;
    if(flag==0) cout<<"PASSED! Second_to_tm passed the test!"<<endl;
    else cout<<"Warning!!!!Second_to_tm failed the test!"<<endl;
}

void time_hao_test()
{
    int rank=0;
#ifdef MPI_HAO
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    if(rank==0)
    {
        time_class_test();
        time_init_end_test();
        second_to_tm_test();
    }

    if(rank==0) cout<<" "<<endl;
}
