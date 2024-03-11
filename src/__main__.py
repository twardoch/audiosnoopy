#!/usr/bin/env python3

import fire
from audiosnoopy import snoop


def cli():
    fire.Fire(snoop)


if __name__ == "__main__":
    cli()
