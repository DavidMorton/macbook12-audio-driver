#!/bin/bash

folder=./alsa-output/$(date +"%Y-%m-%d")
mkdir -p $folder

sudo chown david:david $folder

outputfile=$(date +"%H-%M.txt")
alsa-info --no-upload --output $folder/$outputfile