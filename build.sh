#!/bin/bash

customConfigPath='/home/ionut/ntz_custom_dactyl'

qmk json2c "$customConfigPath/ntz.json" > "$customConfigPath/keymaps/default/generated_layout.c"

qmk compile -kb ntz_custom_dactyl -km default

# qmk flash -kb ntz_custom_dactyl -km default
