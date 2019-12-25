#!/usr/bin/env bash

ANALYSIS_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
VIRTUAL_ENV_HOME=$ANALYSIS_PATH/../venv

source $VIRTUAL_ENV_HOME/bin/activate

export TEST_FOLDER=$ANALYSIS_PATH/tests
export PYTHONPATH=$ANALYSIS_PATH

cd $ANALYSIS_PATH

if [ $# -eq 0 ]; then
    python -m unittest tests/test_suite.py
else
   python -m unittest $@
fi
