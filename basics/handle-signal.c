#include <signal.h>
#include <unistd.h>
#include <errno.h>

volatile static sig_atomic_t n = 0;
const char message[] = "Arghh, press it again\n";

void handler(int s)
{
    int save_errno = errno;
    signal(SIGINT, handler);
    n++;
    write(1, message, sizeof(message)-1);
    errno = save_errno;
}

int main()
{
    signal(SIGINT, handler);
    while(n<5)
        sleep(1);
    return 0;
}
