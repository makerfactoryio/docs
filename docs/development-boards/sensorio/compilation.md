# Mbed OS based firmware compilation

Once [Mbed OS project is set up](./code-setup.md) firmware can be compiled with simple command from terminal:

```bash
mbed compile --profile debug.json
```

and the resulting binaries can be found in `./BUILD/SENSORIO/GCC_ARM-DEBUG/` directory.

For optimized/release binary build command uses a different profile:

```bash
mbed compile --profile release.json
```

and the resulting binaries can be found in `./BUILD/SENSORIO/GCC_ARM/` directory.
