#!/usr/bin/env bash
set -eo pipefail

CIRCUIT=${1:?the first arg must be an arduino project}

export PORT=$(arduino-cli board list | grep USB | awk '{print $1}')
if [ -z "$PORT" ]; then
  echo "No board found"
  exit 1
fi

echo "+Compiling $CIRCUIT"
arduino-cli compile --fqbn arduino:avr:nano $1
echo "+Uploading $CIRCUIT"
arduino-cli upload -p $PORT --fqbn arduino:avr:nano $1
echo "+Done, listening to serial port"
arduino-cli monitor -p $PORT
