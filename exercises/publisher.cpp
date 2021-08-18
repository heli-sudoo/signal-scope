#include <lcm/lcm-cpp.hpp>
#include "lcm-types/cpp/test_signal_lcmt.hpp"
#include "lcm-types/cpp/test_signal_sequence_lcmt.hpp"
#include <cstring>
#include <unistd.h>
#include <math.h>
#include <cstdlib>

#define pi 3.1415926

int publish_signal();
int publish_signalSeq();
int main(int argn, char *argv[])
{
    if (argn <= 1)
        return publish_signal();

    std::string argin = std::string(argv[1]);
    if (argin == "seq")
        return publish_signalSeq();
    else
        return publish_signal();
}

int publish_signal()
{
    printf("execute publish_signal \n");
    lcm::LCM lcm;
    if (!lcm.good())
        return 1;

    test_signal_lcmt signal;

    signal.pos = 1;
    signal.rpy = 0;
    int k = 0; // count in microsecond
    while (true)
    {
        signal.timestep= 1000 * k;
        lcm.publish("MPCPlan", &signal);
        usleep(100); // publish every 100 microsecond
        k++;
    }
}

int publish_signalSeq()
{
    printf("execute publish_signalSeq() \n");
    lcm::LCM lcm;
    if (!lcm.good())
        return 1;

    test_signal_sequence_lcmt signalSeq;
    for (int i = 0; i < sizeof(signalSeq.timestep)/sizeof(float); i++)
    {
        signalSeq.timestep[i] = 0.01 *i*1e06; // unit microsecond
    }
    float f = 1; // frequency
    while (true)
    {
        for (int i = 0; i < sizeof(signalSeq.timestep)/sizeof(float); i++)
        {
            float t = signalSeq.timestep[i]*1e-06;
            signalSeq.pos[i] = sin(2*pi*f*t);
        }        
        lcm.publish("MPCPlan", &signalSeq);
        sleep(1); // publish every 10 s
        f++; // increase frequency by 1
    }
}
