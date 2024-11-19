#include <string.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void LOG(const char* source, const char* message)
{
    time_t rawTime;
    time(&rawTime);

    // Add offset for UTC+6 (6 * 3600 seconds)
    rawTime += 6 * 3600;

    // Convert to a broken-down time (UTC+6 offset)
    struct tm *timeInfo = gmtime(&rawTime);

    // Get hundredths of a second
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int hundredths = (tv.tv_usec / 10000);  // 1 hundredth = 10,000 microseconds

    // Format and print the time
    char formattedTime[16];
    strftime(formattedTime, sizeof(formattedTime), "%H:%M:%S", timeInfo);

    printf("[%s:%02d][%s]: %s\n", formattedTime, hundredths, source, message);

    // Open the log file in append mode
    FILE *logFile = fopen("log.txt", "a");
    if (logFile == NULL) {
        perror("Unable to open log file");
        return;
    }

    // Write the log message to the file
    fprintf(logFile, "[%s:%02d][%s]: %s\n", formattedTime, hundredths, source, message);

    // Close the file
    fclose(logFile);
}
