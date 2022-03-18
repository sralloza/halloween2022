: ${PORT:?must set \$PORT}

set -eo pipefail

CIRCUIT=${1:?the first arg must be an arduino project}

arduino-cli compile --fqbn arduino:avr:nano $1
arduino-cli upload -p $PORT --fqbn arduino:avr:nano $1
arduino-cli monitor -p $PORT
