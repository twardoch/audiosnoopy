#!/usr/bin/env python3

# audiosnoopy/__init__.py

import json
from pathlib import Path
from typing import Union

import fire

import audiosnoopy


def audiosnoopy(plugin_path: Union[str, Path]) -> dict:
    """Introspects an audio plugin and returns its API info as a dict."""
    if isinstance(plugin_path, Path):
        plugin_path = str(plugin_path.resolve())

    snoopy = audiosnoopy.AudioSnoopy(plugin_path)
    info_json = snoopy.get_plugin_info()
    return json.loads(info_json)


def cli():
    """CLI entry point."""
    fire.Fire(audiosnoopy)
