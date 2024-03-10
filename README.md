# audiosnoopy

audiosnoopy is a lightweight Python library for introspecting audio plugin APIs. It provides a simple way to extract information about audio plugins, such as their name, format, manufacturer, version, and parameters.

## Features

- Supports various audio plugin formats (VST, VST3, AudioUnit, etc.)
- Retrieves plugin metadata and parameter information
- Easy-to-use Python API
- Lightweight and dependency-free

## Installation

You can install audiosnoopy using pip:

```bash
pip install audiosnoopy
```

## Usage

To use audiosnoopy, simply import the library and call the `audiosnoopy` function with the path to the audio plugin:

```python
from audiosnoopy import audiosnoopy

plugin_info = audiosnoopy("path/to/plugin.vst")
print(plugin_info)
```

The `audiosnoopy` function returns a dictionary containing the plugin information:

```json
{
  "name": "Plugin Name",
  "format": "VST",
  "manufacturer": "Plugin Manufacturer",
  "version": "1.0.0",
  "parameters": [
    {
      "name": "Parameter 1",
      "default": 0.5
    },
    {
      "name": "Parameter 2",
      "default": 0.0
    }
  ]
}
```

## CLI Usage

audiosnoopy also provides a command-line interface (CLI) for easy usage from the terminal:

```bash
audiosnoopy path/to/plugin.vst
```

The CLI will output the plugin information in JSON format.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the [GitHub repository](https://github.com/your-username/audiosnoopy).

## License

This project is licensed under the [GNU General Public License v3.0](LICENSE).
