#!/usr/bin/env bash

TARGET=$1

g++ $TARGET -Istatic/include -Lstatic/bin -lhjdj
