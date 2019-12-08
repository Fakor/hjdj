#!/usr/bin/env bash

HJDJ_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
VIRTUAL_ENV_HOME=$HJDJ_PATH/venv

source $VIRTUAL_ENV_HOME/bin/activate

export TEST_FOLDER=$HJDJ_PATH/tests
export PYTHONPATH=$HJDJ_PATH

cd $TEST_FOLDER

if [ $# -eq 0 ]; then
    python -m unittest test_suite.py
else
   python -m unittest $@
fi



