#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <thread>
#include <string.h>

using namespace std;

#define FIFO1 "/home/ams/fifo1"
#define FIFO2 "/home/ams/fifo2"


void CreateFIFO(const char* path, mode_t mode)
{
    int ret = mkfifo(path, mode);
    string result = ret == -1 ? "failed" : "success";
    printf("Create FIFO channel %s for %s\n", result.c_str(), path);
}
int OpenFIFO(const char* path, int flag)
{
    int fd = open(path, flag);
    string result = fd == -1 ? "failed" : "success";
    printf("Open FIFO channel %s for %s, fd:%d\n", result.c_str(), path, fd);
    return fd;
}

int main()
{
    CreateFIFO(FIFO1, 0777);
    CreateFIFO(FIFO2, 0777);
    
    int fdRead = OpenFIFO(FIFO1, O_RDWR);
    int fdWrite = OpenFIFO(FIFO2, O_RDWR);

    if (fdRead == -1 || fdWrite == -1)
    {
        return -1;
    }
    
    char r_msg[128];
    for (auto i = 0; i < 10; i++)
    {
        string message = "hello world!" + to_string(i);
        int ret1 = write(fdWrite, message.c_str(), message.length());
        string result1 = ret1 == -1 ? "failed" : "success";
        printf("Write data %s. Index:%d\n", result1.c_str(), i);


        memset(r_msg, 0, sizeof(r_msg));
        int ret2 = read(fdRead, r_msg, 128);
        string result2 = ret2 == -1 ? "failed" : "success";
        printf("Index %d Read data %s, Data:[%s]\n", i, result2.c_str(), r_msg);
    }
   
    close(fdRead);
    close(fdWrite);

    return 0;
}