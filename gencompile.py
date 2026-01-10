#!/usr/bin/env python3
"""
Generates a shell script to compile all my custom keymaps.
"""

import glob

REMAP = {
    'mechlovin/infinity875' : 'mechlovin/infinity875/rev2',
    'drop/ctrl': 'drop/ctrl/v2',
    'xiudi/xd60': 'xiudi/xd60/rev2',
}

print("""#!/bin/sh

die() {
    exit 1
}
""")

files = glob.glob('keyboards/**/seancaulfield*', recursive=True)
for line in sorted(files):
    line = line[10:].rstrip()
    pos = line.find('keymaps')
    keyboard = line[:pos].rstrip('/')
    keyboard = REMAP.get(keyboard, keyboard)
    keymap = line[pos:].split('/')[-1]
    print(f"qmk compile -kb {keyboard} -km {keymap} || die")
