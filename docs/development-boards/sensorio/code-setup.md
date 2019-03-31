# Basic setup for all firmware examples

All firmware examples in this documentation are based on [Mbed OS](https://os.mbed.com).

!!! info "Tools"
    These steps assume that `mbed-cli` and [GNU Arm Embedded Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads) are already installed. For instructions on tooling setup visit [Tooling setup](./tools.md).

## Using template repository

The easiest way to start is to clone [SensorIO template](https://github.com) repository:

```bash
git clone https://github.com/slashdevteam/sensorio-template.git sensorio-example
```

and initialize submodules:

```bash
cd sensorio-example
git submodule update --init --recursive
```

add any necessary drivers, for example for light sensor:

```bash
git clone https://github.com/slashdevteam/ltr303-mbed.git
```

edit `main.cpp`, [compile](./compilation.md) and [flash](./flashing.md).

## Manually

Steps needed to compile Mbed OS based firmware for SensorIO:

1. Create a new directory for your project, for example:

    ```bash
    mkdir sensorio-example
    ```

2. Enter this new directory, for example:

    ```bash
    cd sensorio-example
    ```

3. Get Mbed OS source:

    ```bash
    git clone https://github.com/slashdevteam/mbed-os.git`
    cd mbed-os
    git checkout -t origin/sensorio-dev-target
    cd ..
    ```

    !!! warning "Mbed OS repository"
        SensorIO is currently in the process of Mbed Enabled certification, hence the need to clone a fork of Mbed OS.

4. Get appropriate drivers, for example:

    ```bash
    git clone https://github.com/slashdevteam/ltr303-mbed.git
    ```

5. Download or copy-paste example `main.cpp` into `sensorio-example` directory.

6. Download compilation profile: [release](./assets/release.json) or [debug](./assets/debug.json).

7. Initialize Mbed OS project:

    ```bash
    mbed config root .
    ```

8. Select SensorIO as build target:

    ```bash
    mbed target SENSORIO
    ```

9. Select GNU GCC Toolchain as default:

    ```bash
    mbed toolchain GCC_ARM
    ```

10. Compile firmware example:

    ```bash
    mbed compile --profile debug.json
    ```

11. [Flash binary](./flashing.md) and enjoy!
