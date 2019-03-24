# M5Core BASIC

<div markdown="span" class="float-container text-center">
  <div markdown="span" class="pull-left" style="width: 50%">
    <img src="assets/img/product_pics/core/basic/basic_02.png" alt="basic_02" width="350" height="350">
  </div>
  <div markdown="span" class="pull-left" style="width: 50%">
    <img src="assets/img/product_pics/core/basic/basic_03.png" alt="basic_03" width="350" height="350">
  </div>
</div>

<div markdown="span" class="text-center">
  [Quick Start](../quickstart/overview) &mdash;
  [Example](https://github.com/m5stack/M5Stack/tree/master/examples/Basics) &mdash;
  [Schematic](https://github.com/m5stack/M5-Schematic/blob/master/Core/Basic/M5-Core-Schematic(20171206).pdf)
</div>

## Description

**The M5Stack BASIC** is a black development kit based on **ESP32** chip composed of a black M5Core and a Bottom Base board. You can even program The M5Stack BASIC through Blockly, Arduino or MicroPython. The black core is a basic kit and **it does not own any MEMS chip(like MPU9250...)**.

This is a [Bottom board](en/base/core_bottom) on the back of M5Core. It's designed for expanding gpio on M-Bus besides I2S Pins(GPIO0, GPIO12, GPIO13, GPIO15, GPIO34)for DIY. Each gpio on M-Bus is expanded as pin and port for convenience and flexibility.

<img src="assets/img/product_pics/core/basic/basic_07.png" width="350" height="350"><img src="assets/img/product_pics/core/basic/basic_08.png" width="350" height="350">

## Feature

-  Programming Support: [UIFlow](http://flow.m5stack.com), [MicroPython](http://micropython.org/) and [Arduino](http://www.arduino.cc)
-  TF Card Support(Up to 16GB)

## Source PinMap

**LCD & TF Card**

*LCD Resolution: 320x240*

<table>
 <tr><td>ESP32 Chip</td><td>GPIO23</td><td>GPIO19</td><td>GPIO18</td><td>GPIO14</td><td>GPIO27</td><td>GPIO33</td><td>GPIO32</td><td>GPIO4</td></tr>
 <tr><td>ILI9341</td><td>/</td><td>MISO</td><td>CLK</td><td>CS</td><td>DC</td><td>RST</td><td>BL</td><td> </td></tr>
 <tr><td>TF Card</td><td>MOSI</td><td>MISO</td><td>CLK</td><td> </td><td> </td><td> </td><td> </td><td>CS</td></tr>

</table>

**Button & Speaker**

<table>
 <tr><td>ESP32 Chip</td><td>GPIO39</td><td>GPIO38</td><td>GPIO37</td><td>GPIO25</td></tr>
 <tr><td>Button Pin</td><td>BUTTON A</td><td>BUTTON B</td><td>BUTTON C</td></tr>
 <tr><td>Speaker</td><td> </td><td> </td><td> </td><td>Speaker Pin</td></tr>
</table>

**GROVE 接口 A & IP5306**

*Power Management IC (IP5306) is a custom I2C version, and the IIC address of IP5306 is 0x75. Click [here](https://github.com/m5stack/M5-Schematic/blob/master/Core/IIC_IP5306_REG_V1.4.pdf) for view register manual.*

<table>
 <tr><td>ESP32 Chip</td><td>GPIO22</td><td>GPIO21</td></tr>
 <tr><td>GROVE A</td><td>SCL</td><td>SDA</td></tr>
 <tr><td>IP5306</td><td>SCL</td><td>SDA</td><td>5V</td><td>GND</td></tr>
</table>

## Parameter

<table>
   <tr style="font-weight:bold">
      <td>Source</td>
      <td>Parameter</td>
   </tr>
   <tr>
      <td>ESP32</td>
      <td>240MHz dual core, 600 DMIPS, 520KB SRAM, Wi-Fi, dual mode Bluetooth</td>
   </tr>
   <tr>
      <td>Flash</td>
      <td>16MB (old model: 4MB)</td>
   </tr>
   <tr>
      <td>Input</td>
      <td>5V @ 500mA</td>
   </tr>
   <tr>
      <td>Interface</td>
      <td>TypeC x 1, GROVE(I2C+I/0+UART) x 1</td>
   </tr>
   <tr>
      <td>LCD</td>
      <td>2 inch, 320x240 Colorful TFT LCD, ILI9342</td>
   </tr>
   <tr>
      <td>Speaker</td>
      <td>1W-0928</td>
   </tr>
   <tr>
      <td>Battery</td>
      <td>150mAh @ 3.7V</td>
   </tr>
   <tr>
      <td>Op.Temp.</td>
      <td>32°F to 104°F ( 0°C to 40°C )</td>
   </tr>
   <tr>
      <td>Size</td>
      <td>54 x 54 x 12.5 mm</td>
   </tr>
   <tr>
      <td>C.A.S.E</td>
      <td>Plastic ( PC )</td>
   </tr>
   <tr>
      <td>Weight</td>
      <td>120g with bottom, 100g only core</td>
   </tr>
</table>

**NOTE:**

*We have several kinds of Cores, the following figures show the main differece with them.*

- *If you want to **view** the detailed defference with them, please click [here](https://github.com/m5stack/M5-Schematic/blob/master/Core/hardware_difference_between_cores.md).*

- *If you want to **download** the detailed defference with them, please click [here](https://github.com/m5stack/M5-Schematic/blob/master/Core/M5%20Core%20Detailed%20Comparison.xlsx).*

<img src="https://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_table/core_comparison/core_main_comparison_04_en.png">

<img src="https://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_table/core_comparison/core_main_comparison_05_en.png">

## Include

-  1x M5Stack BASIC
-  1x M5Stack BASIC Bottom
-  10x Proto Wire
-  Type-C USB Cable
-  User Manual

<img src="assets/img/product_pics/core/basic/basic_04.png" alt="basic_04" width="80%" height="80%">

<!-- <img src="assets/img/product_pics/core/basic/basic_04.png" alt="basic_04" width="80%" height="80%">

<img src="assets/img/product_pics/core/basic/basic_06.png" width="250" height="250"> <img src="assets/img/product_pics/core/basic/basic_07.png" width="250" height="250">

<img src="assets/img/product_pics/core/basic/basic_08.png" width="250" height="250"> <img src="assets/img/product_pics/core/basic/basic_09.png" width="250" height="250"> -->

<img src="assets/img/product_pics/core/basic/basic_10.png" width="50%" height="50%">

## Related Link

-  **Datasheet** - [ESP32](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_cn.pdf)

## Related Video

**M5Stack Instroduce**

<video width="500" controls>
    <source src="https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/LukeVideo/m5stack%E7%AE%80%E4%BB%8B%EF%BC%88%E4%B8%AD%E6%96%87%EF%BC%89.mp4" type="video/mp4">
</video>

**M5Core Cases**

[![core_bottom_01.png](http://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/core_compass.png)](https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/Blog/Twitch201811/M5Stack%20Compass.mp4)[![core_bottom_01.png](http://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/core_imu.png)](https://v.youku.com/v_show/id_XNDAxNDMwMjAyNA==.html?spm=a2hzp.8253869.0.0)[![core_bottom_01.png](http://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/core_avatar.png)](https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/Blog/Twitch201811/M5Stack%20Avatar%20Custom%20Face.mp4)

[![core_bottom_01.png](http://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/core_voice_recognition.png)](https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/Blog/Twitch201812/M5Stack%20Voice-Recognize.mp4)[![core_bottom_01.png](http://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/core_smart_electric_monitor.png)](https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/Blog/Twitch201811/M5stack%20Smart%20Electric%20Monitor.mp4)[![core_bottom_01.png](http://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/core_smart_home.png)](https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/Blog/Twitch201812/Smart%20Home.mp4)

[![core_bottom_01.png](http://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/core_leap_motion.png)](https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/Blog/Twitch201811/M5Stack%20Motion%20Detector.mp4)[![core_bottom_01.png](http://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/core_microphone_alexa.png)](https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/Blog/Twitch201812/M5stack%20Microphone%20.mp4)[![core_bottom_01.png](http://m5stack.oss-cn-shenzhen.aliyuncs.com/image/m5-docs_content/core/core_robot.png)](https://m5stack.oss-cn-shenzhen.aliyuncs.com/video/Blog/Twitch201811/M5Stack%20Robot.mp4)
