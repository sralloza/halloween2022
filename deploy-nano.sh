#!/usr/bin/env bash
set -eo pipefail

CIRCUIT=${1:?the first arg must be an arduino project}

export PORT=$(arduino-cli board list | grep USB | awk '{print $1}')
if [ -z "$PORT" ]; then
  echo "No board found"
  exit 1
fi

arduino-cli compile --fqbn arduino:avr:nano $1
arduino-cli upload -p $PORT --fqbn arduino:avr:nano $1
arduino-cli monitor -p $PORT
