# Halloween2022

Arduino code for Halloween2022 electronics.

## Development

For more info take a look at the [arduino-cli docs](https://arduino.github.io/arduino-cli/0.21/getting-started/).

### Update board and libraries index

```shell
arduino-cli core update-index
```

### View arduino connected boards

```shell
arduino-cli board list
```

### Install board core

```shell
arduino-cli core install arduino:avr
```

To list all boards:

```shell
arduino-cli board listall
```

### Compile sketch

```shell
arduino-cli compile --fqbn arduino:avr:mega sam
```

### Upload sketch

```shell
arduino-cli upload -p /dev/cu.usbmodem1201 --fqbn arduino:avr:mega sam
```
