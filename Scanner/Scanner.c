#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>

int numCores = 1;
void scanIP(void *arg); 
void scanIPThread();
int main() {
    scanIP(0);  //single threaded version
    //scanIPThread();  //uncomment for multi threaded version
    printf("Completed");
    Sleep(9999);
    return 0;
}

void scanIP(void *arg){
    int startIP = (int)arg;
    int endIP = startIP + (256 / numCores) - 1;
    for (int ipAddress = startIP; ipAddress <= endIP; ipAddress++) {
        char command[50];
        char line[50];
        FILE *fp;

        sprintf(command, "ping 192.168.0.%d -n 1", ipAddress);
        fp = popen(command, "r");

        if (fp == NULL) {
        perror("popen");
        continue;
        }

        while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, "time") != NULL) {
            char *ip = strtok(line, " ");
            ip = strtok(NULL, " ");
            ip = strtok(NULL, " ");
            char *colon = strchr(ip, ':');

            if (colon) *colon = '\0';

            printf("IP Address: %s is reachable\n", ip);
            break;
        }
        }

        pclose(fp);
    }
}
void scanIPThread(){
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    numCores = systemInfo.dwNumberOfProcessors;
    pthread_t threads[numCores];

    for (int i = 0; i < numCores; i++) {
    int startIP = i * (256 / numCores);
    pthread_create(&threads[i], NULL, (void *)scanIP, (void *)startIP);
    }

    for (int i = 0; i < numCores; i++) {
    pthread_join(threads[i], NULL);
    }
}