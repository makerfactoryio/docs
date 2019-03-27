# FACES Kit

**FACES Kit** is a kit composed of M5Core GRAY, functional keyboards, FACES Base, FACES Charger and some accessories(including DuPont lines, lanyard, M3 fixing screws and so on).

Currently, the functional keyboards are composed of GameBoy, Calculator and QWERTY (*For each functional keyboard, it's integrated **MEGA328** chip, so that when you press a button, a corresponding value(**hexadecimal format**) will be sent from keyboard to M5Core. They(keyboard and m5core) are communicating using I2C. And the I2C address of each keyboard is 0x08.*). We'll add other keyboards to FACES Kit.

You can program it through Arduino IDE or MicroPython. For different applications, you can stack corresponding keyboard on FACES Base and burn corresponding firmware into M5Core. And here, you can learn more about [FACES Base](../../base/faces).

**NOTE:** *If you want to burn the factory firmware yourself, you need to download the M5Burner on our [official website](https://m5stack.com/download). Then connect FACES to PC through Type-C USB cable, burn FACES Kit firmware.*

<img src="/images/m5stack/product_pics/core/faces_kit/download_faces_firmware_01.png">

<img src="/images/m5stack/product_pics/core/faces_kit/download_faces_firmware_02.png">

Now, here's the picture of the whole kit.

<figure>
    <img src="/images/m5stack/product_pics/core/faces_kit/faces_kit.jpg">
</figure>

### 1. GameBoy Keyboard

When create a handheld game, you can stack a GameBoy keyboard over FACES Base straight. And burn a Nintendo Entertainment System emulator.

Here is the method of burning emulator and a game: [download game](../quickstart/faces-nes)

<figure>
    <img src="/images/m5stack/product_pics/core/faces_kit/gameboy_01.jpg">
</figure>

### 2. Calculator Keyboard

When create a calculator, you need the Calculator Keyboard. Burn your firmware into M5Core. The button which was pressed will execute the callback specifical function, so the calculator is created.

<figure>
    <img src="/images/m5stack/product_pics/core/faces_kit/calculator.jpg">
</figure>

### 3. QWERTY Keyboard

When your project needs full keyboard input, just to stack QWERTY over Base.

Burn the following example(example function: M5Core and serial terminal will print button you pressed)

-  **source file of example** - a. [Arduino](https://github.com/m5stack/M5Stack/tree/master/examples/Modules/FACES) - b. [MicroPython](https://github.com/m5stack/M5Cloud/tree/master/examples/FACES)(for M5Cloud)

-  **M5Cloud usage** - [MicroPython(M5Cloud)](../../core/quickstart/m5cloud)

<figure>
    <img src="/images/m5stack/product_pics/core/faces_kit/qwerty.jpg">
</figure>


### 4. FACES Charger

**FACES Charger** built in some magnets. When charging, the FACES can be attached with charger. They are connected by PIGO Pin.

<figure>
    <img src="/images/m5stack/product_pics/core/faces_kit/charger.jpg">
</figure>

### Related Link

- **[Example](https://github.com/m5stack/M5Stack/tree/master/examples/Modules/FACES)**

- **[MEGA328P Firmware](https://github.com/m5stack/FACES-Firmware)**

### NOTE

*The [Gray version](../..//core/gray) core is configured in the FACES Kit, and our Core has several versions. Similarly, other versions of Core can be stacked on the base of the FACES. The following picture is a comparison of their main differences, which is convenient for you to use.*

- *If you want to **view** the detailed defference with them, please click [here](https://github.com/m5stack/M5-Schematic/blob/master/Core/hardware_difference_between_cores.md).*

- *If you want to **download** the detailed defference with them, please click [here](https://github.com/m5stack/M5-Schematic/blob/master/Core/M5%20Core%20Detailed%20Comparison.xlsx).*
