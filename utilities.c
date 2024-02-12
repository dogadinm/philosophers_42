#include "philosophers.h"

unsigned int get_time()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void    new_sleep(unsigned long duration, t_env *env)
{
    unsigned long start;
    start = get_time();
    while (!env->stop_condition)
    {
        if(get_time() - start >= duration)
            break;
        usleep(env->count * 2);
    }
}

int ft_error(char *mess)
{
    ft_putstr_fd(mess, 2);
    return(0);
}