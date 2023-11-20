    #include <unistd.h>
    #include <stdio.h>
    #include <sys/time.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    int main()
    {
        struct timeval tv;
        struct timezone tz;
        char buf[15];
        int fd=open("test",O_RDONLY);
        int ret = gettimeofday(&tv,&tz);
        long int t1=tv.tv_usec;
        printf("time is:%ld\n",tv.tv_usec);
        for (size_t i = 0; i < 10000; i++)
        {
            read(STDIN_FILENO,buf,0);
        }
        ret = gettimeofday(&tv,&tz);
        long int t2=tv.tv_usec;
        printf("time is:%ld\n",tv.tv_usec);
        printf("dtime is:%ld\n",t2-t1);
        write(STDOUT_FILENO,buf,0);
        return 0 ;
    }