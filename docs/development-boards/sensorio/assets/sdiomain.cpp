#include "sdioblockdevice.h"
#include "FATFileSystem.h"
#include "Serial.h"

mbed::Serial console(SERIAL_TX, SERIAL_RX, 115200);

int main(int argc, char **argv)
{
    console.printf("This is SensorIO\r\n");

    int returnCode = 1;
    const char mountPoint[] = "sd";
    const char fullMountPoint[] = "/sd/";
    const char fileName[] = "/sd/sensorio.txt";

    SDIOBlockDevice blockDevice;
    FATFileSystem fat(mountPoint, &blockDevice);

    do
    {
        console.printf("Listing %s directory:\r\n", fullMountPoint);
        DIR* directory = opendir(mountPoint);

        if(nullptr == directory)
        {
            console.printf("Error: %s (%d) while opening %s\r\n", strerror(errno), -errno, mountPoint);
            break;
        }

        bool fileExists = false;
        while(true)
        {
            struct dirent* dirEntry = readdir(directory);
            if(nullptr == dirEntry)
            {
                break;
            }

            console.printf("    %s\r\n", dirEntry->d_name);

            if(0 == std::strncmp(fileName, dirEntry->d_name, NAME_MAX))
            {
                fileExists = true;
            }
        }
        closedir(directory);

        FILE* file = nullptr;
        if(fileExists)
        {
            file = fopen(fileName, "w");
        }
        else
        {
            file = fopen(fileName, "a");
        }

        if(nullptr == file)
        {
            console.printf("Error: %s (%d) while opening %s\r\n", strerror(errno), -errno, file);
            break;
        }

        fprintf(file, "%s", "SensorIO\r\n");

        if(0 != fclose(file))
        {
            console.printf("Closing file failed!\r\n");
            break;
        }

        // everything ok
        returnCode = 0;
    }
    while(false);

    fat.unmount();
    blockDevice.deinit();

    console.printf("Program: %s\r\n", (returnCode == 0) ? "SUCCESS" : "FAIL");
    return returnCode;
}
