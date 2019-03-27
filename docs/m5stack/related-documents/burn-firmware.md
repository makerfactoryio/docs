# How to Burn Firmware


*This article will guide you how to burn a right firmware to your board via M5Burner.*

## Windows

### 1. Install USB driver

If you have not installed the CP2104 USB driver yet, read [here](../serial-connection). Otherwise, Start directly from step 2.

### 2. Download M5Burner

For downloading M5Burner, visit the [M5Stack Website](http://www.m5stack.com) please.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/download_M5Burner.jpg">

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/download_M5Burner_02.png">

### 3. Burn the firmware

Unzip the M5Burner tool which you donwloaded for official website just now, then double click `M5Burner.exe`.

**Then choice the `serial port` which is connected with your board and the `Baud` which is 921600 following below steps. Choice a right firmware, click `Erase` and then click `Burn`.**

- If you want to program with [UIFlow](http://flow.m5stack.com)(/[M5Cloud](http://cloud.m5stack.com)), select `M5Flow-vx.x`(/`M5Cloud-vx.x.x`) option(the lastest version).

- If you own a ESP32CAM (/ M5CAMERA), select `M5Cam-vx.x (/M5Cam-psram)` option


<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_flow_firmware.gif">

!> **Notice** If it does not display any ``COMx`` port or only ``COM1`` exists at the option, you need to visit this article [establish serial connection](../serial-connection) and reinstall the USB driver.

**a. Choice a right firmware**

a. select `M5Flow-vx.x` option(the lastest version), if you want to program with [UIFlow](http://flow.m5stack.com)

b. select `M5Cam-vx.x (/M5Cam-psram)` option, if you own a ESP32CAM (/ M5CAMERA)

**b. Click `Erase`**


<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_01.png">

*If M5Burner shows the information `Hard resetting via RTS pin...` below, it means chip has been erased successfully.*


<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_04.png">

*If M5Burner shows the information `Leaving... Staying in bootloader.` below, it means chip has been burnt successfully.*


<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_05.png">

### 3. Then reset your board

!!! info
    If M5Burner means be busy after clicking `Burn`, please wait for a few minutes. It'll be normal after the firmware has been burnt successfully.

!!! info
    If the burning procedure has been interrupted(like `M5Burner has been closed suddenly...`), it's better to burn your board again.

## MacOS

### 1. Install USB Driver (If you have not install USB driver, follow this step. Otherwise, jump to step 2 directly.)

The first thing to do is to visit the official website https://m5stack.com, then select `Explore` -> `Download` from the top menu, download the `M5Burner` and the `CP21X Driver`.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_01.jpg">

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_02.jpg">

Once the driver download is complete. Open the driver file as shown below.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_03.jpg">

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_04.jpg">

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_05.jpg">

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_06.jpg">

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_07.jpg">

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_08.jpg">

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_09.jpg">

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_10.jpg">

Now, the USB driver has been installed successfully. You must now allow the operating system to run third-party applications. Open the `search`, then find the `Terminal` application.app and start it by pressing `Enter`.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_11.jpg">

Now write the line below and press `Enter`.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_12.jpg">

Now, click on the Apple in the upper left corner, then open `System Preferences...`, then open `Security & Privacy`.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_13.jpg">

Make sure you have the radio check box set to Anywhere (if not, check it).

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_14.jpg">

### 2. Open M5Burner

Now go back to the browser to `Downloads` button and open the file with the `Ctrl` key pressed.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_15.jpg">

### 3. Burn the firmware

So, now connect your device to your Mac with a USB cable. Select the corresponding SOFTWARE version (Normally, select the lastest version) and click on the `Flash` button. At the end of the process, the indicator will be completely painted.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_mac_16.jpg">

Once the device is flashed - disconnect the cable from the Mac and press the red button (the same power button) on the M5.

## Linux

### 1. Install pip and esptool

Open the terminal, enter the following command according to your system version for installing Python package management tool `pip`.

* Centos7:

```shell
sudo yum install python-pip
```

* Ubuntu and Debian:

```shell
sudo apt-get install python-pip
```

* Arch:

```shell
sudo pacman -S --needed python-pip
```

After installing `pip` successfully, enter `sudo pip install esptool` for installing `esptool`.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_11.png">

### 2. Download the last version of M5Burner

Access [UIFlow](http://www.m5stack.com), download the MacOS version installer `M5Burner-Flow-For-MacOS`, and unzip it.

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_10.png">

### 3. Execute

Creat a new folder `M5burner`, and copy `M5Burner_MacOS/M5Burner_MacOS.app/Contents/Resources/firmware/M5Flow/` to `~/M5burner`

If you want to bun v1.1.1 version firmware, switch the current directory to the corresponding directory e.g. `cd ~/M5burner/M5Flow/v1.1.1-en`

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_13.png">

Plug the M5Core in, and enter `sudo chmod +x *.sh` for granting `root` authority, and run `sudo ./flash.sh`

<img src="/images/m5stack/getting_started_pics/how_to_burn_firmware/burn_firmware_12.jpg">

## Video Tutorial

**Windows**

<video width="500" height="315" controls>
    <source src="https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/%E6%95%99%E7%A8%8B/Firmware%20Upgrade/A1%20-%20Firmware%20Upgrade.mp4" type="video/mp4">
</video>
