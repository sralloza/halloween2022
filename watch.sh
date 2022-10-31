#!/usr/bin/env bash
set -eo pipefail

export PORT=$(arduino-cli board list | grep USB | awk '{print $1}')
if [ -z "$PORT" ]; then
  echo "No board found"
  exit 1
fi

echo "+Listening to serial port $PORT"
arduino-cli monitor -p $PORT
