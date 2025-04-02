# xecho - Enhanced Echo Command

`xecho` is an improved version of the standard `echo` command, adding support for text styling, colors, and custom formatting.

## Features

- **Text Formatting**: Bold, italic, underline, and strikethrough.
- **Color Output**: Print text in red, green, yellow, or blue.
- **Custom Separators**: Use `-sep` to change the separator between words.
- **Environment Variable Expansion**: Works like `echo $VAR`.
- **Pipe Support**: Accepts input from other commands.

## Installation

```sh
git clone https://github.com/Darky-Github/xecho.git
cd xecho
make
sudo make install
```

## Usage

### Basic Output
```sh
xecho "Hello, world!"
```

### Colored Output
```sh
xecho -c red "Error: Something went wrong!"
```

### Bold and Underlined Text
```sh
xecho -b -u "Important message!"
```

### Custom Separator
```sh
xecho -sep , "apple" "banana" "cherry"
```

### Help Menu
```sh
xecho -h
```

## Uninstallation
```sh
sudo make uninstall
```

## License
MIT License
