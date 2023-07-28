#!/bin/bash

outputfile=$(date +"%Y-%m-%d-%H-%M.txt")
alsa-info --no-upload --output ./alsa-output/$outputfile