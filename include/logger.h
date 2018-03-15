#ifndef _LOGGER_H
#define _LOGGER_H

#define DEBUG 1
#define ERROR 1
#define INFO  0
#define DEBUGWAIT 500


#define DEBUGLOG(format, ...) if(INFO){ fprintf(stdout, "[%s %s <debug>  %s:%s(): %d ] ", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__);fprintf(stdout, format, ##__VA_ARGS__);}

#define ERRORLOG(format, ...) if(INFO){ fprintf(stderr, "[%s %s <error>  %s:%s(): %d ] ", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__);fprintf(stderr, format, ##__VA_ARGS__);}

#define INFOLOG(format, ...) if(INFO){ fprintf(stdout, "[%s %s  <info>  %s:%s(): %d ] ", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__);fprintf(stdout, format, ##__VA_ARGS__);}




#endif
