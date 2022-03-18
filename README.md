# Halloween2022

Arduino code for Halloween2022 electronics.

Designed using Arduino Mega, deployed using Arduino Nano.

## Development

For more info take a look at the [arduino-cli docs](https://arduino.github.io/arduino-cli/0.21/getting-started/).

Environment variables:

- **`PORT`**: usually /dev/xxx. Use `arduino-cli board list` to get the correct port.
- **`BOARD`**: `arduino:avr:mega` for Arduino Mega and `arduino:avr:nano` for Arduino Nano

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
arduino-cli compile --fqbn $BOARD <PROJECT>
```

### Upload sketch

```shell
arduino-cli upload -p $PORT --fqbn $BOARD <PROJECT>
```

### Open serial monitor

```shell
arduino-cli monitor -p $PORT
```
